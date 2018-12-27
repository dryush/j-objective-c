#pragma once

#include "TableFiller.h"

class SuperChecker : public NodeVisiter {
	ClassImplementationNode* cc;
	void visit(ProgramNode * node) override {
		RETURN_IF_NODE_NULL;

		for (auto iclassImpl = node->classImplementations.begin(); iclassImpl != node->classImplementations.end(); iclassImpl++) {
			auto classImpl = *iclassImpl;
			cc = classImpl;
			(classImpl)->visit(this);
		}
	}

	void visit(ExprNode* node) override {

		if ( node->exprType == EXPR_METHOD_CALL) {
			if (node->object->operationType == OP_VALUE) {
				if (node->object->constType == TYPE_CUSTOM) {
					if (node->object->name == "base") {
						node->isSuper = true;
						node->object->name = "this";
						node->object->returnType = TypeInfo::Pointer(cc->name).toNode();
					}
				}
			}
		}

		NodeVisiter::visit(node);
	}
};


class ThisRetType : public NodeVisiter {
	ClassImplementationNode* cc;
	ClassMethodImplementationNode* m;
	void visit(ProgramNode * node) override {
		RETURN_IF_NODE_NULL;

		for (auto iclassImpl = node->classImplementations.begin(); iclassImpl != node->classImplementations.end(); iclassImpl++) {
			auto classImpl = *iclassImpl;
			cc = classImpl;
			(classImpl)->visit(this);
		}
	}

	void visit( ClassMethodImplementationNode* node){
		this->m = node;
		NodeVisiter::visit( node);
	}
	void visit(ExprNode* node) override {

		if (node->exprType == EXPR_OPERATION && node->operationType == OP_VALUE && node->constType == TYPE_CUSTOM && m->methodType == METHOD_LOCAL && node->name == "this") {
			node->returnType = TypeInfo::Pointer(cc->name).toNode();
		}
		NodeVisiter::visit(node);
	}
};

class ThisMethodCallChecker : public NodeVisiter {
public:

	ClassImplementationNode* cc;
	ClassMethodImplementationNode* m;
	void visit(ProgramNode * node) override {
		RETURN_IF_NODE_NULL;

		for (auto iclassImpl = node->classImplementations.begin(); iclassImpl != node->classImplementations.end(); iclassImpl++) {
			auto classImpl = *iclassImpl;
			cc = classImpl;
			(classImpl)->visit(this);
		}
	}

	void visit(ClassMethodImplementationNode* node) {
		m = node;
		VISIT_IF_NOT_NULL(node->body);

	}
	ExprNode* p;
	void visit(ExprNode* node) override {

		if (node->exprType == EXPR_FUNC_CALL) {
			if( !findFunction(node->name) && m->methodType == METHOD_LOCAL) {
				auto cl = getLocalMethod(cc->name, node->name);
				if (cl) {
					node->exprType = EXPR_METHOD_CALL;
					node->operationType = (OperationType) -1;
					node->constType = TYPE_CUSTOM;
					node->object = new ExprNode();
					node->object->exprType = EXPR_OPERATION;
					node->object->operationType = OP_VALUE;
					node->object->constType = TYPE_CUSTOM;
					node->object->name = "this";
					node->object->returnType = TypeInfo::Pointer(cc->name).toNode();
				}
			}
		}
		else if (node->exprType == EXPR_OPERATION && node->operationType == OP_VALUE && node->constType == TYPE_CUSTOM) {
			auto mm = getLocalMethod(cc->name, m->name);
			if (mm && !mm->getVar(node->name)) {
				auto cl = classes[cc->name];
				if( getField(cc->name, node->name)) {

					node->exprType = EXPR_INVAR_CALL;
					node->operationType = (OperationType)-1;
					node->constType = TYPE_CUSTOM;
					node->object = new ExprNode();
					node->object->exprType = EXPR_OPERATION;
					node->object->operationType = OP_VALUE;
					node->object->constType = TYPE_CUSTOM;
					node->object->name = "this";
					node->object->returnType = TypeInfo::Pointer(cc->name).toNode();
					
				};
			}
		}
		
		/*else if(node->exprType == EXPR_OPERATION && node->operationType == OP_ASSIGN && node->left->exprType == EXPR_OPERATION && node->left->operationType == OP_VALUE && node->left->constType == TYPE_CUSTOM)
		{
			auto mm = getLocalMethod(cc->name, m->name);
			if (mm && !mm->getVar(node->left->name)) {
				auto cl = classes[cc->name];
				if( getField(cc->name, node->left->name)) {

					node->exprType = EXPRE_CLASS_FIELD_ASSIGN;
					node->object = node->left;

					
                    node->name = node->left->name;
                    node->right = node->right;
					node->returnType = node->returnType;


					node->operationType = (OperationType)-1;
					node->constType = TYPE_CUSTOM;
					
					node->object = new ExprNode();
					node->object->exprType = EXPR_OPERATION;
					node->object->operationType = OP_VALUE;
					node->object->constType = TYPE_CUSTOM;
					node->object->name = "this";
					node->object->returnType = TypeInfo::Pointer(cc->name).toNode(); 
					
				};
			}
		}*/
		p = node;
		NodeVisiter::visit(node);
	}
};
