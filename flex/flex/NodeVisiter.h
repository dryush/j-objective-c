#pragma once

class Node;
#include <iostream>

#include "TreeClass.h"


#include "CommonNodes.h"
#include "ClassNodes.h"
#include "FunctionNodes.h"
#include "ProgramNode.h"


#define RETURN_IF_FALSE(var) if(!var) return;
#define RETURN_IF_NODE_NULL RETURN_IF_FALSE(node);
#define VISIT_IF_NOT_NULL(childnode) if(childnode) childnode->visit(this);
#define FOR_EACH( elem, container) for( auto elem = container.begin(); elem != container.end(); elem++)


class NodeVisiter {
public:

	virtual void visit( TypeNode* node){
		RETURN_IF_NODE_NULL;
        if( node->childType)
            ((node->childType))->visit( this);
	}

	virtual void visit( ExprListNode* node){
		RETURN_IF_NODE_NULL;
        for( auto iexpr = node->exprs.begin(); iexpr != node->exprs.end(); iexpr++){
            auto expr = *iexpr;
            if( expr)
                ( expr)->visit( this);
        }
	}

	virtual void visit( ExprNode* node) {
		RETURN_IF_NODE_NULL;
        if( node->left)
            (node->left)->visit( this);
		if( node->right)
            ( node->right)->visit( this);
        if( node->arrayElems)
            ( node->arrayElems)->visit( this);
        if( node->object)
            ( node->object)->visit( this);
		if( node->funcArgs)
            ( node->funcArgs)->visit( this);
        FOR_EACH( arg,node->methodCallArgs) VISIT_IF_NOT_NULL( (*arg))
	}


	virtual void visit( StatementNode* node){
		RETURN_IF_NODE_NULL;
		if( node->expr)
            ( node->expr)->visit( this);
		if( node->condition)
            ( node->condition)->visit( this);
        if( node->truthStmt)
            ( node->truthStmt)->visit( this);
		if( node->wrongStmt)
            ( node->wrongStmt)->visit( this);

        for( auto ichildStmt = node->childs.begin(); ichildStmt != node->childs.end(); ichildStmt++){
            auto childStmt = *ichildStmt;
			if( childStmt)
                ( childStmt)->visit( this);
        }
	}

	virtual void visit ( FunctionParamNode* node){
		RETURN_IF_NODE_NULL;
		if( node->type)
            ( node->type)->visit( this);
	}

	virtual void visit( FunctionNode* node){
		RETURN_IF_NODE_NULL
		if( node->returnType)
            ( node->returnType)->visit( this);
		if( node->body)
            ( node->body)->visit( this);
        for( auto iparam = node->params.begin(); iparam != node->params.end(); iparam++){
			auto param = *iparam;
            if( param)
                ( param)->visit( this);
        }
	} 

	virtual void visit( ClassMethodParamNode* node){
		RETURN_IF_NODE_NULL;
		if( node->type)
            ( node->type)->visit( this);
	}

	virtual void visit( ClassMethodDeclarationNode* node){ 
		RETURN_IF_NODE_NULL;
        if( node->returnType){
            node->returnType->visit( this);
        }
		for( auto iparam = node->params.begin(); iparam != node->params.end(); iparam++){
			auto param = *iparam;
            if( param)
                ( param)->visit( this);
        }
	}

	virtual void visit( ClassFieldDeclarationNode * node){
		RETURN_IF_NODE_NULL;
		if( node->type) 
            ( node->type)->visit( this);
	}

	virtual void visit( ClassDeclarationNode* node){
		RETURN_IF_NODE_NULL;
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
	}

	virtual void visit( ClassMethodImplementationNode* node) {
		RETURN_IF_NODE_NULL;
		if( node->returnType)
            ( node->returnType)->visit( this);

		if( node->body)
            ( node->body)->visit( this);

		for( auto iparam = node->params.begin(); iparam != node->params.end(); iparam++){
			auto param = *iparam;
            if( param)
                ( param)->visit( this);
        }
	}

	virtual void visit( ClassImplementationNode* node){
		RETURN_IF_NODE_NULL;
        for( auto imethod = node->methods.begin(); imethod != node->methods.end(); imethod++){
			auto method = *imethod;
            if( method)
                ( method)->visit( this);
        }
	}

    virtual void visit(EnumNode* node){
        RETURN_IF_NODE_NULL;
    }

	virtual void visit(ProgramNode * node){
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
        for( auto iclassImpl = node->classImplementations.begin(); iclassImpl != node->classImplementations.end(); iclassImpl++){
			auto classImpl = *iclassImpl;
            (classImpl)->visit( this);
        }
        for( auto ienum = node->enums.begin(); ienum != node->enums.end(); ienum++){
			auto _enum = *ienum;
            (_enum)->visit( this);
        }
	}
	
    virtual void visit(Node*) {
        std::cout <<"!!!! visit default Node" << endl;
    }

};

void FunctionNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}
	
void FunctionParamNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}

void Node::visit(NodeVisiter* visiter) {
    visiter->visit(this);
}

void TypeNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}

void ExprNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}

void ExprListNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}
	
void ProgramNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}


void StatementNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}


void ClassDeclarationNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}


void ClassMethodDeclarationNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}


void ClassMethodParamNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}


void ClassFieldDeclarationNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}

void ClassImplementationNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}

void ClassMethodImplementationNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}

void MethodCallArgNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}

void EnumNode::visit(NodeVisiter* visiter){
    visiter->visit(this);
}







