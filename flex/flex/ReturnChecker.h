#include "NodeVisiter.h"

class ReturnChecker : public NodeVisiter {

    bool isClass;
    string funcName;
    string className;
	string methodName;

    void genError(){
        
		string err = "";
        if( isClass) {
            err += "Method " + methodName + " in class " + className;
        } else {
            err += "Function " + funcName + "()";
        }
		err += " don't have return value";
        addError(err);
    }

public:

	void visit(FunctionNode* node) override {
		RETURN_IF_NODE_NULL
        
        this->isClass = false;
        this->funcName = node->name;
		bool isOk = false;
        // Must be always
        for( auto ichildStmt = node->body->childs.begin(); ichildStmt != node->body->childs.end(); ichildStmt++) {
            auto childStmt = *ichildStmt;
			if (childStmt->stmtType == STMT_RETURN) {
				isOk = true;
				break;
			}
        }
		if (isOk == false) {
			this->genError();
		}
	}

	void visit(ClassMethodImplementationNode* node) override {
		RETURN_IF_NODE_NULL;
		
		if (node->returnType->varType != TYPE_VOID) {
			bool isOk = false;
			for( auto ichildStmt = node->body->childs.begin(); ichildStmt != node->body->childs.end(); ichildStmt++) {
				auto childStmt = *ichildStmt;
				if (childStmt->stmtType == STMT_RETURN)  {
					isOk = true;
					break;
				}
			}
			if (isOk == false) {
				this->methodName = node->name;
				this->genError();
			}
		}	
	}

	void visit(ClassImplementationNode * node) override {
		RETURN_IF_NODE_NULL;
		this->isClass = true;
		this->className = node->name;

		for( auto imethod = node->methods.begin(); imethod != node->methods.end(); imethod++){
			auto method = *imethod;
            VISIT_IF_NOT_NULL(method);
        }
	}

	void visit(ProgramNode* node) override {
		RETURN_IF_NODE_NULL;
		
		for( auto ifunc = node->functions.begin(); ifunc != node->functions.end(); ifunc++){
			auto func = *ifunc;
			if (func->returnType->varType != TYPE_VOID)
				VISIT_IF_NOT_NULL(func);
        }
        for( auto iClassImpl = node->classImplementations.begin(); iClassImpl != node->classImplementations.end(); iClassImpl++){
			auto classImpl = *iClassImpl;
            VISIT_IF_NOT_NULL(classImpl);
        }
	}

};