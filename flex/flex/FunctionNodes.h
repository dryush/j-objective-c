#pragma once
#include "TreeClass.h"

/// <summary>
/// ��� ����������
/// </summary>
class FunctionParamNode : public Node {
public:
	TypeNode* type;
	string name;
	FunctionParamNode(Func_arg_st* st) {
		this->type = new TypeNode(st->val_type);
		this->name = name;
	}
};

class FunctionNode : public Node {
public:
	TypeNode* returnType;
	string name;
	StatementNode* body;
	list<FunctionParamNode*> params;


	FunctionNode(Func_impl_st* st) {
		this->name = st->name;
		this->returnType = new TypeNode(st->return_type);
		
		auto last = st->args;
		while (last) {
			this->params.push_back(new FunctionParamNode(last->arg));
			last = last->next;
		}
		this->body = new StatementNode(st->body);
	}
};