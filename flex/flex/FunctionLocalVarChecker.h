#include "NodeVisiter.h"

/**
 *  Cheks for var eclration in first statment of function and methods
 * 
 */
class FunctionAndMethodsLocalVarChecker : public NodeVisiter {

    bool isMethod;
    string funcName;
    string methodName;
    string className;

    void genError( string& varName){
        string err = "Variable declaration in ";
        if( isMethod){
            err += className + "." + methodName;
        } else {
            err += funcName + " (function)";
        }
        err += " variable name: " + varName;
    
        addError(err);
    }

public:

    void visit(StatementNode* node) override {
        RETURN_IF_NODE_NULL
        
        if( node->stmtType == STMT_ARRAY_DECL || node->stmtType == STMT_VAR_DECL){
            this->genError( node->name);
        }
    }

    void visit( ClassMethodImplementationNode* node) override {
		RETURN_IF_NODE_NULL
        
        this->isMethod = true;
        this->methodName = node->name;


        // Must be always
        for( auto ichildStmt = node->body->childs.begin(); ichildStmt != node->body->childs.end(); ichildStmt++){
            auto childStmt = *ichildStmt;
            for( auto ichildChildStmt = childStmt->childs.begin(); ichildChildStmt != childStmt->childs.end(); ichildChildStmt++){
                auto childChildStmt = *ichildChildStmt;
                VISIT_IF_NOT_NULL(childChildStmt);
            }
        }
	}

    void visit(FunctionNode* node) override {
		RETURN_IF_NODE_NULL
        
        this->isMethod = false;
        this->funcName = node->name;

        // Must be always
        for( auto ichildStmt = node->body->childs.begin(); ichildStmt != node->body->childs.end(); ichildStmt++) {
            auto childStmt = *ichildStmt;
            for( auto ichildChildStmt = childStmt->childs.begin(); ichildChildStmt != childStmt->childs.end(); ichildChildStmt++) {
                auto childChildStmt = *ichildChildStmt;
                VISIT_IF_NOT_NULL(childChildStmt);
            }
        }
        
        //	VISIT_IF_NOT_NULL( childStmt);
        //VISIT_IF_NOT_NULL( node->body);
	}

    void visit( ClassImplementationNode* node) override {
		RETURN_IF_NODE_NULL

        this->className = node->name;

        for( auto imethod = node->methods.begin(); imethod != node->methods.end(); imethod++){
			auto method = *imethod;
            VISIT_IF_NOT_NULL( method);
        }
	}

	void visit(ProgramNode* node) override {
		RETURN_IF_NODE_NULL;
		
		for( auto ifunc = node->functions.begin(); ifunc != node->functions.end(); ifunc++){
			auto func = *ifunc;
            VISIT_IF_NOT_NULL(func);
        }
        for( auto iimplDecl = node->classImplementations.begin(); iimplDecl != node->classImplementations.end(); iimplDecl++){
			auto implDecl = *iimplDecl;
            VISIT_IF_NOT_NULL(implDecl);
        }
	}

    
    void checkVarDecl(ProgramNode * prog) {
        VISIT_IF_NOT_NULL(prog);
    }
};
