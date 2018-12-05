#include "TableFiller.h"

class PointerChecker : public NodeVisiter {


public:

	void visit( StatementNode* node) override {
		if ( node->stmtType == STMT_EXPR) {
			auto expr = node->expr;
			//Если умножение
			if( expr->exprType == EXPR_OPERATION && expr->operationType == OP_MUL ){
				// Если оба операнда- значения
				if( expr->left->exprType == EXPR_OPERATION && expr->left->operationType == OP_VALUE &&
					expr->right->exprType == EXPR_OPERATION && expr->right->operationType == OP_VALUE ) {
					// Если оба значения неизвестного ( своего) типа
					if ( expr->left->constType == TYPE_CUSTOM && expr->right->constType == TYPE_CUSTOM) {
						// Если существует классс именем левого операндаы
						if( classes.find( expr->left->name) != classes.end()) {
							StatementNode* newstmt = new StatementNode();
							newstmt->stmtType = STMT_VAR_DECL;
							newstmt->name= expr->right->name;
							
							auto type = new TypeNode();
							type->varType = TYPE_POINTER;
							type->childType = new TypeNode();
							type->childType->varType = TYPE_CUSTOM;
							type->childType->name = expr->left->name;

							newstmt->varType = type;

							*node = *newstmt;
							delete newstmt;
						}
					}
				}
			}
		}
		NodeVisiter::visit(node);
	}
};