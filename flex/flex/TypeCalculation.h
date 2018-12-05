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


    StatementNode* curstmt;
    void visit( StatementNode* node) override {
        curstmt = node;
        
        FunctionInfo * currentFuncOrMethod;
        if( this->isMethod)
            currentFuncOrMethod = classes[curClass->name]->getMethod( curMethod);
        else
            currentFuncOrMethod = functions[ curFunc->name];

        if( curstmt->stmtType == STMT_ARRAY_DECL){
            currentFuncOrMethod->addLocalVar( curstmt->name, TypeInfo( curstmt->varType));
        } else if ( curstmt->stmtType == STMT_VAR_DECL) {
            currentFuncOrMethod->addLocalVar( curstmt->name, TypeInfo( curstmt->varType));
        }

        NodeVisiter::visit( node);
        curstmt = nullptr;
    }

    TypeNode* calcValueExprType(ExprNode* node){
        auto retType = new TypeNode();

        retType->varType = node->constType;
        
        if( node->constType == VarType::TYPE_CUSTOM) {
            //retType->name = node->name;
            if( classes.find( node->name) != classes.end() ){
                retType->varType = TYPEE_CLASS;
            } else {
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

    TypeNode* calcOperation( ExprNode* node) {
        auto retType = new TypeNode();

        if( node->exprType == ExprType::EXPR_OPERATION) {
            
            if( node->operationType == OperationType::OP_VALUE) {
                retType = calcValueExprType( node);
            } else if ( node->isBinnaryOnlyNumbers()) {

                if( node->left->isNuberValue() && node->right->isNuberValue()) {
                    if( node->left->returnType->varType != node->right->returnType->varType && (
                        node->left->returnType->varType == VarType::TYPE_FLOAT || 
                        node->right->returnType->varType == VarType::TYPE_FLOAT
                        )
                    ){
                        retType->varType = TYPE_FLOAT;
                        // TODO: ѕо-хорошему бы привидение типов вставить
                    } else {
                        retType->varType = node->left->constType;
                    }
                } else {
                    addError("Not number with binnary math operations");
                }
            } else if ( node->isUnnaryMath() ) {

                if( node->left->returnType->varType == TYPE_INT || 
                    node->left->returnType->varType == TYPE_FLOAT) {
                    retType->varType = node->left->returnType->varType;
                } else {
                    addError("Not number with uplus or uminus");
                }
            } else if( node->isEqual()) {
                retType->varType = TYPE_BOOL;
                if( node->left->returnType->varType == node->right->returnType->varType) {
                        

                } else if ( node->left->returnType->isNuberValue() && node->right->returnType->isNuberValue()) {
                        /// TODO: ѕо-хорошему бы привидение типов вставить
                } else if( node->left->returnType->varType == TYPE_POINTER && node->right->returnType->varType == TYPE_POINTER) {
                    /// TODO: ѕо-хорошему бы привидение типов вставить и проверить указатели
                } else {
                    addError("Can`t compare");
                }

            } else if( node->isBinnaryLogical() ) {
                //TODO:: ƒима провер€й сам
                retType->varType = TYPE_BOOL;
            } else if ( node->operationType == OperationType::OP_LOGICAL_NOT) {
                //TODO:: ƒима провер€й сам
            }

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

        TypeNode* retType = new TypeNode();
        
        if( node->exprType == ExprType::EXPR_OPERATION) {
            retType = calcOperation( node);
        } 
        else if ( node->exprType == ExprType::EXPR_FUNC_CALL ) {
            auto ifunc = functions.find( node->name);
            if( ifunc != functions.end()){
                /// TODO:: √де-то проверить соотвествие аргументов
                retType = ifunc->second->returnType.toNode();
            }
        } 
        else if ( node->exprType == ExprType::EXPR_METHOD_CALL ) {
            MethodInfo* meth;
            if( node->object->returnType->varType == TYPEE_CLASS) {
                ClassInfo* iclassinfo = classes[node->name]; 
                auto imeth = iclassinfo->staticMethods.find( node->name);
                if (imeth != iclassinfo->staticMethods.end()){
                    meth = imeth->second;
                } else {
                    addError(string("Unknown static method ") + iclassinfo->name + "::" + node->name );
                }
            } else {

            }
        }
       
        node->returnType = retType;
    }

}