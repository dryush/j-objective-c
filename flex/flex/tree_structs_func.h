#pragma once

#include "tree_structs.h"

#include <stdlib.h>

struct Func_arg_st 
{
    struct Type_st* val_type;
    char* name;
};

struct Func_arg_st* createFuncArg(struct Type_st* valtype, char * name)
{
    struct Func_arg_st* st = (struct Func_arg_st*) malloc(sizeof(struct Func_arg_st));
    st->val_type = valtype;
    st->name = name;
    printf("CreateFuncArg\n");
    return st; 
}

struct Func_arg_list_st
{
    struct Func_arg_st* arg;
    struct Func_arg_list_st* next;
};

struct Func_arg_list_st* createFuncArgList( struct Func_arg_st* arg )
{
    struct Func_arg_list_st* st = (struct Func_arg_list_st*) malloc(sizeof(struct Func_arg_list_st));
    st->arg  = arg;
    st->next = NULL;
    printf("CreateFuncArgList\n");
    return st;
}

struct Func_arg_list_st* addToFuncArgList( struct Func_arg_list_st* list, struct Func_arg_st* arg) 
{
    struct Func_arg_list_st* last = list;
    while ( last->next)
        last = last->next;
    last->next = createFuncArgList(arg);
    printf("AddToFuncArgList\n");
    return list;
}

struct Func_declaration_st
{
    struct Type_st * return_type;
    char* name;
    struct Func_arg_list_st* args;
};

struct Func_declaration_st* createFuncDeclaration(
  struct Type_st* return_type, char*name, struct Func_arg_list_st * args )
{
    struct Func_declaration_st * st = (struct Func_declaration_st*) malloc(sizeof(struct Func_declaration_st));
    st->return_type = return_type;
    st->name = name;
    st->args = args;
    printf("CreateFuncDeclaration\n");
    return st;
}

struct Func_impl_st
{
    struct Type_st * return_type;
    char* name;
    struct Func_arg_list_st* args;
    struct Statement_st* body;
};

struct Func_impl_st* createFuncImpl(struct Func_declaration_st* decl, struct Statement_st* body)
{
    struct Func_impl_st* st = (struct Func_impl_st*)malloc(sizeof(struct Func_impl_st));
    st->return_type = decl->return_type;
    st->name = decl->name;
    st->args = decl->args;
    st->body = body;
    printf("CreateFuncImpl\n");
    return st;
}

struct Expression_st* createFuncCall( char* name, struct Expr_list_st* args)
{
    struct Expression_st* st = (struct Expression_st*) malloc ( sizeof(struct Expression_st));
    st->exprType = EXPR_FUNC_CALL;
    st->identifier = name;
    st->func_args = args;
    printf("createFuncCall\n");
    return st;
}

struct Expression_st* createFuncCallNoArgs( char* name)
{
    struct Expression_st* st = (struct Expression_st*) malloc ( sizeof(struct Expression_st));
    st->exprType = EXPR_FUNC_CALL;
    st->identifier = name;
    st->func_args = NULL;
    printf("createFuncCallNoArgs\n");
    return st;
}