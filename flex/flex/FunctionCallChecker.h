#include "TableFiller.h"

/**
* ��������� ����� �������, ���� ���������� � �� ���-��
*/
class FunctionCallChecker : public NodeVisiter {
public:
    void checkTypesAndCount(FunctionInfo* func){
            list<MethodCallArgNode*>& existArgs = node->methodCallArgs; 
            auto iExistArg = existArgs.begin(); 
            auto& params = func->params;
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
    void visit( ExprNode* node) override {
        if( node->exprType == EXPR_FUNC_CALL) {

            FunctionInfo* func = findFunction( node->name);
            this->checkTypesAndCount( func);
        } else if ( node->exprType == EXPR_METHOD_CALL ){
            MethodInfo* method; //******
            /// replace args
            this->checkTypesAndCount( method);
        }
        } else if ( node->exprType == EXPR_ARRAY_ELEM_CALL) {
            auto inttypenode = new TypeNode();
            inttypenode->varType = TYPE_INT;
            if( ! TypeCalculation::castIfPossible( node->right, inttypenode)){
                addError(string("Index must be int array elem call: ") + node->left->name);
            }
        } else if ( node->exprType == EXPRE_ARRAY_ELEM_ASSIGN) {
            auto inttypenode = new TypeNode();
            inttypenode->varType = TYPE_INT;
            if( ! TypeCalculation::castIfPossible( node->left, inttypenode)){
                addError(string("Index must be int array elem call: ") + node->left->name);
            }
        }
    }
};
