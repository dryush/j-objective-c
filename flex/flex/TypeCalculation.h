#pragma once

#include "TableFiller.h"

//#define RETURN_IF_NODE_TYPE_EXIST node->

class TypeCalculation : public NodeVisiter {

public: 
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

		if (curstmt->stmtType == STMT_RETURN) {
			curstmt->expr->returnType = calcOperation(curstmt->expr);
			if( this->isMethod) {
				if (castIfPossible(curstmt->expr, curMethod->returnType) == false) {
					addError("Return type does not match type of method " + curMethod->name + "() in class " + curClass->name);
					return;
				}
			}
			else {
				if (castIfPossible(curstmt->expr, curFunc->returnType) == false) {
					addError("Return type does not match type of function " + curFunc->name + "()");
					return;
				}
			}
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
                        typeInfo.type = TYPEE_CLASS;
                        typeInfo.name = node->name;
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
            // ����� ��������� ���� ��� �������� ������� ���� ������ ����
            FOR_EACH( iArrayElemExpr, node->arrayElems->exprs){
                //������� � ������
                VISIT_IF_NOT_NULL( (*iArrayElemExpr));
                if( type != (*iArrayElemExpr)->constType ||  customtypename != (*iArrayElemExpr)->name) {
                    addError(string("Uncorrect array elem type, var name: ") + node->name);
                }
            }
            retType = arrayType->toNode();
        } else if (node->constType == VarType::TYPEE_CLASS){
            throw "wtf?";
        } else {
            retType->varType = node->constType;
        }
        return retType;
    }

    static bool castIfPossible(ExprNode* node, TypeNode* typeToCast){
        
        if( TypeInfo(node->returnType).isEqual( typeToCast)){
            return true;
        }

        if( node->returnType->varType == TYPE_INT ) {
            /// TODO:: ���� ���
            if( typeToCast->varType == TYPE_FLOAT || typeToCast->varType == TYPE_BOOL)
                return true;
            else
                return false;
        }

        if( node->returnType->varType == TYPE_FLOAT) {
            /// TODO:: ���� ���
            if( typeToCast->varType == TYPE_INT)
                return true;
            else
                return false;
        }

        if( node->returnType->varType == TYPE_BOOL){
            /// TODO:: ���� ���
            return false;
        }

        if( node->returnType->varType == TYPE_CHAR){
            return false;
        }

        if( node->returnType->varType == TYPE_STRING){

            ExprNode nssClassObject;
            nssClassObject.exprType = EXPR_OPERATION;
            nssClassObject.operationType = OP_VALUE;
            nssClassObject.constType = TYPEE_CLASS;
            nssClassObject.name = "NSString";
            nssClassObject.returnType = new TypeNode();
            
            auto nsstringAlloc = new ExprNode();
            
            nsstringAlloc->exprType = EXPR_METHOD_CALL;
            nsstringAlloc->name="alloc";
            nsstringAlloc->returnType = classes[ nssClassObject.name]->staticMethods[ nsstringAlloc->name]->returnType.toNode();

            nsstringAlloc->object = new ExprNode( nssClassObject); 

            auto nsstringInitFromString = new ExprNode();
            nsstringInitFromString->exprType = EXPR_METHOD_CALL;
            nsstringInitFromString->name="init";
            nsstringInitFromString->object = nsstringAlloc;
            nsstringInitFromString->returnType = classes[ nssClassObject.name]->localMethods[ nsstringInitFromString->name]->returnType.toNode();

            nsstringInitFromString->methodArgs.push_back( new ExprNode(*node));
            
            *node = *nsstringInitFromString;

            return castIfPossible( node, typeToCast);
        }

        if( node->returnType->varType == TYPE_POINTER){
            if( TypeInfo(node->returnType).isEqual( typeToCast)){
                return true;
            }
            if( typeToCast->varType != TYPE_POINTER)
                return false;
            ///TODO:: ��������� �������� �� ��������� � ��������
            bool isChild = true;
            string parent = node->returnType->childType->name;
            auto parentType = classes.find( parent);
            while( parentType != classes.end() && parentType->second->parentName.size()){
                if( parentType->second->name == typeToCast->childType->name){
                    auto thisNode = new ExprNode( *node);
                    auto castNode = new ExprNode();
                    castNode->exprType = EXPR_OPERATION;
                    castNode->operationType = OPE_CAST;
                    castNode->constType = TYPE_POINTER;
                    castNode->name = parentType->second->name;
                    castNode->returnType = TypeInfo::Pointer( castNode->name).toNode();
                    *node = *castNode;
                    node->left = thisNode;

                    return true;
                }
                parentType = classes.find( parentType->second->parentName);
            }
            return false;
        }
        if( node->returnType->varType == TYPE_ARRAY){
            return false;
        }

        return false;
    }

    TypeNode* calcOperation( ExprNode* node) {
        auto retType = new TypeNode();

        if( node->exprType == ExprType::EXPR_OPERATION) {
 
            if( node->operationType == OperationType::OP_VALUE) {
				retType = calcValueExprType( node );
            } else {
				
				if (node->left)
					node->left->returnType = calcOperation(node->left);
				if (node->right)
					node->right->returnType = calcOperation(node->right);

				if ( node->isBinnaryOnlyNumbers()) {
				
					//calcVarType(node);
					if( node->left->isNumberValue() && node->right->isNumberValue()) {
                    
						VarType leftType = node->left->returnType->varType;
						VarType rightType = node->right->returnType->varType;
						if (leftType == rightType && leftType == TYPE_INT) {
							 retType->varType = TYPE_INT;
						}
						else if (leftType == rightType && leftType == TYPE_FLOAT) {
							retType->varType = TYPE_FLOAT;
						}
						else if (leftType == TYPE_FLOAT) {
							retType->varType = TYPE_FLOAT;
							node->right->floatVal = node->right->intVal;
						}
						else if (rightType == TYPE_FLOAT) {
							retType->varType = TYPE_FLOAT;
							node->left->floatVal = node->left->intVal;
						}
					} else {
						if (node->left->isNumberValue() == node->right->isNumberValue() )
							addError("This operation have not float and int operands");
						else
							addError("This operation have not float and int operand");
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
							/// TODO: ��-�������� �� ���������� ����� ��������
					} else if( node->left->returnType->varType == TYPE_POINTER && node->right->returnType->varType == TYPE_POINTER) {
						/// TODO: ��-�������� �� ���������� ����� �������� � ��������� ���������
					} else {
						addError("Can`t compare");
					}

				} else if( node->isBinnaryLogical() ) {
					//TODO:: ���� �������� ��� (a != nil) && YES
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
					//TODO:: ���� �������� ���
				} else if ( node->operationType == OperationType::OP_ASSIGN) {
					retType = new TypeNode( *node->right->returnType);
				}
			}

        }
        return retType;
    }

    void visit( ExprNode* node) override {
        RETURN_IF_NODE_NULL;
        
        if ( node->returnType){
            return;
        }

        NodeVisiter::visit( node);

        TypeNode* retType = new TypeNode();
        
        if( node->exprType == ExprType::EXPR_OPERATION) {
            retType = calcOperation( node);
        } 
        else if ( node->exprType == ExprType::EXPR_FUNC_CALL ) {
            auto ifunc = functions.find( node->name);
            if( ifunc != functions.end()){
                /// TODO:: ���-�� ��������� ����������� ����������
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
                    
                    //���������, ����� ���� �� �� ���� ����� �����
                    auto varNameClass = classes.find( node->object->name);
                    bool isStatic = varNameClass != classes.end(); 
                    if( isStatic ) {
                        auto staticMethod = varNameClass->second->staticMethods.find( node->name);
                        isStatic = staticMethod != varNameClass->second->staticMethods.end(); 
                        if( isStatic ){
                            meth = staticMethod->second;
                        }
                    } 
                    if( !isStatic)
                        addError(string("Unknown local method: ") + iclassinfo->name + "::" + node->name );
                }
            } else {
				addError(string("Can`t call method " + node->name + " from variable " + node->object->name));
            }
            if( meth) {
                retType = meth->returnType.toNode();
            } else {
                addError(string("Can`t calc Method Return TYPE!!!!!!!!!!!!!!!"));
            }
        } else if ( node->exprType == ExprType::EXPR_INVAR_CALL ) {
            if(node->object->returnType->varType == TYPEE_CLASS) {
                addError("can`t get static field");
            } else if (node->object->returnType->varType == TYPE_CUSTOM) {
                //TODO:: � ���� ���� �����?
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


            retType = new TypeNode(*node->right->returnType);
        } 
        else if ( node->exprType == ExprType::EXPRE_CLASS_FIELD_ASSIGN) {
            retType = new TypeNode(*node->right->returnType->childType);
        }
        else if ( node->exprType == ExprType::EXPR_ARRAY_ELEM_CALL ) {
            if (node->left->returnType->childType)
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