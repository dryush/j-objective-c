#pragma once

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

    TypeNode* toNode() {
        auto retType = new TypeNode();
        
        retType->varType = this->type;
        
        if( retType->varType == VarType::TYPE_ARRAY) {
            retType->childType = new TypeNode();
            retType->childType->varType = this->arrayType;
            retType->childType->name = this->name;
        } else if ( retType->varType == VarType::TYPE_POINTER) {
            retType->childType = new TypeNode();
            retType->childType->varType = VarType::TYPE_CUSTOM;
            retType->childType->name = this->name;
        } else {
            retType->name = this->name;
        }
        return retType;
    }

    bool isEqual( TypeInfo& other){

        if ( this->type == other.type){
            if( this->type == TYPE_CUSTOM || this->type == POINTER){
                return this->name == other.name;
            } else if ( this->type == TYPE_ARRAY){
                return this->arrayType == other.arrayType && this->name == other.name;
            } else {
                return true;
            }
        }
        return false;
    }

    bool isEqual( TypeNode* node){
        return this->isEqual( TypeInfo(node));
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
private:
    int localVarNum;
public:
    FunctionInfo(){
        this->localVarNum = 0;
    }
    string name;
    TypeInfo returnType;
    unordered_map<string, FunctionParamInfo*> params;
    unordered_map<string, TypeInfo> localVars;
    unordered_map<string, int> localVarsNumber;

    bool getVar( string& name, TypeInfo* type = nullptr){
        auto var = localVars.find( name);
        if( var == localVars.end()){
            auto param = params.find( name);
            if( param == params.end())
                return false;
            *type = param->second->type;
            return true;
        }
        *type = var->second;
        return true;
    }

    
    bool addLocalVar( string& name, TypeInfo& type){
        if( !this->getVar(name) ){
            this->localVars[name] = type;
            this->localVarsNumber[name] = ++this->localVarNum;
            return true;
        }
        return false;
    }
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

    bool getMethod( string& name, MethodInfo* retMethod = nullptr){
        auto m = this->staticMethods.find( name);
        if ( m == this->staticMethods.end()) {
            m = this->localMethods.find( name);
            if ( m == this->localMethods.end()) {
                return false;
            }
        }
        if( retMethod)
            *retMethod = *m->second;
        return true;
    }

    MethodInfo* getMethod( ClassMethodImplementationNode* method){
        if( method->methodType == MethodType::METHOD_LOCAL)
            return localMethods[ method->name];
        else
            return staticMethods[ method->name];
    }

};

unordered_map<string, ClassInfo*> classes;

TypeInfo* getMethodVarType(string& classname, string& methodname, string& varname ){
    auto c = classes[ classname];
    MethodInfo m;
    TypeInfo* t = new TypeInfo();
    if( c->getMethod( methodname, &m) ){
        m.getVar( varname, t);
    } else {
        delete t;
        t = nullptr;
        auto f = c->fields[ varname];
        if( f)
            t = new TypeInfo(f->type);
    }
    return t;
}

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
            if( this->currentClass->staticMethods.find(node->name) != this->currentClass->staticMethods.end())
				addError("Static method " + node->name + " redefinition");
        } 
        else if ( node->methodType == METHOD_LOCAL){
            if( this->currentClass->localMethods.find(node->name) != this->currentClass->localMethods.end())
				addError("Local method " + node->name + " redefinition");
        }

        this->currentMethod = new MethodInfo();
        this->currentMethod->name = node->name;
        this->currentMethod->access = node->access;
        this->currentMethod->returnType = TypeInfo( node->returnType);
		this->currentMethod->methodType = node->methodType;

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
            addError("Class " + node->name + " redefinition");    
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

	void visit( ProgramNode * node) override {
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
	
    void visit( StatementNode* node) override {
        RETURN_IF_NODE_NULL;

        auto body = node->childs.front();
        
    }
};