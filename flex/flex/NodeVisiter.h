#pragma once

class Node;

#include "TreeClass.h"

#define RETURN_IF_FALSE(var) if(!var) return;
#define RETURN_IF_NODE_NULL RETURN_IF_FALSE(node) 
#define VISIT_IF_NOT_NULL(childnode) this->visit(childnode);
class NodeVisiter {
public:

	void visit( TypeNode* node){
		RETURN_IF_NODE_NULL
		VISIT_IF_NOT_NULL( node->childType);
	}

	void visit( ExprNode* node) {
		RETURN_IF_NODE_NULL
		VISIT_IF_NOT_NULL( node->left);
		VISIT_IF_NOT_NULL( node->right);
		VISIT_IF_NOT_NULL( node->arrayElems);
		VISIT_IF_NOT_NULL( node->object);
		VISIT_IF_NOT_NULL( node->funcArgs);
	}

	void visit( ExprListNode* node){
		RETURN_IF_NODE_NULL
		for( auto expr : node->exprs)
			VISIT_IF_NOT_NULL( expr);
	}

	void visit( StatementNode* node){
		RETURN_IF_NODE_NULL
		VISIT_IF_NOT_NULL( node->expr);
		VISIT_IF_NOT_NULL( node->condition);
		VISIT_IF_NOT_NULL( node->truthStmt);
		VISIT_IF_NOT_NULL( node->wrongStmt);
		for( auto childStmt : node->childs)
			VISIT_IF_NOT_NULL( childStmt);
	}

	void visit( FunctionParamNode* node){
		RETURN_IF_NODE_NULL
		VISIT_IF_NOT_NULL( node->type);
	}

	void visit( FunctionNode* node){
		RETURN_IF_NODE_NULL
		VISIT_IF_NOT_NULL( node->returnType);
		VISIT_IF_NOT_NULL( node->body);
		for( auto param : node->params)
			VISIT_IF_NOT_NULL( param);
	} 

	void visit( ClassMethodParamNode* node){
		RETURN_IF_NODE_NULL
		VISIT_IF_NOT_NULL( node->type);
	}

	void visit( ClassMethodDeclarationNode* node){ 
		RETURN_IF_NODE_NULL
		VISIT_IF_NOT_NULL(type);
		for( auto param : node->params)
			VISIT_IF_NOT_NULL( param);
	}

	void visit( ClassFieldDeclarationNode * node){
		RETURN_IF_NODE_NULL
		VISIT_IF_NOT_NULL( type);
	}

	void visit( ClassDeclarationNode* node){
		RETURN_IF_NODE_NULL
		for( auto field : node->fields)
			VISIT_IF_NOT_NULL( field);
		for( auto method : node->methods)
			VISIT_IF_NOT_NULL( method);
	}

	void visit( ClassMethodImplementationNode* node) {
		RETURN_IF_NODE_NULL
		VISIT_IF_NOT_NULL( node->returnType);
		VISIT_IF_NOT_NULL( node->body);
		for( auto param : node->params)
			VISIT_IF_NOT_NULL( param);
	}

	void visit( ClassImplementationNode* node){
		RETURN_IF_NODE_NULL
		for( auto method : node)
			VISIT_IF_NOT_NULL( method);
	}

	void visit( FunctionParam* node){
		RETURN_IF_NODE_NULL
		VISIT_IF_NOT_NULL( node->type);
	}

	void visit(FunctionNode* node){
		RETURN_IF_NODE_NULL
		VISIT_IF_NOT_NULL( node->returnType);
		VISIT_IF_NOT_NULL( node->body);
		for( auto param : node->params)
			VISIT_IF_NOT_NULL( param);
	}

	void visit(ProgramNode * node){
		RETURN_IF_NODE_NULL
		
		for( auto func : node->functions)
			VISIT_IF_NOT_NULL(func);
		for( auto classDecl : node->classDeclarations)
			VISIT_IF_NOT_NULL(classDecl);
		for( auto implDecl : node->classImplementations)
			VISIT_IF_NOT_NULL(implDecl);
	}
	
	void visit(Node* node) {
	}

};
