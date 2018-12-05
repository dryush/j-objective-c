#pragma once

#include "TableFiller.h"

//#define RETURN_IF_NODE_TYPE_EXIST node->

class TypeCalculation : public NodeVisiter {

    bool isFunc;
    FunctionNode* curFunc;
    void visit( FunctionNode* node) override {
        isFunc = true;
        curFunc = node;
        NodeVisiter::visit( node);
        curFunc = nullptr;
        isFunc = false;
    }

    bool isMethod;
    ClassMethodImplementationNode* curMethod;
    void visit( ClassMethodImplementationNode* node) override {
        isMethod = true;
        curMethod = node;
        NodeVisiter::visit( node);
        curMethod = nullptr;
        isMethod = false;
    }

    bool isClass;
    ClassImplementationNode* curClass;
    void visit( ClassImplementationNode* node) override {
        isClass = true;
        curClass = node;
        NodeVisiter::visit(node);
        isClass = false;
        curClass = nullptr;
    }


    StatementNode* stmt;
    void visit( StatementNode* node) override {
        stmt = node;
        
        FunctionInfo * currentFuncOrMethod;
        if( this->isMethod)
            currentFuncOrMethod = classes[curClass->name]->getMethod( curMethod);
        else
            currentFuncOrMethod = functions[ curFunc->name];

        if( stmt->stmtType == STMT_ARRAY_DECL){
            currentFuncOrMethod->addLocalVar( stmt->name, TypeInfo( stmt->varType));
        } else if ( stmt->stmtType == STMT_VAR_DECL) {
            currentFuncOrMethod->addLocalVar( stmt->name, TypeInfo( stmt->varType));
        }

        NodeVisiter::visit( node);
        stmt = nullptr;
    }

    TypeNode* calcValueExprType(ExprNode* node){
        auto retType = new TypeNode();

        retType->varType = node->constType;
        
        if( node->constType == VarType::TYPE_CUSTOM) {
            //retType->name = node->name;
            FunctionInfo* curFuncOrMethod;
            ClassInfo*  curClassInfo;
            if( isFunc) { 
                curFuncOrMethod =  functions[ curFunc->name]; 
            }
            else if ( isMethod) {
                curClassInfo = classes[ curClass->name];
                if( curMethod->methodType == MethodType::METHOD_LOCAL)
                    curFuncOrMethod = curClassInfo->localMethods[ curMethod->name];
                else
                    curFuncOrMethod = curClassInfo->staticMethods[ curMethod->name];
            }

            TypeInfo typeInfo;

            bool isExist = curFuncOrMethod->getVar( node->name, &typeInfo);
            if( !isExist){
                if ( isMethod) {
                    auto field = curClassInfo->fields[ node->name];
                    if( field) {
                        isExist = true;
                        typeInfo = field->type;
                    }
                }
            }

            if( !isExist) {
                addError(string("Unknown variable: ") + node->name);
            } else {
                retType = typeInfo.toNode();
            }
        }
        else if ( node->constType == VarType::TYPE_ARRAY ) {
            
            auto arrayType = getMethodVarType( curClass->name, curMethod->name, node->name);
            auto type = arrayType->arrayType;
            auto customtypename = arrayType->name;
            // «десь провер€ем чтоб все елементы массива были одного типа
            FOR_EACH( iArrayElemExpr, node->arrayElems->exprs){
                //«аходим в каждый
                VISIT_IF_NOT_NULL( (*iArrayElemExpr));
                if( type != (*iArrayElemExpr)->constType ||  customtypename != (*iArrayElemExpr)->name) {
                    addError(string("Uncorrect array elem type, var name: ") + node->name);
                }
            }
            retType = arrayType->toNode();
        } 
        return retType;
    }

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
                retType = calcValueExprType( node);
            } else if ( node->isBinnaryMath()) {
                //auto lefttype = node->left
            }

        }
        node->returnType = retType;
    }

}