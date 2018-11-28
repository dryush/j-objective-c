#pragma once
#include "FunctionNodes.h"
#include "ClassNodes.h"


class ProgramNode : public Node {
public:
	list<FunctionNode*> functions;
	list<ClassDeclarationNode*> classDeclarations;
	list<ClassImplementationNode*> classImplementations;
	list<EnumNode*> enums;

    void visit(NodeVisiter* visiter);

    ProgramNode(Program_st* st) {
		auto last = st;
		while (last) {
			if (last->code->func_impl) {
				FunctionNode* func = new FunctionNode(last->code->func_impl);
				functions.push_back(func);
			}
			else if (last->code->class_decl) {
				ClassDeclarationNode* decl = new ClassDeclarationNode(last->code->class_decl);
				classDeclarations.push_back(decl);
			}
			else if (last->code->class_impl) {
				ClassImplementationNode* impl = new ClassImplementationNode(last->code->class_impl);
				classImplementations.push_back(impl);
			}
			else if (last->code->enum_decl){
				this->enums.push_back( new EnumNode(last->code->enum_decl));
			}
			last = last->next;
		}
	}
};

