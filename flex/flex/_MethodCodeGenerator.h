﻿#pragma once
#include <string>
#include <vector>
#include "TableFiller.h"

#include "_JVMCommands.h"

class MethodCodeGenerator : public NodeVisiter {
    
    unsigned short localVarsCount;
    string code;
    vector<JVMCommand*> commands;
    unordered_map<string, TypeInfo> localVars;
    unordered_map<string, int> localVarsNumber;
	FunctionInfo* info;
	int numberCurrentRow;

    void genCode( FunctionInfo* info){
        localVarsCount = 0;
        localVarsCount += info->params.size();
		localVars.clear();
		localVars = info->localVars;
		localVarsNumber.clear();
		localVarsNumber = info->localVarsNumber;
		numberCurrentRow = 0;
		this->info = info;
		if (info->functionNode->body != NULL)
			info->functionNode->body->visit(this);
    }

    void genCode( MethodInfo* info){
        if( info->methodType == METHOD_LOCAL)
            localVarsCount = 1;
        else localVarsCount = 0;
		localVars.clear();
		localVars = info->localVars;
		localVarsNumber.clear();
		localVarsNumber = info->localVarsNumber;

        localVarsCount += info->params.size();
    }

    void addCommand(JVMCommand* command) {
		numberCurrentRow += command->toBytes().size();
		commands.push_back( command );
	}

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

			node->condition->left->visit(this);
			node->condition->right->visit(this);

			int ifLine = numberCurrentRow;
			int numberIfCommand = commands.size();
			addCommand( new IF_ICMP(node->condition->operationType, 0));

			node->truthStmt->visit(this);

			int shift = numberCurrentRow - ifLine;
			commands[numberIfCommand] = new IF_ICMP(node->condition->operationType, shift);

			int gotoLine = numberCurrentRow;
			int numberGotoCommand = commands.size();
			addCommand( new GOTO(0));

			node->wrongStmt->visit(this);

			shift = numberCurrentRow - gotoLine;
			commands[numberGotoCommand] = new GOTO(shift);
			
        } else if( node->stmtType == STMT_RETURN) {
			VISIT_IF_NOT_NULL(node->expr);
			if (info->returnType.type == TYPE_VOID)
				addCommand( new VRETURN());
			else
				addCommand( new IRETURN());
        } else if( node->stmtType == STMT_WHILE) {
			node->condition->visit(this);
			node->truthStmt->visit(this);
        }
    }

    void visit( ExprNode* node) override {
        if ( node->exprType == EXPR_ARRAY_ELEM_CALL) {
            //if( node->returnType->childType->varType == TYPE_POINTER) throw new runtime_error(" array of objects unsupported yet");
        }
        else if ( node->exprType == EXPR_FUNC_CALL) {
            commands.push_back( new INVOKE_STATIC( node->constantNum));
        }
        else if ( node->exprType == EXPR_INVAR_CALL) {

        }
        else if ( node->exprType == EXPR_METHOD_CALL) {
            FOR_EACH( methodNode, node->methodCallArgs){
                VISIT_IF_NOT_NULL( (*methodNode));
            }
            if ( node->object->returnType->varType = TYPEE_CLASS) {
                commands.push_back( new INVOKE_STATIC( node->constantNum));
            } else if ( node->object->returnType->varType = TYPE_POINTER) {
                commands.push_back( new INVOKE_VIRTUAL( node->constantNum));
            } else throw new runtime_error( "method call from not object (code gen)");
        }
        else if ( node->exprType == EXPR_OPERATION) {
            if( node->operationType == OP_VALUE) {
				if (node->constType == TYPE_CUSTOM) {
					VarType type = localVars[node->name].type;
					int number = localVarsNumber[node->name];
					if ( type == TYPE_INT) {
						addCommand( new ILOAD(number));
					}
				} else if (node->constType == TYPE_INT) {
					addCommand( new IConst(node->intVal));
				}
                
            } else if( node->operationType == OP_ADD) {
				node->left->visit(this);
				node->right->visit(this);
				addCommand( new IADD());
			}  else if( node->operationType == OP_SUB) {
				node->left->visit(this);
				node->right->visit(this);
				addCommand( new ISUB());
			} else if( node->operationType == OP_MUL) {
				node->left->visit(this);
				node->right->visit(this);
                addCommand( new IMUL());
            } else if( node->operationType == OP_DIV) {
				node->left->visit(this);
				node->right->visit(this);
                addCommand( new IDIV());
            } else if( node->operationType == OP_MOD) {
				node->left->visit(this);
				node->right->visit(this);
                // a % b === a - (c * b), ��� c = a / b - ����� ����� �����
				addCommand( new IDIV());
				addCommand( new IMUL());
				addCommand( new ISUB());
			} else if( node->operationType == OP_ASSIGN) {
                node->right->visit(this);
				int number = localVarsNumber[node->left->name];
				addCommand( new ISTORE(number));
            } else if( node->operationType == OP_ASSIGN_ARRAY) {
                // �������� ���-�� ��� �������� �����
				node->right->visit(this);
				// ���� ������� ����� ����� ����������
				//commands.push_back( new ISTORE());
            } else if( node->operationType == OP_LESS || 
						node->operationType == OP_LESS_OR_EQUAL ||
						node->operationType == OP_GREATER ||
						node->operationType == OP_GREATER_OR_EQUAL ||
						node->operationType == OP_EQUAL ||
						node->operationType == OP_NOT_EQUAL )
			{
				/*node->left->visit(this);
				node->right->visit(this);*/
            } else if( node->operationType == OP_LOGICAL_NOT) {
                
            } else if( node->operationType == OP_AND) {
                
            } else if( node->operationType == OP_OR) {
                
            } else if( node->operationType == OP_UPLUS) {
                node->left->visit(this);
            } else if( node->operationType == OP_UMINUS) {
                addCommand( new IConst(-1));
				node->left->visit(this);
				addCommand( new IMUL());
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