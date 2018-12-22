#pragma once
#include <string>
#include <vector>
#include "TableFiller.h"

#include "_JVMCommands.h"

class MethodCodeGenerator : public NodeVisiter {
    
    string code;
    vector<JVMCommand*> commands;
    unordered_map<string, TypeInfo> localVars;
    unordered_map<string, int> localVarsNumber;

    
    void addVar( const string& name, TypeInfo& type){
        this->localVars[name] = type;
        this->localVarsNumber[name] = this->localVarsNumber.size();
    }

    int getVarNumber(const string& varname){
        return this->localVarsNumber[ varname];
    }

    TypeInfo getVarType( const string& varname){
        return this->localVars[ varname];
    }
    
    
    JavaConstantTable* table;
    FunctionInfo* info;
	int numberCurrentRow;

    void startGen( FunctionInfo* inf){
        this->info = inf;

        FOR_EACH( p, inf->paramsList){
            addVar((*p)->name, (*p)->type);
        }
    }

    void genCode( FunctionInfo* info){
        
        startGen( info);

		if (info->functionNode->body != NULL)
			info->functionNode->body->visit(this);
    }

    void genCode( MethodInfo* info){

        startGen( info);

        if( info->methodType == METHOD_LOCAL)
            addVar("this", TypeInfo::Pointer(info->classname));
        
    }

    void addCommand(JVMCommand* command) {
		numberCurrentRow += command->toBytes().size();
		commands.push_back( command );
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
            addVar( node->name, TypeInfo( node->varType));

        } else if( node->stmtType == STMT_VAR_DECL) {
            addVar( node->name, TypeInfo( node->varType));

        } else if( node->stmtType == STMT_EXPR) {
            node->expr->visit( this);
        } else if( node->stmtType == STMT_IF) {

			node->condition->visit(this);

			int ifLine = numberCurrentRow;
			int numberIfCommand = commands.size();
			addCommand( new IF_0(OP_NOT_EQUAL, 0, false));

			node->truthStmt->visit(this);

			int gotoLine = 0;
			int numberGotoCommand = 0;
			if (node->wrongStmt != NULL) {
				gotoLine = numberCurrentRow;
				numberGotoCommand = commands.size();
				addCommand( new GOTO(0));
			}
			
			int shift = numberCurrentRow - ifLine;
			commands[numberIfCommand] = new IF_0(OP_NOT_EQUAL, shift, false);

			if (node->wrongStmt != NULL) {
				node->wrongStmt->visit(this);

				shift = numberCurrentRow - gotoLine;
				commands[numberGotoCommand] = new GOTO(shift);
			}
			
        } else if( node->stmtType == STMT_RETURN) {
            VISIT_IF_NOT_NULL(node->expr);	
			
            if ( info->returnType.type == TYPE_VOID)
                addCommand( new VRETURN());
			else if (info->returnType.type == TYPE_INT)
                addCommand( new IRETURN());
			else if (info->returnType.type == TYPE_FLOAT)
                addCommand( new FRETURN());
            else if ( info->returnType.type == TYPE_POINTER)
                addCommand( new ARETURN());
            
        } else if( node->stmtType == STMT_WHILE) {
			
			int gotoLine = numberCurrentRow;
			int numberGotoCommand = commands.size();
			addCommand( new GOTO(0));

			node->truthStmt->visit(this);

			int shift = numberCurrentRow - gotoLine;
			commands[numberGotoCommand] = (new GOTO(shift));

			node->condition->visit(this);

			shift = gotoLine + 3 - numberCurrentRow;
			addCommand( new IF_0(OP_NOT_EQUAL, shift, true));
        }
    }

	void calcBinaryComp(ExprNode *node) {
		VarType leftType = node->left->returnType->varType;
		VarType rightType = node->right->returnType->varType;
		
		if (leftType == TYPE_INT && rightType == TYPE_INT) {
			node->left->visit(this);
			node->right->visit(this);

			int ifLine = numberCurrentRow;
			int numberIfCommand = commands.size();
			addCommand( new IF_ICMP(node->operationType, 0, false));
			addCommand( new SIPush(1));
			int gotoLine = numberCurrentRow;
			int numberGotoCommand = commands.size();
			addCommand( new GOTO(0));
			int shift = numberCurrentRow - ifLine;
			commands[numberIfCommand] = new IF_ICMP(node->operationType, shift, false);
			addCommand( new SIPush(0));
			shift = numberCurrentRow - gotoLine;
			commands[numberGotoCommand] = new GOTO(shift);
		}
		else if (leftType == TYPE_FLOAT || rightType == TYPE_FLOAT) {
			node->left->visit(this);
			if (leftType == TYPE_INT)
				addCommand( new I2F());

			node->right->visit(this);
			if (rightType == TYPE_INT)
				addCommand( new I2F());
				
			addCommand( new FCMP(OP_GREATER));

			int ifLine = numberCurrentRow;
			int numberIfCommand = commands.size();
			addCommand( new IF_0(node->operationType, 0, false));
			addCommand( new SIPush(1));
			int gotoLine = numberCurrentRow;
			int numberGotoCommand = commands.size();
			addCommand( new GOTO(0));
			int shift = numberCurrentRow - ifLine;
			commands[numberIfCommand] = new IF_0(node->operationType, shift, false);
			addCommand( new SIPush(0));
			shift = numberCurrentRow - gotoLine;
			commands[numberGotoCommand] = new GOTO(shift);
		}
	}

	void calcUnaryMath(ExprNode *node) {
		
		if( node->operationType == OP_UPLUS) {
			node->left->visit(this);
		} 
		else if( node->operationType == OP_UMINUS) {
			node->left->visit(this);
			addCommand( new SIPush(-1));
			if (node->left->returnType->varType == TYPE_FLOAT) {
				addCommand( new I2F());
				addCommand( new FMUL());
			}
			else
				addCommand( new IMUL());
		} 
	}

	void calcBinaryMath(ExprNode *node) {
		VarType returnType = node->returnType->varType;
		VarType leftType = node->left->returnType->varType;
		VarType rightType = node->right->returnType->varType;

		node->left->visit(this);

		if (returnType == TYPE_FLOAT && leftType == TYPE_INT) {
			addCommand( new I2F());
		}

		node->right->visit(this);

		if (returnType == TYPE_FLOAT && rightType == TYPE_INT) {
			addCommand( new I2F());
		}

		if( node->operationType == OP_ADD) {
				
			if (node->returnType->varType == TYPE_INT)
				addCommand( new IADD());
			else if (node->returnType->varType == TYPE_FLOAT)
				addCommand( new FADD());

		}  else if( node->operationType == OP_SUB) {
			
			if (node->returnType->varType == TYPE_INT)
				addCommand( new ISUB());
			else if (node->returnType->varType == TYPE_FLOAT)
				addCommand( new FSUB());

		} else if( node->operationType == OP_MUL) {
			
            if (node->returnType->varType == TYPE_INT)
				addCommand( new IMUL());
			else if (node->returnType->varType == TYPE_FLOAT)
				addCommand( new FMUL());

        } else if( node->operationType == OP_DIV) {
			
            if (node->returnType->varType == TYPE_INT)
				addCommand( new IDIV());
			else if (node->returnType->varType == TYPE_FLOAT)
				addCommand( new FDIV());

        } else if( node->operationType == OP_MOD) {
			
			if (node->returnType->varType == TYPE_INT)
				addCommand( new IREM());
			else if (node->returnType->varType == TYPE_FLOAT)
				addCommand( new FREM());
		}
	}

    void visit( ExprNode* node) override {
        if ( node->exprType == EXPR_ARRAY_ELEM_CALL) {
            node->left->visit(this);
            node->right->visit(this);
			
			VarType returnType = node->returnType->varType;

            if( returnType == TYPE_POINTER || returnType == TYPE_ARRAY){
                addCommand( new AALOAD());
            } else if ( returnType == TYPE_INT) {
                addCommand( new IALOAD());
            } else if ( returnType == TYPE_FLOAT) {
				addCommand( new FALOAD());
			}
            //if( node->returnType->childType->varType == TYPE_POINTER) throw new runtime_error(" array of objects unsupported yet");
        }
        else if ( node->exprType == EXPRE_ARRAY_ELEM_ASSIGN ) {
            node->object->visit(this);
            node->left->visit(this);
            node->right->visit(this);

			VarType rightType = node->right->returnType->varType;
            if( rightType == TYPE_POINTER) {
                addCommand( new AASTORE());
            } else if ( rightType == TYPE_INT) {
                addCommand( new IASTORE());
            } else if ( rightType == TYPE_FLOAT) {
				addCommand( new FASTORE());
			}
        }
        else if ( node->exprType == EXPR_FUNC_CALL) {
            auto args = node->methodCallArgs;

            FOR_EACH( methodNode, node->methodCallArgs){
                VISIT_IF_NOT_NULL( (*methodNode));
            }
            addCommand( new INVOKE_STATIC( node->constantNum));
        }
        else if ( node->exprType == EXPR_INVAR_CALL) {
            node->object->visit(this);
            addCommand( new GET_FILED(node->constantNum));
        } 
        else if ( node->exprType == EXPRE_CLASS_FIELD_ASSIGN ){
            node->object->visit( this);
            node->right->visit( this);
            addCommand( new PUT_FILED(node->constantNum));
        }
        else if ( node->exprType == EXPR_METHOD_CALL) {
            
            VISIT_IF_NOT_NULL( node->object);
            FOR_EACH( methodNode, node->methodCallArgs){
                VISIT_IF_NOT_NULL( (*methodNode));
            }

            if ( node->object->returnType->varType == TYPEE_CLASS) {
                if ( node->isAlloc) {
                    int classid = table->classByMethod[ node->constantNum];
                    addCommand( new NEW( classid));
                    addCommand( new DUP());
                    addCommand( new INVOKE_SPECIAL( table->constructors[node->object->returnType->name]));
                }
                else {
                    addCommand( new INVOKE_STATIC( node->constantNum));
                }
            } else if ( node->object->returnType->varType == TYPE_POINTER) {
                

                addCommand( new INVOKE_VIRTUAL( node->constantNum));
            } else throw new runtime_error( "method call from not object (code gen)");
        }
        else if ( node->exprType == EXPR_OPERATION) {
            if( node->operationType == OP_VALUE) {
				if (node->constType == TYPE_CUSTOM) {
                    auto type = node->returnType;
                    int number = getVarNumber( node->name);
                    if ( type->varType == TYPE_INT) {
						addCommand( new ILOAD(number));
                    } else if ( type->varType ==TYPE_FLOAT) {
						addCommand( new FLOAD(number));
					} else if ( type->varType == TYPE_POINTER || (type->varType == TYPE_ARRAY )){
                        addCommand( new ALOAD(number));
                    }
				} else if (node->constType == TYPE_INT) {
					addCommand( new SIPush(node->intVal));
					if (node->returnType->varType == TYPE_FLOAT)
						addCommand( new I2F());
                } else if ( node->constType == TYPE_FLOAT) {
					addCommand( new LDC_W(table->floats[ node->floatVal]));
					if (node->returnType->varType == TYPE_INT)
						addCommand( new F2I());

				} else if ( node->constType == TYPE_STRING) {
                    addCommand( new LDC_W( table->strings[ node->strVal]));
                } else if ( node->constType == TYPE_POINTER){
					addCommand( new ACONST_NULL());
				}
                
            } else if (node->isBinnaryMath()) {
				
				calcBinaryMath(node);
			
			} else if (node->isUnnaryMath()) {

				calcUnaryMath(node);

			} else if( node->operationType == OP_ASSIGN) {
                node->right->visit(this);
                int number = getVarNumber( node->left->name);

				VarType leftType = node->left->returnType->varType;
				VarType rightType = node->right->returnType->varType;

                if ( leftType == TYPE_INT){

					if (rightType == TYPE_FLOAT)
						addCommand( new F2I());
				    addCommand( new ISTORE(number));

                } else if (leftType == TYPE_FLOAT) {
					
					if (rightType == TYPE_INT)
						addCommand( new I2F());
					addCommand( new FSTORE(number));

				} else if (node->right->returnType->varType == TYPE_POINTER){
                    addCommand( new ASTORE(number)); 
                } else if ( node->right->returnType->varType == TYPE_ARRAY){
                    addCommand( new LDC_W( table->ints[ node->right->arrayElems->exprs.size()]));
                    
                    if ( node->right->returnType->childType->varType == TYPE_POINTER){
                        int classid =table->classNumByName[ node->right->returnType->childType->childType->name];
                        addCommand( new ANEW_ARRAY( classid));
                        int index = 0;
                        FOR_EACH( elem, node->right->arrayElems->exprs){
                            addCommand( new DUP());
                            addCommand( new SIPush( index));
                            index++;
                            (*elem)->visit( this);
                            addCommand( new AASTORE());
                        }
                        addCommand( new ALOAD( getVarNumber( node->left->name)));
                    }
                    else {

                        addCommand( new NEW_ARRAY( node->right->returnType->childType->childType->varType));
                        int index = 0;
                        FOR_EACH( elem, node->right->arrayElems->exprs){
                            addCommand( new DUP());
                            addCommand( new SIPush( index));
                            index++;
                            (*elem)->visit( this);
                            addCommand( new IASTORE());
                        }
                        addCommand( new ALOAD( getVarNumber( node->left->name)));
                    }
                    
                }
            } else if( node->operationType == OP_ASSIGN_ARRAY) {
                // �������� ���-�� ��� �������� �����
				//node->left->visit(this);
                addCommand( new SIPush( node->arrayElems->exprs.size()));
                if( node->left->returnType->childType->varType == TYPE_POINTER){
                    
					addCommand( new ANEW_ARRAY( table->classNumByName[ node->left->returnType->childType->childType->name]));
                    int index = 0;
                    FOR_EACH( elem, node->arrayElems->exprs){
                        addCommand( new DUP());
                        addCommand( new SIPush( index));
                        (*elem)->visit( this );
                        index++;
                        addCommand( new AASTORE());
                    }
                } else {
                    addCommand( new NEW_ARRAY( node->left->returnType->childType->varType));
                    int index = 0;
                    FOR_EACH( elem, node->arrayElems->exprs){
                        addCommand( new DUP());
                        addCommand( new SIPush( index));
                        (*elem)->visit( this );
                        index++;
                        addCommand( new IASTORE());
                    }
                }
                int varNum = getVarNumber( node->left->name);
                addCommand( new ASTORE( varNum));
                // ���� ������� ����� ����� ����������
				//commands.push_back( new ISTORE());
            } 
			else if( node->isBinnaryComparer() || node->isEqual() )
			{
				calcBinaryComp(node);

            } else if( node->operationType == OP_LOGICAL_NOT) {
                
				node->left->visit(this);

				if (node->left->returnType->varType == TYPE_FLOAT) {
					addCommand( new FCONST(0));
					addCommand( new FCMP(OP_GREATER));
				}

				int ifLine = numberCurrentRow;
				int numberIfCommand = commands.size();
				addCommand( new IF_0(OP_NOT_EQUAL, 0, false));

				addCommand( new SIPush(0));

				int gotoLine = numberCurrentRow;
				int numberGotoCommand = commands.size();
				addCommand( new GOTO(0));
				
				int shift = numberCurrentRow - ifLine;
				commands[numberIfCommand] = new IF_0(OP_NOT_EQUAL, shift, false);

				addCommand( new SIPush(1));

				shift = numberCurrentRow - gotoLine;
				commands[numberGotoCommand] = new GOTO(shift);

            } else if( node->operationType == OP_AND) {
                
				node->left->visit(this);
				
				if (node->left->returnType->varType == TYPE_FLOAT) {
					addCommand( new FCONST(0));
					addCommand( new FCMP(OP_GREATER));
				}

				int ifLine = numberCurrentRow;
				int numberIfCommand = commands.size();
				addCommand( new IF_0(OP_NOT_EQUAL, 0, true));
				addCommand( new SIPush(0));
				int gotoLine1 = numberCurrentRow;
				int numberGotoCommand1 = commands.size();
				addCommand( new GOTO(0));
				int shift = numberCurrentRow - ifLine;
				commands[numberIfCommand] = new IF_0(OP_NOT_EQUAL, shift, true);

				node->right->visit(this);

				if (node->right->returnType->varType == TYPE_FLOAT) {
					addCommand( new FCONST(0));
					addCommand( new FCMP(OP_GREATER));
				}

				ifLine = numberCurrentRow;
				numberIfCommand = commands.size();
				addCommand( new IF_0(OP_NOT_EQUAL, 0, true));
				addCommand( new SIPush(0));

				int gotoLine2 = numberCurrentRow;
				int numberGotoCommand2 = commands.size();
				addCommand( new GOTO(0));
				shift = numberCurrentRow - ifLine;
				commands[numberIfCommand] = new IF_0(OP_NOT_EQUAL, shift, true);

				addCommand( new SIPush(1));
				
				shift = numberCurrentRow - gotoLine1;
				commands[numberGotoCommand1] = new GOTO(shift);

				shift = numberCurrentRow - gotoLine2;
				commands[numberGotoCommand2] = new GOTO(shift);

            } else if( node->operationType == OP_OR) {
                
				node->left->visit(this);
				
				if (node->left->returnType->varType == TYPE_FLOAT) {
					addCommand( new FCONST(0));
					addCommand( new FCMP(OP_GREATER));
				}

				int ifLine = numberCurrentRow;
				int numberIfCommand = commands.size();
				addCommand( new IF_0(OP_NOT_EQUAL, 0, false));
				addCommand( new SIPush(1));
				int gotoLine1 = numberCurrentRow;
				int numberGotoCommand1 = commands.size();
				addCommand( new GOTO(0));
				int shift = numberCurrentRow - ifLine;
				commands[numberIfCommand] = new IF_0(OP_NOT_EQUAL, shift, false);

				node->right->visit(this);

				if (node->right->returnType->varType == TYPE_FLOAT) {
					addCommand( new FCONST(0));
					addCommand( new FCMP(OP_GREATER));
				}

				ifLine = numberCurrentRow;
				numberIfCommand = commands.size();
				addCommand( new IF_0(OP_NOT_EQUAL, 0, false));
				addCommand( new SIPush(1));

				int gotoLine2 = numberCurrentRow;
				int numberGotoCommand2 = commands.size();
				addCommand( new GOTO(0));
				shift = numberCurrentRow - ifLine;
				commands[numberIfCommand] = new IF_0(OP_NOT_EQUAL, shift, false);

				addCommand( new SIPush(0));
				
				shift = numberCurrentRow - gotoLine1;
				commands[numberGotoCommand1] = new GOTO(shift);

				shift = numberCurrentRow - gotoLine2;
				commands[numberGotoCommand2] = new GOTO(shift);

            }
        }
    }


    string genCode( JavaMethodTableRecord& method, JavaConstantTable* table){
        commands.clear();
        this->table = table;
        localVars.clear();
		localVarsNumber.clear();
		//localVarsNumber = info->localVarsNumber;
		numberCurrentRow = 0;
        

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