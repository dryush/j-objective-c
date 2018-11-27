#pragma once
#include "FunctionNodes.h"
#include "ClassNodes.h"


class ProgramNode : public Node {
public:
	list<FunctionNode*> functions;
	list<ClassDeclarationNode*> classDeclarations;
	list<ClassImplementationNode*> classImplementations;

    void visit(NodeVisiter* visiter);

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

