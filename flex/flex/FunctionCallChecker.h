#include "TableFiller.h"

/**
* Проверяет вызов функций, типы аргумметов и их кол-во
*/
class FunctionCallChecker : public NodeVisiter {

    void visit( ExprNode* node) override {
        if( node->exprType == EXPR_FUNC_CALL) {

            list<ExprNode*>& existArgs = node->funcArgs->exprs; 
            auto iExistArg = existArgs.begin(); 
            auto& params = functions[ node->name]->params;
            auto iParam = params.begin();
            int order = 0;
            for( ; iParam != params.end() && iExistArg != existArgs.end(); iParam++, iExistArg++){
                order++;
                if( !TypeCalculation::castIfPossible(*iExistArg, iParam->second->type.toNode())) {
                    addError(string("Uncorrect arg type in function call: ") + node->name + "()" + " arg number: " + to_string( order)); 
                }
            }

            if( iParam != params.end() )
                addError(string("Too many args in function call: ") + node->name + "()");
            else if( iExistArg != existArgs.end()) 
                addError(string("Not enought args in function call: ") + node->name + "()"); 

        }
    }
};
