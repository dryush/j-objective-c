#include "NodeVisiter.h"

/**
 *  
 * 
 */
class ArrayAndFieldAssignTransform : public NodeVisiter {
public:
    void visit( ExprNode* node) override {
		RETURN_IF_NODE_NULL;
        if( node->exprType == EXPR_OPERATION){
            if( node->operationType == OP_ASSIGN ){
                if ( node->left->exprType == EXPR_ARRAY_ELEM_CALL ){
                    auto newNode = new ExprNode();
                    newNode->exprType = EXPRE_ARRAY_ELEM_ASSIGN;
                    newNode->object = node->left->left; //МАССИВ
                    newNode->left = node->left->right; //индекс
                    newNode->right = node->right; //Присваиваемое значение
                    *node = *newNode;
                } else if ( node->left->exprType == EXPR_INVAR_CALL ){
                    auto newNode = new ExprNode();
                    newNode->exprType = EXPRE_CLASS_FIELD_ASSIGN;
                    newNode->object = node->left->object;
                    newNode->name = node->left->name;
                    newNode->right = node->right;
					newNode->returnType = node->returnType;
                    *node = *newNode;
                }
            }
        }
        NodeVisiter::visit(node);
	}

};