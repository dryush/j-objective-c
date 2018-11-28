#include "NodeVisiter.h"
#include <unordered_map>
#include <string>


/// TODO::: Прописать деструкторы

class EnumInfo {
public: 
    string name;
    unordered_map<string, EnumElem> elems ;
};

class TypeInfo {
public:
    VarType type;
    VarType arrayType;
    string name;
	TypeInfo() {
	}
    TypeInfo( VarType vt, string n){
        this->type =vt;
        this->name = n;
    }
    TypeInfo( TypeNode* node){
        this->type = node->varType;
        if( node->varType == TYPE_CUSTOM){
            this->name = node->name;
        } else if ( node->varType == TYPE_ARRAY){
            this->arrayType = node->childType->varType;
            this->name = node->childType->name;
        } else if ( node->varType == TYPE_POINTER){
            this->name = node->childType->name;
        }
    }
};

class FunctionParamInfo {
public:
    TypeInfo type;
    string name;
	FunctionParamInfo() {

	}
    FunctionParamInfo( FunctionParamNode* pn){
        this->name = pn->name;
        this->type = TypeInfo(pn->type);
    }
};

class MethodParamInfo : public FunctionParamInfo {
public: 
    string outerName;
    MethodParamInfo( ClassMethodParamNode* pn){
        this->name = pn->innerName;
        this->outerName = pn->outerName;
        this->type = TypeInfo(pn->type);
    }
};

class FunctionInfo {
public:
    string name;
    TypeInfo returnType;
    unordered_map<string, FunctionParamInfo*> params;
};

class FieldInfo {
public:
    string name;
    TypeInfo type;
    FieldAccess access;
    FieldInfo( ClassFieldDeclarationNode * node){
        this->name = node->name;
        this->type = TypeInfo( node->type);
        this->access = node->access;
    }    
};


class MethodInfo : public FunctionInfo {
public:
    string name;
    TypeInfo returnType;
    MethodType methodType;
    FieldAccess access;
    unordered_map<string, MethodParamInfo*> outerParams;
};

class ClassInfo {
public:
    string name;
    string parentName;
    unordered_map<string, FieldInfo*> fields;
    unordered_map<string, MethodInfo*> staticMethods;
    unordered_map<string, MethodInfo*> localMethods;
};

unordered_map<string, ClassInfo*> classes;
unordered_map<string, FunctionInfo*> functions;
unordered_map<string, EnumInfo*> enums;
/**
 *  
 * 
 */
class TableFiller : public NodeVisiter {
public:

    EnumInfo* currentEnum;
    void visit(EnumNode* node){
        RETURN_IF_NODE_NULL;

        this->currentEnum = new EnumInfo();
        for( auto ielem = node->elems.begin(); ielem != node->elems.end(); ielem++){
            this->currentEnum->elems[ielem->name] = *ielem;
        }

        enums[ this->currentEnum->name] = this->currentEnum;
    }

    FunctionInfo* currentFunction;

    void visit( FunctionNode* node) override {
		RETURN_IF_NODE_NULL

        this->currentFunction = new FunctionInfo();

        this->currentFunction->returnType = TypeInfo( node->returnType);
		this->currentFunction->name = node->name;

        for( auto iparam = node->params.begin(); iparam != node->params.end(); iparam++){
			auto param = *iparam;
            if( param){
                auto p = new FunctionParamInfo( param);
                this->currentFunction->params[p->name] = p;;
            }
        }

        functions[this->currentFunction->name] = this->currentFunction;
	} 


    MethodInfo* currentMethod;
	void visit( ClassMethodDeclarationNode* node) override { 
		RETURN_IF_NODE_NULL;

        if ( node->methodType == METHOD_STATIC){
            if( this->currentClass->staticMethods[node->name])
            ///TODO::Добавить ошибку
                throw "static method redef";
        } 
        else if ( node->methodType == METHOD_LOCAL){
            if( this->currentClass->localMethods[node->name])
            ///TODO::Добавить ошибку
                throw "local method redef";
        }

        this->currentMethod = new MethodInfo();
        this->currentMethod->name = node->name;
        this->currentMethod->access = node->access;
        this->currentMethod->returnType = TypeInfo( node->returnType);

        for( auto iparam = node->params.begin(); iparam != node->params.end(); iparam++){
			auto param = *iparam;
            if( param){
                auto mpi = new MethodParamInfo( param);
                this->currentMethod->params[ mpi->name] = mpi;
                this->currentMethod->outerParams[ mpi->outerName] = mpi;
            }
        }

        if( this->currentMethod->methodType == METHOD_LOCAL)
            this->currentClass->localMethods[ this->currentMethod->name] = this->currentMethod;
        else if( this->currentMethod->methodType == METHOD_STATIC)
            this->currentClass->staticMethods[ this->currentMethod->name ] = this->currentMethod;
	}
    
	void visit( ClassFieldDeclarationNode * node) override {
		RETURN_IF_NODE_NULL;
        auto field = new FieldInfo( node);
        this->currentClass->fields[field->name] = field;
	}

    ClassInfo* currentClass;
    void visit( ClassDeclarationNode* node) override {
		RETURN_IF_NODE_NULL;
		
        if( classes[node->name]){
            ///TODO:: Записать ошибку
            throw "class redefinition";    
        }
        this->currentClass = new ClassInfo();
        this->currentClass->name = node->name; 
        this->currentClass->parentName = node->parentName;
        

        for( auto ifield = node->fields.begin(); ifield != node->fields.end(); ifield++){
			auto field = * ifield;
            if( field)
                ( field)->visit( this);
        }

        for( auto imethod = node->methods.begin(); imethod != node->methods.end(); imethod++){
			auto method = *imethod;
            if( method)
                ( method)->visit( this);
        }

        
        classes[ this->currentClass->name] = currentClass;
	}

	void visit(ProgramNode * node) override {
		RETURN_IF_NODE_NULL;
		
		for( auto ifunc = node->functions.begin(); ifunc != node->functions.end(); ifunc++ ){
			auto func = *ifunc;
            if( func)
                ( func)->visit( this);
        }
        for( auto iclassDecl = node->classDeclarations.begin(); iclassDecl != node->classDeclarations.end(); iclassDecl++){
			auto classDecl = *iclassDecl;
            (classDecl)->visit( this);
        }
        for( auto ienum = node->enums.begin(); ienum != node->enums.end(); ienum++){
			auto _enum = *ienum;
            (_enum)->visit( this);
        }
	}
	

};