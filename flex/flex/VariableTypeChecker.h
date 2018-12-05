#include "NodeVisiter.h"

class VariableTypeChecker : public NodeVisiter {

    bool isClass;
    string funcName;
    string className;

    void genError( string & varName){
        string err = "Variable \"" + varName + "\" is void in ";
        if( isClass) {
            err += "class " + className;
        } else {
            err += "function " + funcName + "()";
        }
    
        addError(err);
    }

public:

	void visit(FunctionNode* node) override {
		RETURN_IF_NODE_NULL
        
        this->isClass = false;
        this->funcName = node->name;

        // Must be always
        for( auto ichildStmt = node->body->childs.begin(); ichildStmt != node->body->childs.end(); ichildStmt++) {
            auto childStmt = *ichildStmt;
			if ( (childStmt->stmtType == STMT_ARRAY_DECL || childStmt->stmtType == STMT_VAR_DECL) 
				&& childStmt->varType->varType == TYPE_VOID) {
				this->genError( childStmt->name );
			}
        }
	}

	void visit(ClassFieldDeclarationNode* node) override {
		RETURN_IF_NODE_NULL;

		if (node->type->varType == TYPE_VOID)
			this->genError(node->name);
	}

	void visit(ClassDeclarationNode * node) override {
		RETURN_IF_NODE_NULL;
		this->isClass = true;
		this->className = node->name;

		for( auto ifield = node->fields.begin(); ifield != node->fields.end(); ifield++){
			auto field = *ifield;
            VISIT_IF_NOT_NULL(field);
        }
	}

	void visit(ProgramNode* node) override {
		RETURN_IF_NODE_NULL;
		
		for( auto ifunc = node->functions.begin(); ifunc != node->functions.end(); ifunc++){
			auto func = *ifunc;
            VISIT_IF_NOT_NULL(func);
        }
        for( auto iClassDecl = node->classDeclarations.begin(); iClassDecl != node->classDeclarations.end(); iClassDecl++){
			auto classDecl = *iClassDecl;
            VISIT_IF_NOT_NULL(classDecl);
        }
	}

};