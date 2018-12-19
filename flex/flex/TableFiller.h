#pragma once

#include <unordered_map>
#include <string>
#include <vector>

#include "NodeVisiter.h"

struct pairhash { 
public: 
template <typename T, typename U> 
std::size_t operator()(const std::pair<T, U> &x) const 
{ 
return std::hash<T>()(x.first) ^ std::hash<U>()(x.second); 
} 
}; 

const string FUNCTIONS_CLASS = "______________________FUNCTIONS_CLASS______________________";
const string MAIN_CLASS = "______________________MAIN_CLASS______________________";
const string DEFAULT_FUNCTIONS_CLASS= "______________________DEFAULT_FUNCTIONS______________________";


class JavaConstantTable;

/// TODO::: Прописать деструкторы

class EnumInfo {
public: 
    string name;
    unordered_map<string, EnumElem> elems ;
    EnumNode* enumNode;
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
            if( node->childType->varType == TYPE_POINTER)
                this->name = node->childType->childType->name;
            else
                this->name = node->childType->name;
        } else if ( node->varType == TYPE_POINTER){
            this->name = node->childType->name;
        }
    }

    static TypeInfo Pointer( const string& classname) {
        TypeInfo info;
        info.type = TYPE_POINTER;
        info.name = classname;
        return info;
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
            if( this->type == TYPE_CUSTOM || this->type == TYPE_POINTER){
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
        if( node)
            return this->isEqual( TypeInfo(node));
        else
            false; ///TODO::: СПОРНО ДО БЕЗУМИЯ
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
    MethodParamInfo() : FunctionParamInfo() {
        this->outerName = "";
    }

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
     bool isDefault;

    FunctionInfo(){
        this->localVarNum = 0;
        isDefault = false;
    }

   
    string name;
    TypeInfo returnType;
    FunctionNode* functionNode;
    unordered_map<string, FunctionParamInfo*> params;
    unordered_map<string, TypeInfo> localVars;
    unordered_map<string, int> localVarsNumber;
    vector< FunctionParamInfo*> paramsList;
    unordered_map< FunctionParamInfo*, int> paramOrderNum;
    string descriptor;

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

    void addParam( FunctionParamInfo* param) {
        this->paramOrderNum[ param] = this->paramsList.size();
        this->paramsList.push_back( param);
        this->params[ param->name] = param;

    }
};

class FieldInfo {
public:
    string name;
    TypeInfo type;
    FieldAccess access;

    string classname;
    
    string descriptor;
    
    FieldInfo( ClassFieldDeclarationNode * node){
        this->name = node->name;
        this->type = TypeInfo( node->type);
        this->access = node->access;
    }    
};


class MethodInfo : public FunctionInfo {
public:
    string classname;
    
    MethodType methodType;

    ClassMethodDeclarationNode* methodDeclNode;
    ClassMethodImplementationNode* methodImplNode;


    FieldAccess access;
    unordered_map<string, MethodParamInfo*> outerParams;


    
    void addParam( MethodParamInfo* param) {
        FunctionInfo::addParam( param);
        //this->pa
        //this->params[ param->name] = param;
        this->outerParams[ param->outerName] = param;
    }
};

class ClassInfo {
public:
    bool isDefault;
    ClassInfo(){
        this->isDefault = false;
    }

    string name;
    string parentName;
    unordered_map<string, FieldInfo*> fields;
    unordered_map<string, MethodInfo*> staticMethods;
    unordered_map<string, MethodInfo*> localMethods;

    ClassDeclarationNode* classDeclNode;
    ClassImplementationNode* classImlpNode;

    JavaConstantTable* table;
    
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

MethodInfo* getLocalMethod( string& classname, string& method) {
    auto classinfo = classes.find(classname);
    if( classinfo != classes.end()){
        auto imethodinfo = classinfo->second->localMethods.find( method);
        if ( imethodinfo != classinfo->second->localMethods.end()){
            return imethodinfo->second;
        } else {
            return getLocalMethod( classinfo->second->parentName, method);
        }
    }
    return nullptr;
}

MethodInfo* getStaticMethod( const string& classname, const string& method){
    auto classinfo = classes.find(classname);
    if( classinfo != classes.end()){
        auto imethodinfo = classinfo->second->staticMethods.find( method);
        if ( imethodinfo != classinfo->second->staticMethods.end()){
            return imethodinfo->second;
        }
    }
    return nullptr;
}

TypeInfo* getMethodVarType(string& classname, string& methodname, string& varname ){
    auto c = classes[ classname];
    MethodInfo * m;
    TypeInfo* t = new TypeInfo();
    m = getLocalMethod(c->name, methodname);
    if( m){
        m->getVar( varname, t);
    } else {
        delete t;
        t = nullptr;
        auto f = c->fields[ varname];
        if( f)
            t = new TypeInfo(f->type);
    }
    return t;
}

FieldInfo* getField( string& classname, string& fieldname){
    auto classinfo = classes.find(classname);
    if( classinfo != classes.end()){
        auto ifieldinfo = classinfo->second->fields.find( fieldname);
        if ( ifieldinfo != classinfo->second->fields.end()){
            return ifieldinfo->second;
        } else {
            return getField( classinfo->second->parentName, fieldname);
        }
    }
    return nullptr;

}

unordered_map<string, FunctionInfo*> functions;
unordered_map<string, EnumInfo*> enums;

FunctionInfo* findFunction( const string& name){
    FunctionInfo* func = nullptr;

    auto ifunc = functions.find( name); 
        if( ifunc != functions.end())
            func = ifunc->second; 
        else
        {
            auto iclass = classes.find( DEFAULT_FUNCTIONS_CLASS); 
            if ( iclass != classes.end()) {
                
                auto im = iclass->second->staticMethods.find( name);
                if ( im != iclass->second->staticMethods.end()){
                    auto mp = *im;
                    func = static_cast<FunctionInfo*>( mp.second);
                    //////////////////КОСТЫЛИЩЕ НЕПОНЯТНОЕ ХЕРНИЩЕ
                    //func->name = im->second->name;
                    //func->returnType = im->second->returnType;
                    
                }
            }
        }
    return func;
}

/**
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*/



string genClassDescriptor( const string& classname){
    return string("L") + classname +";";
}

string genDescriptor( const TypeInfo& type){
    string descr = "";
    if( type.type == TYPE_INT) {
        descr = "I";
    } else if ( type.type == TYPE_FLOAT) {
        descr = "F";
    } else if ( type.type == TYPE_VOID) {
        descr = "V";
    } else if ( type.type == TYPE_CHAR) {
        descr = "I";
    } else if ( type.type == TYPE_STRING) {
        descr = "Ljava/lang/String;";
    } else if ( type.type == TYPE_CUSTOM) {
        descr = "I"; ///TODO::Дима, если не так - подумай, здесь CUSTOM == ENUM
    } else if ( type.type == TYPE_BOOL) {
        descr = "B?????";
    } else if ( type.type == TYPE_ARRAY) {
        descr = "[" + genDescriptor(TypeInfo( type.arrayType, type.name));
    } else if ( type.type == TYPE_POINTER) {
        descr = string("L") + type.name+";";
    }
    return descr;
}
string genDescriptor( FunctionInfo* method) {
    string descr = "(";
    FOR_EACH( param, method->params){
        descr += genDescriptor(param->second->type);
    }
    descr += ")";
    descr += genDescriptor( method->returnType);
    return descr;
}


string genDescriptor( MethodInfo* method) {
    string descr = "(";
    FOR_EACH( param, method->params){
        descr += genDescriptor(param->second->type);
    }
    descr += ")";
    descr += genDescriptor( method->returnType);
    return descr;
}


string genDescriptor( FieldInfo* field) {
    return genDescriptor( field->type);
}



#define IF_FIND_ELSE( from, what, then, another) { auto elem = from.find( what); if ( elem != from.end()) { then ;} else { another ;} } 
#define IF_FIND( from, what, then)  IF_FIND_ELSE( from, what, then, {;}) 

string to_string( int number) {
    return std::to_string((long long) number);
}

string to_string( float number) {
    return std::to_string((long double) number);
}

enum JavaTableRecordValueType {
    CONST_VAL_STR,
    CONST_VAL_INT,
    CONST_VAL_FLOAT,
    CONST_VAL_TWO_INT
};
enum JavaTableRecordType {
    CONSTANT_NOT_SET = -1,
    CONSTANT_UTF8 = 1,
    CONSTANT_Integer = 3,
    CONSTANT_Float = 4,
    CONSTANT_String = 8,
    CONSTANT_NameAndType = 12,
    CONSTANT_Class = 7,
    CONSTANT_Fieldref = 9,
    CONSTANT_Methodref = 10
    
};


class JavaTableRecord {
public:
    string strvalue;
    int intvalue;
    float floatvalue;
    pair<int, int> twointvalue;

    
    JavaTableRecordValueType valueType;
    JavaTableRecordType constantType;
    
    string to_csv_string(){
        string res;
        if( constantType == CONSTANT_Class){
            res = "CONSTANT_Class";
        } else if ( constantType == CONSTANT_Fieldref){
            res = "CONSTANT_Fieldref";
        } else if ( constantType == CONSTANT_Float){
            res = "CONSTANT_Float";
        } else if ( constantType == CONSTANT_Integer){
            res = "CONSTANT_Integer";
        } else if ( constantType == CONSTANT_Methodref){
            res = "CONSTANT_Methodref";
        } else if ( constantType == CONSTANT_NameAndType){
            res = "CONSTANT_NameAndType";
        } else if ( constantType == CONSTANT_NOT_SET){
            res = "CONSTANT_NOT_SET";
        } else if ( constantType == CONSTANT_String){
            res = "CONSTANT_String";
        } else if ( constantType == CONSTANT_UTF8){
            res = "CONSTANT_UTF8";
        }
        res += ";";
        if( valueType == CONST_VAL_STR) {
            res += "\"" + this->strvalue + "\"";
        } else if( valueType == CONST_VAL_FLOAT) {
            res += to_string(this->floatvalue);
        } else if( valueType == CONST_VAL_INT) {
            res += to_string(this->intvalue);
        } else if( valueType == CONST_VAL_TWO_INT) {
            res += to_string(this->twointvalue.first) + ", " + to_string(this->twointvalue.second);
        }
        return res;
    }

    JavaTableRecord(const string& val, const JavaTableRecordType& type){
        this->strvalue = val;
        this->constantType = type;
        this->valueType = CONST_VAL_STR;
    }

    
    JavaTableRecord(const int& val, const JavaTableRecordType& type){
        this->intvalue = val;
        this->constantType = type;
        this->valueType = CONST_VAL_INT;
    }

    JavaTableRecord(const float& val, const JavaTableRecordType& type){
        this->floatvalue = val;
        this->constantType = type;
        this->valueType = CONST_VAL_FLOAT;
    }
    
    JavaTableRecord(const int& val1, const int& val2, const JavaTableRecordType& type){
        this->twointvalue = make_pair( val1, val2);
        this->constantType = type;
        this->valueType = CONST_VAL_TWO_INT;
    }

    
    JavaTableRecord(const pair<int,int>& val, const JavaTableRecordType& type)  {
        this->twointvalue = val;
        this->constantType = type;
        this->valueType = CONST_VAL_TWO_INT;
    }

};

enum JVMFieldAccess{
    ACC_PUBLIC    =	0x0001,//	Declared public; may be accessed from outside its package.
    ACC_PRIVATE   =	0x0002,//	Declared private; usable only within the defining class.
    ACC_PROTECTED =	0x0004,//	Declared protected; may be accessed within subclasses.
    ACC_STATIC	  = 0x0008,//	Declared static.
    ACC_FINAL	  = 0x0010,//	Declared final; never directly assigned to after object construction (JLS §17.5).
    ACC_VOLATILE  =	0x0040,//	Declared volatile; cannot be cached.
    ACC_TRANSIENT =	0x0080,//	Declared transient; not written or read by a persistent object manager.
    ACC_SYNTHETIC =	0x1000,//	Declared synthetic; not present in the source code.
    ACC_ENUM	  = 0x4000,//	Declared as an element of an enum.
};


class JavaFieldTableRecord{
public:    
    int access;
    int nameId;
    int descriptorId; //NameType
    int atributesCount; // =0
    
    JavaFieldTableRecord() {
        access = ACC_PUBLIC;
        nameId = -1;
        descriptorId = -1;
        atributesCount = 0;
    }

    JavaFieldTableRecord( FieldInfo* field, int name, int descriptor) {
        if( field->access == ACCESS_PUBLIC)
            access = ACC_PUBLIC;
        else if( field->access == ACCESS_PROTECTED)
            access = ACC_PROTECTED;
        else if( field->access == ACCESS_PRIVATE)
            access = ACC_PRIVATE;
        
        nameId = name;
        descriptorId = descriptor;
        atributesCount = 0;
    }
};

class JavaMethodTableRecord : public JavaFieldTableRecord {

public:
    MethodInfo* methodInfo;
    FunctionInfo* funcInfo;

    JavaMethodTableRecord( MethodInfo* method, int name, int descriptor){
        if( method->access == ACCESS_PUBLIC)
            access = ACC_PUBLIC;
        else if( method->access == ACCESS_PROTECTED)
            access = ACC_PROTECTED;
        else if( method->access == ACCESS_PRIVATE)
            access = ACC_PRIVATE;
        
        if( method->methodType == MethodType::METHOD_STATIC)
            access |= ACC_STATIC;

        nameId = name;
        descriptorId = descriptor;
        atributesCount = 0;
        methodInfo = method;
        funcInfo = nullptr;
     }
    JavaMethodTableRecord( FunctionInfo* method, int name, int descriptor){
        
        access = ACC_PUBLIC;
        access |= ACC_STATIC;

        nameId = name;
        descriptorId = descriptor;
        atributesCount = 0;
        funcInfo = method;
        methodInfo = nullptr;
     }
};
class JavaConstantTable {
public:
    ///
    bool isDefault;

    //// КОНСТАНТЫ
    
    unordered_map<string, int> utf8s;
    unordered_map<int, int> ints;
    unordered_map<float, int> floats;
    unordered_map<string, int> strings;
    unordered_map<pair<int,int>, int, pairhash> nametypes;
    unordered_map<int, int> classes;
    unordered_map<pair<int, int>, int, pairhash> fields;
    unordered_map<pair<int, int>, int, pairhash> methods;
    
    ///
    int classconst;
    unordered_map<string, int> constructors;
    int superclassconst;
    string classname;

    /// 
    vector<JavaTableRecord> records;


    ///
    vector<JavaFieldTableRecord> fieldsTable;
    vector<JavaMethodTableRecord> methodsTable;
    


    ///
    unordered_map<pair<string,string>, int, pairhash> methodNumByName;
    unordered_map<pair<string,string>, int, pairhash> fieldNumByName;
    
    unordered_map< int, int> classByMethod;
    unordered_map< string, int> classNumByName;

    string to_csv_string(){
        string res;
        for( int i =1; i < records.size(); i++){
            res += to_string(i) + ";" + records[i].to_csv_string() + "\n";
        }
        return res;
    }
    JavaConstantTable(){
        //Нумерация с единицы, вроде как
        records.push_back(JavaTableRecord("", CONSTANT_NOT_SET));
    }
    int addUtf8( string str) {
        auto elem = utf8s.find( str);
        if ( elem != utf8s.end())
        { return elem->second; }
        else
        {
            records.push_back(JavaTableRecord(str, CONSTANT_UTF8));
            int num = records.size()-1;
            utf8s[ str] = num;
            return num;
        }

    }

    
    int addInt( const int& number) {
        IF_FIND_ELSE( ints, number,
        { return elem->second;},
        {
            records.push_back(JavaTableRecord(number, CONSTANT_Integer));
            int num = records.size()-1;
            ints[ number] = num;
            return num;
        });

    }

    int addFloat( const float& number) {
        IF_FIND_ELSE( ints, number,
        { return elem->second;},
        {
            records.push_back(JavaTableRecord(number, CONSTANT_Float));
            int num = records.size()-1;
            floats[ number] = num;
            return num;
        });
    }

    int addStr ( const string& str) {
        IF_FIND_ELSE( strings, str,
        { return elem->second;},
        {
            int utf8num = addUtf8( str);
            records.push_back(JavaTableRecord(utf8num, CONSTANT_String));
            int num = records.size()-1;
            strings[ str] = num;
            return num;
        });
    }

    int addClass( const string& classname){
        
        int numutf8 = addUtf8( classname);
        int num = -1;
        IF_FIND_ELSE( classes, numutf8,
        { num = elem->second;},
        {
            records.push_back( JavaTableRecord( numutf8, CONSTANT_Class));
            num = this->classNumByName[classname] = this->classes[ numutf8] = (int)records.size()-1;
            
            //Константа для атрибута Code
            addUtf8( "Code");
            //Константа деффолтного конструктора
            this->constructors[ classname] = addMethod(classname, "<init>", "()V");

        }
        );

        return num;
    }

    int addNameAndType( const string& name, const string& typedescr) {
        int namenum = addUtf8( name);
        int typenum = addUtf8( typedescr);
        int num = -1;
        auto tn = make_pair(namenum, typenum);
        IF_FIND_ELSE( this->nametypes, tn,
        {num = elem->second;},
        {
            records.push_back( JavaTableRecord( tn, CONSTANT_NameAndType));
            num = this->nametypes[ tn] = records.size()-1;
        });

        return num;
    }

    int addField( const string& classname, const string& fieldname, const string& typedecr){
        int classnum = addClass( classname);
        int typenamenum = addNameAndType( fieldname, typedecr);
        auto classfield = make_pair(classnum, typenamenum);
        int num = -1;
        IF_FIND_ELSE( this->fields, classfield, 
        { num = elem->second;},
        { 
            records.push_back( JavaTableRecord( classfield, CONSTANT_Fieldref));
            num = this->fields[classfield] = records.size()-1;
        }
        );
        
        this->fieldNumByName[ make_pair( classname, fieldname)] = num;

        return num;
    }

    int addMethod( const string& classname, const string& methodname, const string& typedecr){
        int classnum = addClass( classname);
        int typenamenum = addNameAndType( methodname, typedecr);
        auto classmethod = make_pair(classnum, typenamenum);
        int num = -1;
        IF_FIND_ELSE( this->methods, classmethod, 
        { num = elem->second;},
        { 
            records.push_back( JavaTableRecord( classmethod, CONSTANT_Methodref));
            num = this->methods[classmethod] = records.size()-1;
            this->methodNumByName[ make_pair( classname, methodname)] = num;
            this->classByMethod[ num] = classnum;
        }
        );
        return num;
    }

    int addValue( ExprNode * valueNode){
        int nm = -1;
        if( valueNode->exprType == EXPR_OPERATION){
            if( valueNode->operationType == OP_VALUE){
                if      ( valueNode->constType ==VarType::TYPE_BOOL ) nm = addInt( valueNode->boolVal);
                else if ( valueNode->constType == VarType::TYPE_CHAR) nm = addInt( valueNode->charVal);
                else if ( valueNode->constType == VarType::TYPE_INT)  nm = addInt( valueNode->intVal);
                else if ( valueNode->constType == VarType::TYPE_FLOAT) nm = addFloat( valueNode->floatVal);
                else if ( valueNode->constType == VarType::TYPE_STRING) nm = addStr(valueNode->strVal);

            }
        }
        return nm;
    }

    int addFunction( FunctionInfo* func){
        string typeDescr = genDescriptor( func);
        int mn = -1;
        if( func->isDefault)
            mn = addMethod( DEFAULT_FUNCTIONS_CLASS, func->name, typeDescr);
        else
            mn = addMethod( FUNCTIONS_CLASS, func->name, typeDescr);

        //JavaMethodTableRecord methodRecord( func, this->utf8s[ func->name], this->utf8s[func->descriptor]);
        //this->methodsTable.push_back( methodRecord);

        return mn;
    }
    
    int addFunctionImpl( FunctionInfo* func){
        int mn = addFunction( func); 
        JavaMethodTableRecord methodRecord( func, this->utf8s[ func->name], this->utf8s[func->descriptor]);
        this->methodsTable.push_back( methodRecord);

        return mn;
    }



    int addMethod( MethodInfo* method){
        
        string typeDescr = genDescriptor( method);
        return addMethod( method->classname, method->name, typeDescr);
    }

    void addClassMethod( MethodInfo* method){
        this->addMethod( method);
        
        JavaMethodTableRecord methodRecord ( method, this->utf8s[ method->name], this->utf8s[method->descriptor]); 
        
        this->methodsTable.push_back( methodRecord);

    } 

    int addField( FieldInfo* field) {
        
        string typeDescr = genDescriptor( field);
        return addField( field->classname, field->name, typeDescr);
        
    }

    void addClassField( FieldInfo* field){
        this->addField( field);
        
        JavaFieldTableRecord fieldRecord ( field, this->utf8s[ field->name], this->utf8s[field->descriptor]); 
        
        this->fieldsTable.push_back( fieldRecord);
    }

    void addClass( ClassInfo* classinfo){
        FOR_EACH( imeth, classinfo->localMethods) {
            auto meth = *imeth; 
            addClassMethod( meth.second);
        }
        FOR_EACH( imeth, classinfo->staticMethods) {
            auto meth = *imeth; 
            addClassMethod( meth.second);
        }
        FOR_EACH( ifield, classinfo->fields) {
            auto field = *ifield; 
            addClassField( field.second);
        }
        this->classconst = this->addClass( classinfo->name);
        this->superclassconst = this->addClass( classinfo->parentName);
        this->classname = classinfo->name;
        this->isDefault = classinfo->isDefault;

    }


};




void fillDefaultClasses() {
    ClassInfo* nsoclassinfo = new ClassInfo();
    nsoclassinfo->isDefault = true;
    nsoclassinfo->name = "NSObject";
    nsoclassinfo->parentName = JavaLangObject;
    nsoclassinfo->table = new JavaConstantTable();
    
    ClassInfo* nssclassinfo = new ClassInfo();
    nssclassinfo->isDefault = true;
    nssclassinfo->name = "NSString";
    nssclassinfo->parentName = defaultParentClass;
    nssclassinfo->table = new JavaConstantTable();
    ///TODO::: Список методов NSString
    auto nssinitm = new MethodInfo();
    nssinitm->isDefault = true;
    nssinitm->name = "init";
    auto stringParam = new MethodParamInfo();
    stringParam->name = "string";
    stringParam->outerName = "string";
    stringParam->type.type = TYPE_STRING;
    nssinitm->addParam( stringParam);

    nssinitm->returnType = TypeInfo::Pointer( nssclassinfo->name);
    nssinitm->classname = nssclassinfo->name;
    nssinitm->access = ACCESS_PUBLIC;
    nssinitm->methodType = METHOD_LOCAL;

    nssclassinfo->localMethods[ nssinitm->name] = nssinitm;


    auto fromInt = new MethodInfo();
    fromInt->isDefault = true;
    fromInt->name = "fromInt";
    auto intParam = new MethodParamInfo();
    intParam ->name = "number";
    intParam ->outerName = "number";
    intParam ->type.type = TYPE_INT;
    fromInt ->addParam( intParam);

    fromInt ->returnType = TypeInfo::Pointer( nssclassinfo->name);
    fromInt ->classname = nssclassinfo->name;
    fromInt ->access = ACCESS_PUBLIC;
    fromInt ->methodType = METHOD_STATIC;
    nssclassinfo->staticMethods[ fromInt->name] = fromInt;

    
    auto strAppnend = new MethodInfo();
    strAppnend->isDefault = true;
    strAppnend->name = "append";
    auto nsstringParam = new MethodParamInfo();
    nsstringParam ->name = "string";
    nsstringParam ->outerName = "string";
    nsstringParam ->type.type = TYPE_POINTER;
    nsstringParam ->type.name = "NSString";
    strAppnend->addParam( nsstringParam );

    strAppnend->returnType = TypeInfo::Pointer( nssclassinfo->name);
    strAppnend->classname = nssclassinfo->name;
    strAppnend->access = ACCESS_PUBLIC;
    strAppnend->methodType = METHOD_STATIC;
    nssclassinfo->localMethods[ strAppnend->name] = strAppnend;

    classes[nsoclassinfo->name] = nsoclassinfo;
    classes[nssclassinfo->name] = nssclassinfo;

    ClassInfo* NSScanner = new ClassInfo();
    NSScanner->name = "NSScanner";
    NSScanner->isDefault = true;
    NSScanner->parentName = defaultParentClass;
    NSScanner->table = new JavaConstantTable();
    vector<string> scanNames;
    scanNames.push_back( "scanInt");
    scanNames.push_back( "scanString");
    scanNames.push_back( "scanFloat");

    FOR_EACH( scanname, scanNames){
        auto scan = new MethodInfo();
        scan->isDefault = true;
        scan->name = *scanname;
        scan->classname = NSScanner->name;
        scan->returnType = TypeInfo::Pointer( nssclassinfo->name);
        scan->access = ACCESS_PUBLIC;
        scan->methodType = METHOD_LOCAL;
        NSScanner->localMethods[ scan->name] = scan;
    }
    auto nsscanerInit = new MethodInfo();
    nsscanerInit->name ="init";
    nsscanerInit->classname = "NSScanner";
    nsscanerInit->isDefault = true;
    nsscanerInit->returnType = TypeInfo::Pointer( nsscanerInit->classname);
    nsscanerInit->access = ACCESS_PUBLIC;
    nsscanerInit->methodType = METHOD_LOCAL;
    classes[ NSScanner->name] = NSScanner;
    NSScanner->localMethods[ nsscanerInit->name] = nsscanerInit;


    ClassInfo* starter = new ClassInfo();
    starter->name = MAIN_CLASS;
    starter->parentName = JavaLangObject;
    starter->isDefault = true;
    //starter->staticMethods
    MethodInfo* main = new MethodInfo();
    main->isDefault = true;
    main->name = "main";
    main->access = ACCESS_PUBLIC;
    main->methodType = METHOD_STATIC;
    main->returnType.type = TYPE_VOID;

    MethodParamInfo* mainParam = new MethodParamInfo();
    mainParam->name = "args";
    mainParam->type.type = TYPE_ARRAY;
    mainParam->type.arrayType = TYPE_STRING;

    main->addParam( mainParam);
    

    FOR_EACH( cl, classes){
        if( cl->second->isDefault)
            cl->second->table->addClass( cl->second);
    }
}
void fillDefaultMethods() {
    MethodInfo alloc;
    alloc.name = "alloc";
    alloc.access = ACCESS_PUBLIC;
    alloc.methodType = MethodType::METHOD_STATIC;
    alloc.isDefault = true;

    
    MethodInfo constructor;
    constructor.name = "<init>";
    constructor.access = ACCESS_PUBLIC;
    constructor.methodType = MethodType::METHOD_LOCAL;
    constructor.isDefault = true;

    TypeInfo cRetType;
    cRetType.type = TYPE_VOID;
    constructor.returnType = cRetType;

    FOR_EACH( cl, classes){
        alloc.classname = cl->second->name;
        
        TypeInfo t;
        t.type = TYPE_POINTER;
        t.name = cl->second->name;
        alloc.returnType = t;
        cl->second->staticMethods[ alloc.name] = new MethodInfo( alloc);
        //cl->second->staticMethods[ alloc.name]
        
        constructor.classname = cl->second->name;
        //cl->second->localMethods[ constructor.classname] = new MethodInfo( constructor); 
    }
}

void fillDefaultFunctions() {

    auto defFuncClass = new ClassInfo();
    if( classes[ DEFAULT_FUNCTIONS_CLASS]){
        throw "why2";
    } else {
        defFuncClass->parentName = defaultParentClass;
        defFuncClass->name= FUNCTIONS_CLASS;
        defFuncClass->table= new JavaConstantTable();
        classes[ DEFAULT_FUNCTIONS_CLASS] = defFuncClass;
    }

    MethodInfo* printf = new MethodInfo();
    printf->classname = DEFAULT_FUNCTIONS_CLASS;
    printf->isDefault = true;
    printf->name = "printf";
    printf->returnType.type = TYPE_VOID;
    
    FunctionParamInfo* stringParam = new FunctionParamInfo();
    stringParam->name = "string";
    stringParam->type = TypeInfo::Pointer("NSString");
    printf->params[ stringParam->name] = stringParam;
    defFuncClass->staticMethods[ printf->name] = printf;
    

    defFuncClass->table->addClass( defFuncClass);
}

/**
 * 
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * 
 */
class ClassTableFiller : public NodeVisiter {
public:
    void visit( ProgramNode* node) override {
        
        for( auto iclassDecl = node->classDeclarations.begin(); iclassDecl != node->classDeclarations.end(); iclassDecl++){
			auto classDecl = *iclassDecl;
            (classDecl)->visit( this);
        }

    }


    ClassInfo* currentClass;
    void visit( ClassDeclarationNode* node) override {
		RETURN_IF_NODE_NULL;
		
        if( classes[node->name]){
            addError("Class " + node->name + " redefinition");    
        }
        this->currentClass = new ClassInfo();
        this->currentClass->table = new JavaConstantTable();

        this->currentClass->name = node->name; 
        this->currentClass->parentName = node->parentName;
        classes[ this->currentClass->name] = currentClass;

        this->currentClass->classDeclNode = node;

	}

};

class TableFiller : public NodeVisiter {
public:

    EnumInfo* currentEnum;
    void visit(EnumNode* node){
        RETURN_IF_NODE_NULL;

        this->currentEnum = new EnumInfo();
        for( auto ielem = node->elems.begin(); ielem != node->elems.end(); ielem++){
            this->currentEnum->elems[ielem->name] = *ielem;
        }

        this->currentEnum->enumNode = node;
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
                this->currentFunction->addParam( p);
            }
        }

        this->currentFunction->functionNode = node;

        this->currentFunction->descriptor = genDescriptor( this->currentFunction);

        functions[this->currentFunction->name] = this->currentFunction;
	} 

    
    ClassInfo* currentClass;
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
        this->currentMethod->classname = this->currentClass->name;
		this->currentMethod->methodType = node->methodType;

        for( auto iparam = node->params.begin(); iparam != node->params.end(); iparam++){
			auto param = *iparam;
            if( param){
                auto mpi = new MethodParamInfo( param);
                this->currentMethod->addParam( mpi);
            }
        }

        
        this->currentMethod->descriptor = genDescriptor( this->currentMethod);
        this->currentMethod->methodDeclNode = node;

        if( this->currentMethod->methodType == METHOD_LOCAL)
            this->currentClass->localMethods[ this->currentMethod->name] = this->currentMethod;
        else if( this->currentMethod->methodType == METHOD_STATIC) 
            this->currentClass->staticMethods[ this->currentMethod->name ] = this->currentMethod;

        
	}
    
	void visit( ClassFieldDeclarationNode * node) override {
		RETURN_IF_NODE_NULL;
        auto field = new FieldInfo( node);
        
        field->descriptor = genDescriptor( field);
        field->classname = currentClass->name;

        if( getField( this->currentClass->name, field->name)) {
            addError(string("field redefenition ") + currentClass->name + "::" + field->name);
        } else {
            this->currentClass->fields[field->name] = field;
        }
	}

    void visit( ClassDeclarationNode* node) override {
		RETURN_IF_NODE_NULL;

        this->currentClass = classes[ node->name]; 
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

        this->currentClass->classDeclNode = node;

	}

	void visit( ProgramNode * node) override {
		RETURN_IF_NODE_NULL;
		
        fillDefaultClasses();
        fillDefaultFunctions();

        classes[FUNCTIONS_CLASS] = new ClassInfo();
        classes[FUNCTIONS_CLASS]->parentName = defaultParentClass;
        classes[FUNCTIONS_CLASS]->name= FUNCTIONS_CLASS;
        classes[FUNCTIONS_CLASS]->table= new JavaConstantTable();
        


        classes[FUNCTIONS_CLASS]->table->addClass( classes[FUNCTIONS_CLASS]);


        for( auto iclassDecl = node->classDeclarations.begin(); iclassDecl != node->classDeclarations.end(); iclassDecl++){
			auto classDecl = *iclassDecl;
            (classDecl)->visit( this);
        }

		for( auto ifunc = node->functions.begin(); ifunc != node->functions.end(); ifunc++ ){
			auto func = *ifunc;
            if( func)
                ( func)->visit( this);
        }
        
        FOR_EACH( ifunc, functions){ 
            classes[FUNCTIONS_CLASS]->table->addFunctionImpl( ifunc->second);
        }

        fillDefaultMethods();

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

class JVMTableFiller : public NodeVisiter {

    void visit( ProgramNode* node){
        NodeVisiter::visit( node);
        FOR_EACH( cl ,classes){
            if( cl->second->isDefault){
                cl->second->table->addClass( cl->second);
            }
        }
    }

    bool isFunc;
    FunctionNode* curFunc;
    void visit( FunctionNode* node) override {
        isFunc = true;
        curFunc = node;
        NodeVisiter::visit( node);
        curFunc = nullptr;
        isFunc = false;
    }

    bool isMethod;
    ClassMethodDeclarationNode* curMethod;
    void visit( ClassMethodDeclarationNode* node) override {
        isMethod = true;
        curMethod = node;
        NodeVisiter::visit( node);
        curMethod = nullptr;
        isMethod = false;
    }

    bool isClass;
    ClassDeclarationNode* curClass;
    void visit( ClassDeclarationNode* node) override {
        isClass = true;
        curClass = node;
        auto c = classes[curClass->name];
        c->table->addClass(c);
        NodeVisiter::visit(node);
        isClass = false;
        curClass = nullptr;
    }

    
	virtual void visit( MethodCallArgNode* node){
		RETURN_IF_NODE_NULL;
        static_cast<ExprNode*>(node)->visit(this);
	}

    void visit( ExprNode* node) override {
        if( node->exprType == EXPR_METHOD_CALL) {
            ClassInfo * c;
            MethodInfo* m;
            bool isOk = true;
            if ( node->object->returnType->varType == TYPEE_CLASS){
                c = classes[ node->object->returnType->name];
                m = c->staticMethods[ node->name];
                if ( node->name == "alloc" && m->params.size() == 0){
                    node->isAlloc = true;
                }
            } else if ( node->object->returnType->varType == TYPE_POINTER) {
                c = classes[ node->object->returnType->childType->name];
                m = c->localMethods[node->name];
            } else {
                addError("Need Test Why this Error");
                isOk = false;
            }

            if( isOk)
                if( isClass)
                    node->constantNum = classes[this->curClass->name]->table->addMethod( m);
                else
                    node->constantNum = classes[ FUNCTIONS_CLASS]->table->addMethod( m);

        } else if( node->exprType == EXPR_FUNC_CALL) {

            auto f = findFunction( node->name);
            if( isClass)
                node->constantNum = classes[this->curClass->name]->table->addFunction( f);
            else
                node->constantNum = classes[ FUNCTIONS_CLASS]->table->addFunction( f);
        } else if( node->exprType == EXPR_INVAR_CALL) {

            auto f = getField( node->object->returnType->childType->name, node->name);
            
            if( f){
                if( isClass)
                    node->constantNum = classes[this->curClass->name]->table->addField( f);
                else
                    node->constantNum = classes[ FUNCTIONS_CLASS]->table->addField( f);
            }
        } else if( node->exprType == EXPR_OPERATION && node->operationType == OP_VALUE) {
            
            if( isClass)
                node->constantNum = classes[this->curClass->name]->table->addValue( node);
            else
                node->constantNum = classes[ FUNCTIONS_CLASS]->table->addValue( node);
            
        }
        NodeVisiter::visit( node);
    }

public: 
    JVMTableFiller() {
		this->curClass = nullptr;
		this->curFunc = nullptr;
		this->curMethod = nullptr;
		
		this->isClass= false;
		this->isMethod= false;
		this->isFunc= false;

    }
};