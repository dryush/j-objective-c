#pragma once
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

    vector<JVMCommand> commands;
    
public:
    unsigned short getLocalVarsCount(){
        return this->localVarsCount;
    }

    void visit( StatementNode* node) override {
        if( node->stmtType == STMT_COMPOUND) {
			for (auto ichildStmt = node->childs.begin(); ichildStmt != node->childs.end(); ichildStmt++)
			{
				 auto childStmt = *ichildStmt;
				 childStmt->visit(this);
			}
        } else if( node->stmtType == STMT_ARRAY_DECL) {

        } else if( node->stmtType == STMT_VAR_DECL) {
            
        } else if( node->stmtType == STMT_EXPR) {
            node->expr->visit( this);
        } else if( node->stmtType == STMT_IF) {
			node->condition->visit(this);
			node->truthStmt->visit(this);
			node->wrongStmt->visit(this);
        } else if( node->stmtType == STMT_RETURN) {

        } else if( node->stmtType == STMT_WHILE) {
			node->condition->visit(this);
			node->truthStmt->visit(this);
        }
    }

    void visit( ExprNode* node) override {
        if( node->exprType == EXPR_OPERATION) {
            if( node->operationType == OP_VALUE) {
                if( node->returnType->varType == VarType::TYPE_INT) {
                    commands.push_back( LDC_W(2)); 
                }
            } else if( node->operationType == OP_ADD) {
				node->left->visit(this);
				node->right->visit(this);
				commands.push_back( IADD());
			}  else if( node->operationType == OP_SUB) {
				node->left->visit(this);
				node->right->visit(this);
                commands.push_back( ISUB());
			} else if( node->operationType == OP_MUL) {
				node->left->visit(this);
				node->right->visit(this);
                commands.push_back( IMUL());
            } else if( node->operationType == OP_DIV) {
				node->left->visit(this);
				node->right->visit(this);
                commands.push_back( IDIV());
            } else if( node->operationType == OP_MOD) {
				node->left->visit(this);
				node->right->visit(this);
                // a % b === a - (c * b), где c = a / b - целая часть деления
				commands.push_back( IDIV());
				commands.push_back( IMUL());
				commands.push_back( ISUB());
			} else if( node->operationType == OP_ASSIGN) {
                node->right->visit(this);
				// передать номер левой переменной
				commands.push_back( ISTORE());
            } else if( node->operationType == OP_ASSIGN_ARRAY) { // тут наверное ещё что-то нужно
                node->right->visit(this);
				// передать номер левой переменной
				commands.push_back( ISTORE());
            } else if( node->operationType == OP_LESS) {
                
            } else if( node->operationType == OP_LESS_OR_EQUAL) {
                
            } else if( node->operationType == OP_GREATER) {
                
            } else if( node->operationType == OP_GREATER_OR_EQUAL) {
                
            } else if( node->operationType == OP_EQUAL) {
                
            } else if( node->operationType == OP_NOT_EQUAL) {
                
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
            methodCode += com->toBytes();
        }
        return methodCode;
    }
    
};