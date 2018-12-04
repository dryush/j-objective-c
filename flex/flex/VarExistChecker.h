#pragma once

#include "TableFiller.h"

class ExpressionTypeChecker : public NodeVisiter {
public:

    bool isStaticMethodExist( string& classname, string&methodname){
        bool isExist = false;
        auto existclass = classes.find(classname);
        isExist = existclass != classes.end();
        if( isExist){
            isExist = existclass->second;
            if( isExist){
                isExist = existclass->second->staticMethods.find(methodname) 
                    != existclass->second->staticMethods.end();
            }
        }
        return isExist;
    }

    void visit( ExprNode* node) override {
        RETURN_IF_NODE_NULL;

       // if( node->exprType == E

         
    }
};