#pragma once

#include "tree_structs.h"

#include <stdlib.h>

struct Expr_list_st* createExprList( struct Expression_st* elem)
{
    struct Expr_list_st* st = (struct Expr_list_st*) malloc(sizeof(struct Expr_list_st));
    st->expr = elem;
    st->next = NULL;
    return st;
}

struct Expr_list_st* addToExprList( 
    struct Expr_list_st* root, struct Expression_st * elem)
{
    struct Expr_list_st* last = root;
    while ( last->next != NULL)
        last = last->next;
    last->next = createExprList( elem);
    return root;
}

struct Expression_st* createArrayElemCall(
  struct Expression_st* array_exp, struct Expression_st* index )
{
    struct Expression_st* st = (struct Expression_st*)malloc(sizeof(struct Expression_st));
    st->left = array_exp;
    st->right = index;
    return st;
}