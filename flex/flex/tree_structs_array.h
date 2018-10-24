#pragma once

#include "tree_structs.h"

struct Array_const_elem_list_st
{
    struct Expression_st * elem;
    struct Array_const_elem_list_st * next;
};

struct Array_const_elem_list_st* createArrayConstElemList( Expression_st * elem)
{
    struct Array_const_elem_list_st * st = (struct Array_const_elem_list_st*) malloc(sizeof(struct Array_const_elem_list_st));
    st->elem = elem;
    st->next = NULL;
    return st;
}

struct Array_const_elem_list_st* addToArrayConstElemList( 
    struct Array_const_elem_list_st* root, Expression_st * elem)
{
    struct Array_const_elem_list_st* last = root;
    while ( last->next != NULL)
        last = last->next;
    last->next = createArrayConstElemList( elem);
    return root;
}

struct Array_elem_call_st
{
    Expression_st * array;
    Expression_st * index;
};

struct Array_elem_call_st* createArrayElemCall(
  Expression_st* array, Expression_st* index )
{
    struct Array_elem_call_st* st = (struct Array_elem_call_st*)malloc(sizeof(struct Array_elem_call_st));
    st->array = array;
    st->index = index;
    return st;
}