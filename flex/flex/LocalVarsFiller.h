#include "TableFiller.h"

class LocalVarsFiller : NodeVisiter {

public:

    void visit( ClassDeclarationNode* node) override {
        return;
    }

    void visit( EnumNode* node) override {
        return;
    }

    ClassImplementationNode* currentClass;
    void visit( ClassImplementationNode* node) override {
        this->currentClass = node;
        FOR_EACH( imethod, node->methods) {
            VISIT_IF_NOT_NULL( (*imethod));
        }
    }

    MethodInfo* currentMethod;
    void visit( ClassMethodImplementationNode* node) override{
        auto body = node->body->childs.front();
        currentMethod = classes[ currentClass->name]->localMethods[ node->name];
        FOR_EACH( istmt, body->childs){
            auto stmt = *istmt;
            
        }
    }

    void visit( ExprNode* expr) override {
        if( expr->exprType == EXPR_FUNC_CALL) {
            auto func = functions.find( expr->name); 
            if( func == functions.end()) {
                addError(string("Unknown function: ") + expr->name); 
            } else {
                if( expr->funcArgs->exprs.size() != func->second->params.size()){
                    addError(string("Expected ") + to_string((long long)func->second->params.size()) + " args in Function call: " + func->second->name );
                }
                auto iparam = func->second->params.begin();
                auto iarg = expr->funcArgs->exprs.begin();
                int num = 1;
                for( ; iparam != func->second->params.end(); iparam++, iarg++, num++){
                    auto arg = *iarg;
                    if( !iparam->second->type.isEqual( arg->returnType)) {
                        addError(string("Unexpected Type in Function call: ") +  func->second->name + "at position "+ to_string((long long) num));
                    }
                }
            }
        }

    }
}