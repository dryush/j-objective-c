#pragma once

#include "tree_structs.h"

/* КЛАССЫ */
enum Field_access_en
{
	A_PUBLIC,
	A_PROTECTED,
	A_PRIVATE,
	A_NOT_SET
};

struct Class_method_param_declaration_st
{
	/* Имя, которое будут использоваться внутри метода*/
	char* innerName;
	/* Имя, которое используется для ппередачи метода в параметр */
	char* outerName;
	struct Type_st* type;
};


struct Class_method_param_declaration_st* createClassMethodParamDeclaration( char* outerName, struct Type_st* type, char* innerName)
{
	struct Class_method_param_declaration_st* st = ( struct Class_method_param_declaration_st*) malloc( sizeof( struct Class_method_param_declaration_st));
	st->innerName = innerName;
	st->outerName = outerName;
	st->type = type;
	return st;
};

struct Class_method_param_declaration_list_st 
{
	struct Class_method_param_declaration_st* param;
	struct Class_method_param_declaration_list_st* next;
};

struct Class_method_param_declaration_list_st* createClassMethodParamDeclarationList( 
  struct Class_method_param_declaration_st* param )
{
	 struct  Class_method_param_declaration_list_st* st = (struct  Class_method_param_declaration_list_st*) malloc( sizeof(struct  Class_method_param_declaration_list_st));
	 st->param = param;
	 st->next = NULL;
	 return st;
 }

struct Class_method_param_declaration_list_st* addToClassMethodParamDeclarationList(
  struct Class_method_param_declaration_list_st* root, struct Class_method_param_declaration_st* param )
{
	struct Class_method_param_declaration_list_st* last = root;
	while ( last->next != NULL )
	 	last = last->next;
	last->next = createClassMethodParamDeclarationList(param); 
	return root;
}
struct Class_method_param_declaration_list_st* addToFrontClassMethodParamDeclarationList(
  struct Class_method_param_declaration_list_st* root, struct Class_method_param_declaration_st* param )
{

	struct Class_method_param_declaration_list_st* newRoot = createClassMethodParamDeclarationList(param);
	newRoot->next = root;
	return newRoot;
}

enum Method_type_en{
	NON_STATIC,
	STATIC
};

struct Class_method_declaration_st 
{
	char* name;
	struct Type_st* returnType;
	enum Method_type_en methodType;
	struct Class_method_param_declaration_list_st* params;
};

struct Class_method_declaration_st* createMethodDeclaration(enum Method_type_en methodType, struct Type_st* returnType, char* name, struct Class_method_param_declaration_list_st* params){
	struct Class_method_declaration_st* st = (struct Class_method_declaration_st*) malloc (sizeof(struct Class_method_declaration_st));
	st->methodType = methodType;
	st->returnType = returnType;
	st->name = name;
	st->params = params;
	return st;
}


struct Class_methods_declaration_list_st
{
	struct Class_method_declaration_st* method;
	struct Class_methods_declaration_list_st* next;
};

struct Class_methods_declaration_list_st* createMethodsDeclarationList( struct Class_method_declaration_st* method )
{
	struct Class_methods_declaration_list_st* st = (struct Class_methods_declaration_list_st*) malloc(sizeof(struct Class_methods_declaration_list_st));
	st->method = method;
	st->next = NULL;
	return st;
}

struct Class_methods_declaration_list_st* addToMethodsDeclarationList( 
  struct Class_methods_declaration_list_st* root, struct Class_method_declaration_st* method )
{
	struct Class_methods_declaration_list_st* last = root;
	while( last->next != NULL)
		last = last->next;
	last->next = createMethodsDeclarationList(method);
	return root;
}

struct Class_methods_declaration_block_st
{
	enum Field_access_en access;
	struct Class_methods_declaration_list_st* list;
};

struct Class_methods_declaration_block_st* createClassMethodsDeclarationBlock(
  enum Field_access_en access, struct Class_methods_declaration_list_st* list)
{
	struct Class_methods_declaration_block_st* st = (struct Class_methods_declaration_block_st*) malloc (sizeof(struct Class_methods_declaration_block_st));
	st->access = access;
	st->list = list;
	return st;
}

struct Class_methods_declaration_block_list_st
{
	struct Class_methods_declaration_block_st* list;
	struct Class_methods_declaration_block_list_st* next;
};

struct Class_methods_declaration_block_list_st* createClassMethodsDeclarationBlockList(
  struct Class_methods_declaration_block_st* list )
{
	struct Class_methods_declaration_block_list_st* st = (struct Class_methods_declaration_block_list_st*) malloc( sizeof(struct Class_methods_declaration_block_list_st));
	st->list = list;
	st->next = NULL;
}

struct Class_methods_declaration_block_list_st* addToClassMethodsDeclarationBlockList(
  struct Class_methods_declaration_block_list_st* root, struct Class_methods_declaration_block_st* list )
{
	struct Class_methods_declaration_block_list_st* last = root;
	while( last->next != NULL )
		last = last->next;
	last->next = createClassMethodsDeclarationBlockList(list);
}

struct Class_invariant_declaration_st
{
	char* name;
	struct Type_st* type;
};

struct Class_invariant_declaration_st* createClassInvariantDeclaration( struct Type_st* type, char * name)
{
	struct Class_invariant_declaration_st* st = (struct Class_invariant_declaration_st*) malloc( sizeof(struct Class_invariant_declaration_st));
	st->name = name;
	st->type = type;
	return st;
}

struct Class_invariants_declaration_list_st
{
	struct Class_invariant_declaration_st* invariant;
	struct Class_invariants_declaration_list_st* next;
};

struct Class_invariants_declaration_list_st* createClassInvariantsDeclarationList(
  struct Class_invariant_declaration_st* invariant)
{
	struct Class_invariants_declaration_list_st* st = (struct Class_invariants_declaration_list_st*) malloc(sizeof(struct Class_invariants_declaration_list_st*));
	st->invariant = invariant;
	st->next = NULL;
}

struct Class_invariants_declaration_list_st* addToClassInvariantsDeclarationList(
  struct Class_invariants_declaration_list_st* root, struct Class_invariant_declaration_st* invariant)
{
	struct Class_invariants_declaration_list_st* last = root;
	while( last->next != NULL)
		last = last->next;
	last->next = createClassInvariantsDeclarationList(invariant);
	return root;
}

struct Class_invariants_declaration_block_st
{
	enum Field_access_en access;
	struct Class_invariants_declaration_list_st* list;
};

struct Class_invariants_declaration_block_st* createClassInvariantsDeclarationBlock(
  enum Field_access_en access, struct Class_invariants_declaration_list_st* list )
{
	struct Class_invariants_declaration_block_st* st = (struct Class_invariants_declaration_block_st*) malloc(sizeof(struct Class_invariants_declaration_block_st));
	st->access = access;
	st->list = list;
}

struct Class_invariants_declaration_block_list_st
{
	struct Class_invariants_declaration_block_st* list;
	struct Class_invariants_declaration_block_list_st* next;
};

struct Class_invariants_declaration_block_list_st* createClassInvariantsDeclarationBlockList(
  struct Class_invariants_declaration_block_st* list )
{
	struct Class_invariants_declaration_block_list_st* st = (struct Class_invariants_declaration_block_list_st*) malloc( sizeof(struct Class_methods_declaration_block_list_st));
	st->list = list;
	st->next = NULL;
}

struct Class_invariants_declaration_block_list_st* addToClassInvariantsDeclarationBlockList(
  struct Class_invariants_declaration_block_list_st* root, struct Class_invariants_declaration_block_st* list )
{
	struct Class_invariants_declaration_block_list_st* last = root;
	while( last->next != NULL )
		last = last->next;
	last->next = createClassInvariantsDeclarationBlockList(list);
}


struct Class_declaration_st
{
	char * name;
	char * parentName;
	struct Class_methods_declaration_block_list_st* methods_declaraion_list;
	struct Class_invariants_declaration_block_st* invariants_declaration_list;
};

struct Class_declaration_st* createClassDeclaration(
  char* name, char* parentName,
  struct Class_methods_declaration_block_list_st* methods_declaraion_list,
  struct Class_invariants_declaration_block_st* invariants_declaration_list )
{
	struct Class_declaration_st* st = (struct Class_declaration_st*)malloc(sizeof(struct Class_declaration_st));
	st->name = name;
	st->parentName = parentName;
	st->methods_declaraion_list = methods_declaraion_list;
	st->invariants_declaration_list = invariants_declaration_list;
	return st;
};

struct Class_method_impl_st {
	char* name;
	struct Type_st* returnType;
	enum Method_type_en methodType;
	struct Statement_st* body;
	struct Class_method_param_declaration_list_st* params;

};

struct Class_method_impl_st* createClassMethodImpl(
  struct Class_method_declaration_st* decl, struct Statement_st* stmt)
{
	struct Class_method_impl_st* st = (struct Class_method_impl_st*) malloc( sizeof(struct Class_method_impl_st));
	st->name = decl->name;
	st->methodType = decl->methodType;
	st->params = decl->params;
	st->returnType = decl->returnType;
	st->body = stmt;
	return st;
}

struct Class_method_impl_list_st
{
	struct Class_method_impl_st* method;
	struct Class_method_impl_list_st* next;
};

struct Class_method_impl_list_st* createClassMethodImplList(struct Class_method_impl_st* method)
{
	struct Class_method_impl_list_st* st = (struct Class_method_impl_list_st*)malloc(sizeof(struct Class_method_impl_list_st));
	st->method = method;
	st->next = NULL;
}

struct Class_method_impl_list_st* addToClassMethodImplList( struct Class_method_impl_list_st* root, struct Class_method_impl_st* method)
{
	struct Class_method_impl_list_st* last = root;
	while( last->next != NULL)
		last = last->next;
	last->next = createClassMethodImplList(method);
	return root;
}

struct Class_impl_st
{
	char* name;
	struct Class_method_impl_list_st* methods;
}; 

struct Class_impl_st* createClassImpl( char * name, struct Class_method_impl_list_st * methods)
{
	struct Class_impl_st* st = (struct Class_impl_st*) malloc( sizeof(struct Class_impl_st));
	st->name = name;
	st->methods = methods;
	return st;
}

struct Invariant_call_st
{
    struct Expression_st* invariant;
    char * name; 
}; 

struct Invariant_call_st* createInvariantCall(
  struct Expression_st* invariant, char * name )
{
    struct Invariant_call_st* st = (struct Invariant_call_st*) malloc(sizeof(struct Invariant_call_st));
    st->name = name;
    st->invariant = invariant;
    return st;
}

struct Method_call_arg_st
{
	char* outer_name;
	struct Expression_st* value;
};

struct Method_call_arg_st* createMethodCallArg(
  char * outer_name, struct Expression_st* value)
{
	struct Method_call_arg_st* st = (struct Method_call_arg_st*)malloc(sizeof(struct Method_call_arg_st));
	st->outer_name = outer_name;
	st->value = value;
	return st;
}

struct Method_call_arg_list_st
{
	struct Method_call_arg_st* arg;
	struct Method_call_arg_list_st* next;
};

struct Method_call_arg_list_st* createMethodCallArgList(
  struct Method_call_arg_st* arg)
{
	struct Method_call_arg_list_st * st = (struct Method_call_arg_list_st*) malloc(sizeof(struct Method_call_arg_list_st));
	st->arg = arg;
	st->next = NULL;
	return st;
}

struct Method_call_arg_list_st* addToMethodCallArgList(
	struct Method_call_arg_list_st * root, struct Method_call_arg_st* arg )
{
	struct Method_call_arg_list_st* last = root;
	while ( last->next != NULL)
		last = last->next;
	last->next = createMethodCallArgList(arg);
	return root; 
}

struct Method_call_arg_list_st* addToFrontMethodCallArgList(
	struct Method_call_arg_list_st * root, struct Method_call_arg_st* arg )
{
	struct Method_call_arg_list_st* newRoot = createMethodCallArgList(arg);
	newRoot->next = root;
	return newRoot;
}

struct Method_call_st 
{
	struct Expression_st * object;
	char * name;
	struct Method_call_arg_list_st* args;
};

struct Method_call_st* createMethodCall( 
  struct Expression_st * object, char * name,
  struct Method_call_arg_list_st* args)
{
	struct Method_call_st * st = (struct Method_call_st*) malloc(sizeof(struct Method_call_st));
	st->args = args;
	st->name = name;
	st->object = object;
	return st;
}