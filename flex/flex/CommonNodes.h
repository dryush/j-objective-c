#pragma once

#include <string>
#include <list>
#include <vector>
#include "TreeClass.h"

using namespace std;

const string NULL_VAL = "#NULL#";

class MethodCallArgNode;

class TypeNode : public Node {
public:
	VarType varType;
	TypeNode* childType;
	string name;
    
    void visit(NodeVisiter* visiter);

    
    bool isNuberValue(){
        return this->varType == VarType::TYPE_FLOAT || this->varType == VarType::TYPE_INT;
    }

    bool isDefaultType(){
        return varType == VarType::TYPE_BOOL || 
            varType == VarType::TYPE_CHAR ||
            varType == VarType::TYPE_FLOAT || 
            varType == VarType::TYPE_INT;
    }

    bool isString(){
        return varType == TYPE_STRING;
    }

	TypeNode() {
		this->name = "";
		this->childType = nullptr;
		this->varType = TYPEE_UNSET;
	}

    TypeNode(TypeNode& tn) {
        this->name = tn.name;
        this->varType = tn.varType;
        if( tn.childType){
            this->childType = new TypeNode( *tn.childType);
        } else this->childType = nullptr;
    }

	TypeNode(Type_st * st) {

		this->varType = st->var_type;
		if( this->varType == TYPE_CUSTOM)
			this->name = st->name;
		this->childType = nullptr;
        if( st->var_type == TYPE_POINTER || st->var_type == TYPE_ARRAY)
		    if( st->childType)
			    this->childType = new TypeNode(st->childType);
	}
	
};



class ExprNode;

class ExprListNode : public Node {
public:
	list<ExprNode*> exprs;
	ExprListNode(Expr_list_st* st);

    void visit(NodeVisiter* visiter);
};

class ExprNode : public Node {
public:
	ExprType exprType;
	OperationType operationType;
	VarType constType;

	ExprNode* left;
	ExprNode* right;

	ExprListNode* arrayElems;
	string name; /* ��� / ��� ������� / ��� ����������� ���� / ��� ����������� ������ */
	int intVal;
	double floatVal;
	bool boolVal;
	char charVal;
	string strVal;
	/* ����� ������ */
	ExprNode* object; /* ������ � �������� ���������� ���� ��� ����� */
	/// TODO:: struct Method_call_arg_list_st* method_args; 
	//list<ExprNode*> methodArgs;
	// TODO:: replace args and convert to exprNode
	vector<MethodCallArgNode*> methodCallArgs;
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	/* ����� �������*/
	ExprListNode* funcArgs;
    bool isAlloc;
    int constantNum;

    void visit(NodeVisiter* visiter);
    
    TypeNode* returnType; // 

    bool isBinnaryLogical() {
        return this->exprType == EXPR_OPERATION && (
            this->operationType == OP_AND ||
            this->operationType == OP_OR
        );
    }
    
    bool isBinnaryComparer () {
        return this->exprType == EXPR_OPERATION && (
            this->operationType == OP_LESS ||
            this->operationType == OP_LESS_OR_EQUAL ||
            this->operationType == OP_GREATER ||
            this->operationType == OP_GREATER_OR_EQUAL
        );
    }

    bool isEqual() {
        return this->exprType == EXPR_OPERATION && (
            this->operationType == OP_EQUAL ||
            this->operationType == OP_NOT_EQUAL
        );
    }

    bool isBinnaryAssign() {
        return this->exprType == EXPR_OPERATION && (
            this->operationType == OP_ASSIGN );
    }
    
    bool isBinnaryAssignArray() {
        return this->exprType == EXPR_OPERATION && (
            this->operationType == OP_ASSIGN_ARRAY );
    }


    bool isBinnaryMath () {
        return this->exprType == EXPR_OPERATION && (
            this->operationType == OP_ADD ||
            this->operationType == OP_SUB ||
            this->operationType == OP_DIV ||
            this->operationType == OP_MUL ||
            this->operationType == OP_MOD 
        );
    }

    bool isBinnaryOnlyNumbers() {
        return this->isBinnaryMath() || this->isBinnaryComparer();
    }

    bool isUnnaryMath() {
        return this->exprType == EXPR_OPERATION && (
            this->operationType == OP_UMINUS ||
            this->operationType == OP_UPLUS
        );
    }

    bool isLeftRight(){
        ///TODO::Порверить внимательнее
        return this->left && this->right;
    }

    bool isNumberValue(){
		return this->returnType->varType == VarType::TYPE_FLOAT || this->returnType->varType == VarType::TYPE_INT;
    }

    ExprNode() {
		this->left = nullptr;
		this->right = nullptr;
		this->arrayElems = nullptr;
		this->name = "";
		this->strVal = "";
		this->charVal = 0;
		this->object = nullptr;
		this->funcArgs = nullptr;
		this->returnType = nullptr;
	}

	ExprNode(Expression_st* st);

};

ExprListNode::ExprListNode(Expr_list_st* st) {
	auto last = st;
	while (last) {
		this->exprs.push_back(new ExprNode(last->expr));
		last = last->next;
	}
}

class StatementNode : public Node {
public:
	StatementType stmtType;
	ExprNode* expr;
	ExprNode* condition;
	StatementNode* truthStmt;
	StatementNode* wrongStmt;
	list<StatementNode*> childs;
	list<ExprNode*> arrayElems;
	int arraySize;
	/*���������� ����������*/
	TypeNode* varType;
	string name;
	///TODO:: ������ � �����������


    void visit(NodeVisiter* visiter);

	StatementNode(Statement_st* st) {
		this->expr = nullptr;
		this->condition = nullptr;
		this->truthStmt = nullptr;
		this->wrongStmt = nullptr;

		this->varType = nullptr;
		this->name = "";
		this->arraySize = 0;
		this->stmtType = st->stmt_type;

		if (this->stmtType == STMT_ARRAY_DECL) {
			/// TODO::
			this->name = st->identifier;
			this->varType = new TypeNode(st->var_type);
			this->arraySize = st->array_size;
			auto last = st->array_elems;
            if( last == NULL && arraySize > 0){
                auto defVal = new Expression_st();
                defVal->exprType = EXPR_OPERATION;
                defVal->operationType = OP_VALUE;
                defVal->const_type = this->varType->childType->varType;
                defVal->bool_value = defVal->char_value = defVal->float_value = defVal->int_value = 0;
                defVal->array_elems = NULL; defVal->func_args = NULL; defVal->left = NULL; defVal->right = NULL;
                defVal->object = NULL; 
                defVal->string_value = "";
                defVal->identifier = new char[ NULL_VAL.size()+1];
                strcpy( defVal->identifier, NULL_VAL.c_str());
                st->array_elems = new Expr_list_st();
                st->array_elems->expr = NULL;
                st->array_elems->next = NULL;
                last = st->array_elems;
                auto start = last;
                last->expr = new Expression_st(*defVal);
                for( int iae = 1; iae < this->arraySize; iae++){
                    last->next = new Expr_list_st();
                    last->next->expr = new Expression_st(*defVal);
                    last->next->next = NULL;
                    last = last->next;
                }
                //st->array_elems = start;
            }
            /*
            if( last == NULL && arraySize > 0){
                for( int ij = 0; ij < this->arraySize; ij++){
                    ExprNode* defVal = new ExprNode();
                    defVal->exprType = EXPR_OPERATION;
                    defVal->operationType = OP_VALUE;
                    defVal->constType = this->varType->childType->varType;
                    defVal->intVal = defVal->boolVal = defVal->charVal = defVal->floatVal = 0;
                    defVal->strVal = "";
                    defVal->name = NULL_VAL;
                    this->arrayElems.push_back( defVal);
                }
            }
			while (last != NULL) {
				auto arrayElem = new ExprNode(last->expr);
				this->arrayElems.push_back(arrayElem);
				last = last->next;
			}*/
		}
		else if (this->stmtType == STMT_COMPOUND) {
			auto last = st->stmt_list;
			/// TODO: ������� �� ������, ������� �������
			while (last) {
				auto child = new StatementNode(last->stmt);
				this->childs.push_back( child);
				// ��������� ���������� � ����������� �� ��� ��������� ����
                if ( (child->stmtType == STMT_VAR_DECL || child->stmtType == STMT_ARRAY_DECL) && last->stmt->expr) {
					Expression_st* left  = CreateIDExpression(last->stmt->identifier);
					Expression_st* expr = nullptr;
					if (child->stmtType == STMT_ARRAY_DECL) {
						expr = CreateArrayInitExpr(left, last->stmt->array_elems);
					}
					else if (child->stmtType == STMT_VAR_DECL) {
						expr = CreateExpression(OP_ASSIGN, left, last->stmt->expr);
					}
					StatementNode* assign = new StatementNode( CreateExpressionStatement(expr));
					this->childs.push_back(assign);
				} 
				last = last->next;
			}
		}
		else if (this->stmtType == STMT_EXPR) {
			this->expr = new ExprNode(st->expr);
		}
		else if (this->stmtType == STMT_IF) {
			this->condition = new ExprNode(st->condition);
			this->truthStmt = new StatementNode(st->truth_stmt);
			this->wrongStmt = st->wrong_stmt ? new StatementNode(st->wrong_stmt) : nullptr;
		}
		else if (this->stmtType == STMT_WHILE) {
			this->condition = new ExprNode(st->condition);
			this->truthStmt = new StatementNode(st->truth_stmt);
		}
		else if (this->stmtType == STMT_RETURN) {
            if ( st->expr) {
                this->expr = new ExprNode(st->expr);
            } 
		}
		else if (this->stmtType == STMT_VAR_DECL) {
			this->varType = new TypeNode(st->var_type);
			this->name = st->identifier;
            this->expr = nullptr;
            //this->expr = st->expr ? new ExprNode(st->expr) : nullptr;
		}
	}

	StatementNode() {
		this->arrayElems;
		this->arraySize = 0;
		this->childs;
		this->condition =nullptr;
		this->expr =nullptr;
		this->name ="";
		this->truthStmt =nullptr;
		this->varType =nullptr;
		this->wrongStmt =nullptr;
	}
};

	
#include "ClassNodes.h"

ExprNode::ExprNode(Expression_st* st) {
	this->left = nullptr;
	this->right = nullptr;
	this->arrayElems = nullptr;
	this->name = "";
	this->strVal = "";
	this->object = nullptr;
	this->funcArgs = nullptr;

	this->exprType = st->exprType;
	this->operationType = st->operationType;
	this->constType = st->const_type;

	this->returnType = nullptr;

    this->isAlloc = false;

	if (st->exprType == EXPR_ARRAY_ELEM_CALL){
		this->left = new ExprNode(st->left);
		this->right = new ExprNode(st->right);  
	}
	else if (this->exprType == EXPR_OPERATION) {
		if (this->operationType == OP_VALUE) {
			
			//this->returnType = new TypeNode();
			this->returnType = nullptr;
			//this->returnType->varType = this->constType;
			
			if (this->constType == TYPE_CUSTOM) {
				this->name = st->identifier;
			}
			else if (this->constType == TYPE_BOOL) {
				this->boolVal = st->bool_value;
			}
			else if (this->constType == TYPE_CHAR) {
				this->charVal = st->char_value;
			}
			else if (this->constType == TYPE_FLOAT) {
				this->floatVal = st->float_value;
				this->intVal = st->float_value;
			}
			else if (this->constType == TYPE_INT) {
				this->intVal = st->int_value;
				this->floatVal = st->float_value;
			}
			else if (this->constType == TYPE_STRING) {
				this->strVal = st->string_value;
			}
			else if (this->constType == TYPE_ARRAY) {
				
			}
		}
		else if (this->operationType == OP_UPLUS
			|| this->operationType == OP_UMINUS
			|| this->operationType == OP_LOGICAL_NOT
			) {
			this->left = new ExprNode(st->left);
		}
		else if (this->operationType == OP_ASSIGN_ARRAY) {
			this->left = new ExprNode(st->left);
			this->arrayElems = new ExprListNode(st->array_elems);
		}
		else {
			this->left = new ExprNode(st->left);
			this->right = new ExprNode(st->right);
		}
	}
	else if (this->exprType == EXPR_FUNC_CALL) {
		this->name = st->identifier;
		//this->funcArgs = new ExprListNode(st->func_args);

        MethodCallArgNode::FillFrom(this->methodCallArgs, st->func_args);
    }
	else if (this->exprType == EXPR_INVAR_CALL) {
		this->object = new ExprNode(st->object);
		this->name = st->identifier;
	}
	else if (this->exprType == EXPR_METHOD_CALL) {
		this->object = new ExprNode(st->object);
		this->name = st->identifier;
		/// TODO::
		MethodCallArgNode::FillFrom(this->methodCallArgs, st->method_args);
	}
}