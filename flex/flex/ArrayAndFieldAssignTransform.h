#include "NodeVisiter.h"

/**
 *  Cheks for var eclration in first statment of function and methods
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
                    newNode->object = node->left->left;
                    newNode->left = node->left->right;
                    newNode->right = node->right;
                    *node = *newNode;
                } else if ( node->left->exprType == EXPR_INVAR_CALL ){
                    auto newNode = new ExprNode();
                    newNode->exprType = EXPRE_CLASS_FIELD_ASSIGN;
                    newNode->object = node->left->object;
                    newNode->name = node->name;
                    newNode->right = node->right;
                    *node = *newNode;
                }
            }
        }
        NodeVisiter::visit(node);
	}

}