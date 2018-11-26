#pragma once
#include "TreeClass.h"
#include "FunctionNodes.h"
class ExternCode : public Node {

};

class ProgramNode : public Node {
public:
	list<FunctionNode*> functions;
	list<ClassDeclarationNode*> classDeclarations;
	list<ClassImplementationNode*> classImplementations;
	ProgramNode(Program_st* st) {
		auto last = st;
		while (last) {
			if (last->code->func_impl) {
				FunctionNode* func = new FunctionNode(st->code->func_impl);
				functions.push_back(func);
			}
			last = last->next;
		}
	}
};

