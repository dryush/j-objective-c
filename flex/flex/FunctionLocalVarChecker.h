#include "NodeVisiter.h"

/**
 *  Cheks for var eclration in first statment of function and methods
 * 
 */
class FunctionAndMethodsLocalVarChecker : protected NodeVisiter {

bool isMethod;
string funcName;
string methodName;
string className;

void genError( string& varName){
    string err = "Variable declaration in "
    if( isMethod){
        err += className + "." + methodName;
    } else {
        err += funcName + " (function)";
    }
    err += " varaible name: " + varName;
    
    addError(err);
}

public:

    void visit(StatementNode* node) override{
        RETURN_IF_NODE_NULL
        
        if( node->stmtType == STMT_ARRAY_DECL || node->stmtType == STMT_ARRAY_DECL ){
            this->genError( node->name);
        }
    }

    void visit( ClassMethodImplementationNode* node) override{
		RETURN_IF_NODE_NULL
        
        this->isMethod = true;
        this->methodName = node->name;


        // Must be always
        if( node->body->childs) {
            for( auto childStmt : node->body->childs){
                if( childStmt->childs){
                    for( auto childChildStmt : childStmt->child){
                        VISIT_IF_NOT_NULL(childChildStmt);
                    }
                }
            }
        }

		VISIT_IF_NOT_NULL( node->body);
	}

    void visit(FunctionNode* node) override {
		RETURN_IF_NODE_NULL
        
        this->isMethod = false;
        this->name = node->name;

        // Must be always
        if( node->body->childs) {
            for( auto childStmt : node->body->childs){
                if( childStmt->childs){
                    for( auto childChildStmt : childStmt->child){
                        VISIT_IF_NOT_NULL(childChildStmt);
                    }
                }
            }
        }
        
        //	VISIT_IF_NOT_NULL( childStmt);
        VISIT_IF_NOT_NULL( node->body);
	}

    void visit( ClassImplementationNode* node) override {
		RETURN_IF_NODE_NULL

        this->className = node->name;

		for( auto method : node)
			VISIT_IF_NOT_NULL( method);
	}

	void visit(ProgramNode * node) override {
		RETURN_IF_NODE_NULL
		
		for( auto func : node->functions)
			VISIT_IF_NOT_NULL(func);
		for( auto implDecl : node->classImplementations)
			VISIT_IF_NOT_NULL(implDecl);
	}

    
    void checkVarDecl(ProgramNode * prog) {
        VISIT_IF_NOT_NULL(prog);
    }
}
