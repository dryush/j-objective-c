#pragma once
#include "TreeClass.h"

enum FieldAccess {
    ACCESS_PUBLIC,
    ACCESS_PROTECTED,
    ACCESS_PRIVATE
};
enum MethodType {
    METHOD_STATIC,
    METHOD_LOCAL
}

FieldAccess DEF_FIELD_ACCESS = ACCESS_PROTECTED;
FieldAccess DEF_METHOD_ACCESS = ACCESS_PROTECTED;


class ClassMethodParamNode : public Node {
public:
    string outerName;
    string innerName;
    TypeNode* type;
    ClassMethodParamNode( Class_method_param_declaration_st* st){
        this->outerName = st->outerName;
        this->innerName = st->innerName;
        this->type = new TypeNode(st->val_type);
    }
    static void FillFrom(list<ClassMethodParamNode*>& list, Class_method_param_declaration_list_st* st){
        auto last = st;
        while( last){
            list.push_back( new ClassMethodParamNode( last->param));
            last = last->next;
        }
    }
};

// Если будут ошибки, не забудь исправаить и ClassMethodImplementationNode
class ClassMethodDeclarationNode : public Node {
public:
    FieldAccess access;
    MethodType methodType;
    string name;
    list<ClassMethodParamNode*> params;
    TypeNode* returnType;
    ClassMethodDeclarationNode(Class_method_declaration_st* st){
        this->methodType = st->methodType == STATIC ? METHOD_STATIC : METHOD_LOCAL;
        this->name = st->name;
        this->return_type = new TypeNode( st->returnType);

        ClassMethodParamNode.FillFrom( this.params, st->params);
    }

    ClassMethodDeclarationNode(Class_method_declaration_st* st, Field_access_en access){
        ClassMethodDeclarationNode( st);
        st->access = 
            blockLast->access == A_PUBLIC ? ACCESS_PUBLIC :
            blockLast->access == A_PROTECTED ? ACCESS_PROTECTED :
            blockLast->access == A_PRIVATE ? ACCESS_PRIVATE :
            DEF_METHOD_ACCESS;
    }

    static void FillFrom(list<ClassMethodDeclarationNode*> list, Class_methods_declaration_block_list_st* st) {
        auto blockListLast = st;
        while( blockListLast){
            auto blockLast = blockListLast->list;
            while( blockLast){
                Field_access_en access = blockLast->access;
                auto last = blockLast->list;
                while( last){
                    fields.push_back(new ClassMethodDeclarationNode(last->method, access));
                    last = last->next;
                }
                blockLast = blockLast->next;
            }
            blockListLast = blockListLast->next;
        } 
    }
};


class ClassFieldDeclarationNode : public Node {
public:
    FieldAccess access;
    string name;
    TypeNode* type;

    ClassFieldDeclarationNode( Class_invariant_declaration_st* st){
        this->name = st->name;
        this->type = new TypeNode(st->val_type);
    }

    ClassFieldDeclarationNode( Class_invariant_declaration_st* st, Field_access_en access){
        ClassFieldDeclarationNode( st);
        st->access = 
            blockLast->access == A_PUBLIC ? ACCESS_PUBLIC :
            blockLast->access == A_PROTECTED ? ACCESS_PROTECTED :
            blockLast->access == A_PRIVATE ? ACCESS_PRIVATE :
            DEF_FIELD_ACCESS;
    }


    static void FillFrom( list<ClassFieldDeclarationNode*>& fields, Class_invariants_declaration_block_list_st * st ){
        auto blockListLast = st;
        while( blockListLast){
            auto blockLast = blockListLast->list;
            while( blockLast){
                Field_access_en access = blockLast->access;
                auto last = blockLast->list;
                while( last){
                    fields.push_back(new ClassFieldDeclarationNode(last->invariant, access));
                    last = last->next;
                }
                blockLast = blockLast->next;
            }
            blockListLast = blockListLast->next;
        } 
    }
};


class ClassDeclarationNode : public Node {
public:
    string name;
    string parentName;
    list<ClassFieldDeclarationNode*> fields;
    list<ClassMethodDeclarationNode*> methods;
    ClassDeclarationNode( Class_declaration_st* st ){
        this->name = st->name;
        this->parentName = st->parentName;
        ClassFieldDeclarationNode.FillFrom( st->invariants_declaration_list);
        ClassMethodDeclarationNode.FillFrom( st->methods_declaraion_list);
    }
};


// TODO::???Возможно отнаследовать от объявления???
class ClassMethodImplementationNode : public Node {
    
    FieldAccess access;
    MethodType methodType;
    string name;
    list<ClassMethodParamNode*> params;
    TypeNode* returnType;
    StatementNode* body;
    ClassMethodDeclarationNode(Class_method_impl_st* st){
        this->methodType = st->methodType == STATIC ? METHOD_STATIC : METHOD_LOCAL;
        this->name = st->name;
        this->return_type = new TypeNode( st->returnType);
        ClassMethodParamNode.FillFrom( this.params, st->params);
        this->body = new StatementNode( st->body);  
    }

    ClassMethodDeclarationNode(Class_method_impl_st* st, Field_access_en access){
        ClassMethodDeclarationNode( st);
        st->access = 
            blockLast->access == A_PUBLIC ? ACCESS_PUBLIC :
            blockLast->access == A_PROTECTED ? ACCESS_PROTECTED :
            blockLast->access == A_PRIVATE ? ACCESS_PRIVATE :
            DEF_METHOD_ACCESS;
    }

    static void FillFrom(list<ClassMethodImplementationNode*> list, Class_method_param_declaration_list_st* st) {
        auto last = st;
        while( last){
            fields.push_back(new ClassMethodImplementationNode(last->method, access));
            last = last->next;
        }
    }
}

class ClassImplementationNode : public Node {
public:
    string name;
    list<ClassMethodDeclarationNode*> methods;
    ClassImplementationNode( Class_impl_st* st){
        this->name = st->name;
        ClassMethodImplementationNode.FillFrom( st->methods);
    }
}


class MethodCallArgNode : public ExprNode {
public:
    string outerName;
    MethodCallArgNode( method_call_arg_st* st) : ExprNode(st->var_type){
        this->outerName = st->outer_name;
    }

    static void FillFrom( list<MethodCallArgNode*> list, Method_call_arg_list_st* st){
        auto last = st;
        while ( last){
            list.push_back( new MethodCallArgNode(last->arg));
            last = last->next;
        }
    }
}