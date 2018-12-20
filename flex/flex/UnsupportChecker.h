#include "NodeVisiter.h"

class UnsupportChecher : public NodeVisiter{
	void visit( ClassDeclarationNode* node) override {
		addError("Classes unsupported yet");
	}
	
	void visit( ClassImplementationNode* node) override {
		addError("Classes unsupported yet");
	}
	
	void visit( EnumNode* node) override {
		addError("Enums unsupported yet");
	}

	/*void visit( TypeNode* node) override {
		if( node->varType == TYPE_FLOAT)
			addError("Float unsupported yet");

		NodeVisiter::visit(node);
	}

	
	void visit( StatementNode* node) override {
		if( node->stmtType == STMT_VAR_DECL && node->varType->varType == TYPE_FLOAT)
			addError("Float unsupported yet");

		NodeVisiter::visit(node);
	}*/
};