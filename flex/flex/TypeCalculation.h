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
        if( this->isMethod){
			if( classes.find(curClass->name) == classes.end()){
				addError("Unknown class: " + curClass->name);
				return;
			}
			else {
				currentFuncOrMethod = classes[curClass->name]->getMethod( curMethod);
			}
		}
        else {
            currentFuncOrMethod = functions[ curFunc->name];
		}

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
            {
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
                    if( classes.find( node->name) != classes.end() ){
                        retType->varType = TYPEE_CLASS;
                        isExist = true;
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
            // Здесь проверяем чтоб все елементы массива были одного типа
            FOR_EACH( iArrayElemExpr, node->arrayElems->exprs){
                //Заходим в каждый
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
                        // TODO: По-хорошему бы привидение типов вставить
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
                        /// TODO: По-хорошему бы привидение типов вставить
                } else if( node->left->returnType->varType == TYPE_POINTER && node->right->returnType->varType == TYPE_POINTER) {
                    /// TODO: По-хорошему бы привидение типов вставить и проверить указатели
                } else {
                    addError("Can`t compare");
                }

            } else if( node->isBinnaryLogical() ) {
                //TODO:: Дима проверяй сам (a != nil) && YES
                retType->varType = TYPE_BOOL;
				if (node->left->returnType->varType == TYPE_BOOL && node->right->returnType->varType == TYPE_BOOL) {
				
				} else {
					if (node->left->returnType->varType == TYPE_INT) {
						node->left->boolVal = node->left->intVal != 0;
					}
					else if (node->left->returnType->varType == TYPE_FLOAT) {
						node->left->boolVal = node->left->floatVal != 0;
					}
					else if (node->left->returnType->varType == TYPE_CHAR) {
						node->left->boolVal = node->left->charVal != 0;
					}
					else if (node->left->returnType->varType == TYPE_STRING) {
						node->left->boolVal = node->left->strVal != "";
					}
					else {
						addError("Left expr can't compare");
					}

					if (node->right->returnType->varType == TYPE_INT) {
						node->right->boolVal = node->right->intVal != 0;
					}
					else if (node->right->returnType->varType == TYPE_FLOAT) {
						node->right->boolVal = node->right->floatVal != 0;
					}
					else if (node->right->returnType->varType == TYPE_CHAR) {
						node->right->boolVal = node->right->charVal != 0;
					}
					else if (node->right->returnType->varType == TYPE_STRING) {
						node->right->boolVal = node->right->strVal != "";
					}
					else {
						addError("Right expr can't compare");
					}
				}

            } else if ( node->operationType == OperationType::OP_LOGICAL_NOT) {
                //TODO:: Дима проверяй сам
            } else if ( node->operationType == OperationType::OP_ASSIGN) {
                node->returnType = new TypeNode( *node->right->returnType);
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
                /// TODO:: Где-то проверить соотвествие аргументов
                retType = ifunc->second->returnType.toNode();
            }
        } 
        else if ( node->exprType == ExprType::EXPR_METHOD_CALL ) {
            MethodInfo* meth = nullptr;
            if( node->object->returnType->varType == TYPEE_CLASS) {
                ClassInfo* iclassinfo = classes[node->object->name]; 
                auto imeth = iclassinfo->staticMethods.find( node->name);
                if (imeth != iclassinfo->staticMethods.end()){
                    meth = imeth->second;
                } else {
                    addError(string("Unknown static method: ") + iclassinfo->name + "::" + node->name );
                }

                

            } else if(node->object->returnType->varType == TYPE_POINTER) {
                string classname = node->object->returnType->childType->name;
                ClassInfo* iclassinfo = classes[classname]; 
                auto imeth = iclassinfo->localMethods.find( node->name);
				if (imeth != iclassinfo->localMethods.end() && imeth->second){
                    meth = imeth->second;
                } else {
                    addError(string("Unknown local method: ") + iclassinfo->name + "::" + node->name );
                }
            } else {
				addError(string("Can`t call method " + node->name + " from variable " + node->object->name));
            }
            if( meth) {
                retType = meth->returnType.toNode();
            }
        } else if ( node->exprType == ExprType::EXPR_INVAR_CALL ) {
            if(node->object->returnType->varType == TYPEE_CLASS) {
                addError("can`t get static field");
            } else if (node->object->returnType->varType == TYPE_CUSTOM) {
                //TODO:: А сюды ваще зайдёт?
                //throw "TypeCalc 226?";
                addError(string("Can`t get field " + node->name + " from variable " + node->object->name));
            } else if ( node->object->returnType->varType == TYPE_POINTER) {

                string classname = node->object->returnType->childType->name;
                ClassInfo* iclassinfo = classes[classname]; 
                auto ifield = iclassinfo->fields.find( node->name);
                if( ifield != iclassinfo->fields.end()){
                    retType = ifield->second->type.toNode();
                } else {
                    addError("Unknown field: " + iclassinfo->name + "::" + node->name);
                }
            }
        }
        else if ( node->exprType == ExprType::EXPRE_ARRAY_ELEM_ASSIGN ) {
            retType = new TypeNode(*node->right->returnType->childType);
        } 
        else if ( node->exprType == ExprType::EXPRE_CLASS_FIELD_ASSIGN) {
            retType = new TypeNode(*node->right->returnType->childType);
        }
        else if ( node->exprType == ExprType::EXPR_ARRAY_ELEM_CALL ) {
            retType = new TypeNode(*node->left->returnType->childType);
        }
       
        node->returnType = retType;
    }
public:
	TypeCalculation() {
		this->curClass = nullptr;
		this->curFunc = nullptr;
		this->curMethod = nullptr;
		this->curstmt = nullptr;
		
		this->isClass= false;
		this->isMethod= false;
		this->isFunc= false;
	}

};