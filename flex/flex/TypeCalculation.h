#pragma once

#include "TableFiller.h"

//#define RETURN_IF_NODE_TYPE_EXIST node->

class TypeCalculation : public NodeVisiter {
    void visit( ExprNode* node) override {
        RETURN_IF_NODE_NULL;
        
        if ( node->returnType){
            return;
        }

        VISIT_IF_NOT_NULL( node->left);
        VISIT_IF_NOT_NULL( node->right);
        VISIT_IF_NOT_NULL( node->object);


        auto retType = new TypeNode();

        if( node->exprType == ExprType::EXPR_OPERATION) {
            
            if( node->operationType == OperationType::OP_VALUE) {
                if( node->constType == VarType::TYPE_CUSTOM)
            } else if ( node->isBinnaryMath()) {
                auto lefttype = node->left
            }

        }
    }

}