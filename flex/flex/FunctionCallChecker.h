#include "TableFiller.h"

/**
* ��������� ����� �������, ���� ���������� � �� ���-��
*/
class FunctionCallChecker : public NodeVisiter {
public:
    void visit( FunctionNode* node){
        int stop = 2;
        stop = 2 + 2;
        NodeVisiter::visit( node);
    }

    void checkTypesAndCount(FunctionInfo* func, ExprNode* node){
        
            vector<MethodCallArgNode*>& existArgs = node->methodCallArgs;

            auto iExistArg = existArgs.begin(); 
            auto& params = func->paramsList;
            auto iParam = params.begin();
            int order = 0;
            for( ; iParam != params.end() && iExistArg != existArgs.end(); iParam++, iExistArg++){
                order++;
                if( !TypeCalculation::castIfPossible(*iExistArg,(*iParam)->type.toNode())) {
                    addError(string("Uncorrect arg type in function call: ") + node->name + "()" + " arg number: " + to_string( (ll)order)); 
                }
            }

            if( iParam != params.end() )
                addError(string("Not enought args in function call: ") + node->name + "()");
            else if( iExistArg != existArgs.end())
                addError(string("Too many args in function call: ") + node->name + "()");  

    }
    void visit( ExprNode* node) override {
        if( node->exprType == EXPR_FUNC_CALL) { 

            FunctionInfo* func = findFunction( node->name);
            this->checkTypesAndCount( func, node);
        } else if ( node->exprType == EXPR_METHOD_CALL ){
            
            MethodInfo* method; //******
            if( node->object->returnType->varType == TYPE_POINTER){
                method = getLocalMethod( node->object->returnType->childType->name, node->name);
            } else if ( node->object->returnType->varType == TYPEE_CLASS){
                method = getStaticMethod( node->object->returnType->name, node->name);
            }

            /// replace args
            if( node->methodCallArgs.size() > 1 && !node->methodCallArgs[1]->outerName.empty() ){
                vector< MethodCallArgNode*> replaced( node->methodCallArgs.size());
                for( int i = 1; i < node->methodCallArgs.size(); i++){
                    string outerName = node->methodCallArgs[i]->outerName;
                    auto iparam = method->outerParams.find( outerName) ;
                    if( iparam != method->outerParams.end()){
                        int realOrder = method->paramOrderNum[ iparam->second];
                        replaced[realOrder] = node->methodCallArgs[i]; 
                    } else {
                        addError("");
                    }
                }
                node->methodCallArgs = replaced;
            }
            
            this->checkTypesAndCount( method, node);
        
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
		} else if ( node->exprType == EXPRE_CLASS_FIELD_ASSIGN) {
			if( !TypeCalculation::castIfPossible( node->right, getField(node->object->returnType->childType->name, node->name)->type.toNode())){
				addError(string("Cant cast field"));
			}
		}

        NodeVisiter::visit( node);
    }
};
