#pragma once
#include <string>
#include <vector>
#include "TableFiller.h"

#include "_JVMCommands.h"

class MethodCodeGenerator : public NodeVisiter {
    
    unsigned short localVarsCount;
    string code;
    
    void genCode( FunctionInfo* info){
        localVarsCount = 0;
        localVarsCount += info->params.size();
        info->functionNode->body->visit(this);
    }

    void genCode( MethodInfo* info){
        if( info->methodType == METHOD_LOCAL)
            localVarsCount = 1;
        else localVarsCount = 0;
        localVarsCount += info->params.size();
    }

    vector<JVMCommand*> commands;
    
public:
    unsigned short getLocalVarsCount(){
        return this->localVarsCount;
    }

    void visit( StatementNode* node) override {
        if( node->stmtType == STMT_COMPOUND) {

        } else if( node->stmtType == STMT_ARRAY_DECL) {

        } else if( node->stmtType == STMT_EXPR) {
            node->expr->visit( this);
        } else if( node->stmtType == STMT_IF) {

        } else if( node->stmtType == STMT_RETURN) {

        } else if( node->stmtType == STMT_VAR_DECL) {
            
        } else if( node->stmtType == STMT_WHILE) {

        }
    }

    void visit( ExprNode* node) override {
        if( node->exprType == EXPR_OPERATION) {
            if( node->operationType == OP_VALUE) {
                if( node->returnType->varType == VarType::TYPE_INT) {
                    commands.push_back( new LDC_W(2)); 
                }
            } else if( node->operationType == OP_ADD) {
                commands.push_back( new IADD());
            }
        }
    }


    string genCode( JavaMethodTableRecord& method){
            
        
        if ( method.methodInfo)
            this->genCode( method.methodInfo);
        else 
            this->genCode( method.funcInfo);
        string methodCode;
        FOR_EACH( com, commands){
            methodCode += (*com)->toBytes();
        }
        return methodCode;
    }
    
};