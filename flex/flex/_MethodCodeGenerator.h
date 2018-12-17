#pragma once
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
    
    JavaConstantTable* table;

    void genCode( FunctionInfo* info){
        


        localVarsCount = 0;
        localVarsCount += info->params.size();
		localVars.clear();
		localVars = info->localVars;
		localVarsNumber.clear();
		//localVarsNumber = info->localVarsNumber;

        info->functionNode->body->visit(this);
    }

    void genCode( MethodInfo* info){
        if( info->methodType == METHOD_LOCAL)
            localVarsCount = 1;
        else localVarsCount = 0;
		localVars.clear();
		localVars = info->localVars;
		localVarsNumber.clear();
		//localVarsNumber = info->localVarsNumber;

        //localVarsCount += info->params.size();
    }

    

public:
    unsigned short getLocalVarsCount(){
        //return this->localVarsCount;
        return this->localVarsNumber.size(); 
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
            this->localVarsNumber[ node->name] = localVars.size();

        } else if( node->stmtType == STMT_EXPR) {
            node->expr->visit( this);
        } else if( node->stmtType == STMT_IF) {
			node->condition->visit(this);
			node->truthStmt->visit(this);
			node->wrongStmt->visit(this);
        } else if( node->stmtType == STMT_RETURN) {
			node->expr->visit(this);	
			commands.push_back( new IRETURN()); 
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
            if ( node->object->returnType->varType == TYPEE_CLASS) {
                if ( node->isAlloc) {
                    int classid = table->classByMethod[ node->constantNum];
                    commands.push_back( new NEW( classid));
                    commands.push_back( new DUP());
                    commands.push_back( new INVOKE_SPECIAL( table->constructors[node->object->returnType->name]));
                }
                else {
                    commands.push_back( new INVOKE_STATIC( node->constantNum));
                }
            } else if ( node->object->returnType->varType == TYPE_POINTER) {
                VISIT_IF_NOT_NULL( node->object);
                
                FOR_EACH( methodNode, node->methodCallArgs){
                    VISIT_IF_NOT_NULL( (*methodNode));
                }



                commands.push_back( new INVOKE_VIRTUAL( node->constantNum));
            } else throw new runtime_error( "method call from not object (code gen)");
        }
        else if ( node->exprType == EXPR_OPERATION) {
            if( node->operationType == OP_VALUE) {
				if (node->constType == TYPE_CUSTOM) {
					VarType type = localVars[node->name].type;
					int number = localVarsNumber[node->name];
					if ( type == TYPE_INT) {
						commands.push_back( new ILOAD(number));
					}
				} else if (node->constType == TYPE_INT) {
					commands.push_back( new IConst(node->intVal));
				}
                
            } else if( node->operationType == OP_ADD) {
				node->left->visit(this);
				node->right->visit(this);
				commands.push_back( new IADD());
			}  else if( node->operationType == OP_SUB) {
				node->left->visit(this);
				node->right->visit(this);
                commands.push_back( new ISUB());
			} else if( node->operationType == OP_MUL) {
				node->left->visit(this);
				node->right->visit(this);
                commands.push_back( new IMUL());
            } else if( node->operationType == OP_DIV) {
				node->left->visit(this);
				node->right->visit(this);
                commands.push_back( new IDIV());
            } else if( node->operationType == OP_MOD) {
				node->left->visit(this);
				node->right->visit(this);
                // a % b === a - (c * b), ��� c = a / b - ����� ����� �����
				commands.push_back( new IDIV());
				commands.push_back( new IMUL());
				commands.push_back( new ISUB());
			} else if( node->operationType == OP_ASSIGN) {
                node->right->visit(this);
				int number = localVarsNumber[node->left->name];
				commands.push_back( new ISTORE(number));
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
				node->left->visit(this);
				node->right->visit(this);
				int shift = 0;
				commands.push_back( new IF_ICMP(node->operationType, shift));
            } else if( node->operationType == OP_LOGICAL_NOT) {
                
            } else if( node->operationType == OP_AND) {
                
            } else if( node->operationType == OP_OR) {
                
            } else if( node->operationType == OP_UPLUS) {
                node->left->visit(this);
            } else if( node->operationType == OP_UMINUS) {
                commands.push_back( new IConst(-1));
				node->left->visit(this);
				commands.push_back( new IMUL());
            } 
        }
    }


    string genCode( JavaMethodTableRecord& method, JavaConstantTable* table){
            
        this->table = table;
        if ( method.methodInfo)
            this->genCode( method.methodInfo);
        else 
            if( method.funcInfo->isDefault){}
            else this->genCode( method.funcInfo);
        string methodCode;
        FOR_EACH( com, commands){
            methodCode += (*com)->toBytes();
        }
        return methodCode;
    }
    
};