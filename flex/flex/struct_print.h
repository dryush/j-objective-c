#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "tree_structs.h"

using namespace std;

int max_id = 1;
unordered_map<void*, int> ids;
unordered_map<void*, string> labels;
unordered_map<void*, vector<void*>> g;
int lvl = 0; // уровень глубины

void printDot() {
    string dot = "digraph Program {\n";
    for( auto i = ids.begin(); i != ids.end(); i++) {
        dot += "\t" + to_string((long long)i->second) + "  [label=\"" + labels[i->first] + "\"];\n"; 
    }
    dot += "\n\n\n";
    for( auto i = g.begin(); i != g.end(); i++){ 
        for( auto in = i->second.begin(); in != i->second.end(); in++) {
            //if ( ids[*in] != 0) {
                dot += "\t" + to_string((long long)ids[i->first]) + "->" + to_string((long long)ids[*in]) + ";\n";
            //}
        }
    }
    dot += "}";
    freopen("graph.txt","w", stdout);
    cout << dot;
}

void printSpaces() {
    for (int i = 0 ; i < lvl; i++) {
        printf(" ");
    }
}

int getNextId() {
    return max_id++;
}

void initId() {

}

void print( Expression_st* st) {
    if (st != NULL) {
        printSpaces();
        lvl++;
        ids[st] = getNextId();
        switch(st->exprType) {
            case EXPR_OPERATION: {
                switch(st->operationType) {
                    case OP_ADD: {
                        labels[st] = "+";
                        g[st].push_back(st->left);
                        g[st].push_back(st->right);
                        print(st->left);
                        print(st->right);
                    }
                    case OP_SUB: {
                        labels[st] = "-";
                        g[st].push_back(st->left);
                        g[st].push_back(st->right);
                        print(st->left);
                        print(st->right);
                    }
                    case OP_MUL: {
                        labels[st] = "*";
                        g[st].push_back(st->left);
                        g[st].push_back(st->right);
                        print(st->left);
                        print(st->right);
                    }
                    case OP_DIV: {
                        labels[st] = "/";
                        g[st].push_back(st->left);
                        g[st].push_back(st->right);
                        print(st->left);
                        print(st->right);
                    }
                    case OP_MOD: {
                        labels[st] = "%";
                        g[st].push_back(st->left);
                        g[st].push_back(st->right);
                        print(st->left);
                        print(st->right);
                    }
                    case OP_ASSIGN: {
                        labels[st] = "=";
                        g[st].push_back(st->left);
                        g[st].push_back(st->right);
                        print(st->left);
                        print(st->right);
                    }
                    case OP_ASSIGN_ARRAY: {

                    }
                    case OP_LESS: {
                        labels[st] = "<";
                        g[st].push_back(st->left);
                        g[st].push_back(st->right);
                        print(st->left);
                        print(st->right);
                    }
                    case OP_LESS_OR_EQUAL: {
                        labels[st] = "<=";
                        g[st].push_back(st->left);
                        g[st].push_back(st->right);
                        print(st->left);
                        print(st->right);
                    }
                    case OP_GREATER: {
                        labels[st] = ">";
                        g[st].push_back(st->left);
                        g[st].push_back(st->right);
                        print(st->left);
                        print(st->right);
                    }
                    case OP_GREATER_OR_EQUAL: {
                        labels[st] = ">=";
                        g[st].push_back(st->left);
                        g[st].push_back(st->right);
                        print(st->left);
                        print(st->right);
                    }
                    case OP_EQUAL: {
                        labels[st] = "==";
                        g[st].push_back(st->left);
                        g[st].push_back(st->right);
                        print(st->left);
                        print(st->right);
                    }
                    case OP_NOT_EQUAL: {
                        labels[st] = "!=";
                        g[st].push_back(st->left);
                        g[st].push_back(st->right);
                        print(st->left);
                        print(st->right);
                    }
                    case OP_LOGICAL_NOT: {
                        labels[st] = "!";
                        g[st].push_back(st->left);
                        print(st->left);
                    }
                    case OP_AND: {
                        labels[st] = "&&";
                        g[st].push_back(st->left);
                        g[st].push_back(st->right);
                        print(st->left);
                        print(st->right);
                    }
                    case OP_OR: {
                        labels[st] = "||";
                        g[st].push_back(st->left);
                        g[st].push_back(st->right);
                        print(st->left);
                        print(st->right);
                    }
                    case OP_UPLUS: {
                        labels[st] = "UPLUS";
                        g[st].push_back(st->left);
                        print(st->left);
                    }
                    case OP_UMINUS: {
                        labels[st] = "UMINUS";
                        g[st].push_back(st->left);
                        print(st->left);
                    }
                    case OP_VALUE: {
                        labels[st] = "Value";
                        switch(st->const_type) {
                            case TYPE_INT: {
                                labels[st] += "Const_Int ";
                            }
                            case TYPE_FLOAT: {
                                labels[st] += "Const_Float ";
                            }
                            case TYPE_CHAR: {
                                labels[st] += "Const_Char ";                                
                            }
                            case TYPE_STRING: {
                                labels[st] += "Const_String ";
                            }
                            case TYPE_BOOL: {
                                labels[st] += "Const_Bool ";                                
                            }
                            case TYPE_CUSTOM: {
                                labels[st] += "Identifier ";                                
                            }
                            case TYPE_POINTER: {
                                labels[st] += "Pointer ";                                
                            }
                        }
                    }
                }
            }
            case EXPR_ARRAY_ELEM_CALL: {
                labels[st] = "Array_elem_call ";
            }
            case EXPR_FUNC_CALL: {
                labels[st] = "Func_call ";
            }
            case EXPR_METHOD_CALL: {
                labels[st] = "Method_call ";
            }
        }
        lvl--;
    }
}

void print( Statements_List_st* st) {
    if (st != NULL) {
        printSpaces();
        printf("Statement list\n");
        lvl++;
        ids[st] = getNextId();
        labels[st] = "Statements_list";
        g[st].push_back(st->stmt);
        g[st].push_back(st->next);
        //print(st->stmt);
        //print(st->next);
        lvl--;
    }
}

void print( Statement_st* st) {
    if (st != NULL) {
        printSpaces();
        lvl++;
        ids[st] = getNextId();
        switch(st->stmt_type) {
            case STMT_WHILE: {
                printf("While_stmt\n");
                labels[st] = "While_stmt";
		        g[st].push_back(st->condition);
                g[st].push_back(st->truth_stmt_list);
                print(st->condition);
                print(st->truth_stmt_list);
                break;
            }
            case STMT_IF: {
                printf("If_stmt\n");
                labels[st] = "If_stmt";
		        g[st].push_back(st->condition);
                g[st].push_back(st->truth_stmt_list);
                g[st].push_back(st->wrong_stmt_list);
                print(st->condition);
                print(st->truth_stmt_list);
                print(st->wrong_stmt_list);
                break;
            }
            case STMT_EXPR: {
                printf("Expr\n");
                labels[st] = "Expr";
		        g[st].push_back(st->expr);
                print(st->expr);
                break;
            }
            case STMT_VAR_DECL: {
                printf("Var_decl_stmt %s\n", st->identifier);
                labels[st] = "Var_decl_stmt " + string(st->identifier);
		        g[st].push_back(st->var_type);
                g[st].push_back(st->array_constant);
                g[st].push_back(st->expr);
               // print(st->var_type);
               // print(st->array_constant);
                print(st->expr);
                break;
            }
            case STMT_RETURN: {
                printf("Return_stmt\n");
                labels[st] = "Return_stmt";
		        g[st].push_back(st->expr);
                print(st->expr);
                break;
            }
            case STMT_COMPOUND: {
                printf("Compound_stmt\n");
                labels[st] = "Compound_stmt";
		        g[st].push_back(st->truth_stmt_list);
                print(st->truth_stmt_list);
                break;
            }
        }
        lvl--;
    }
}

void print( Class_declaration_st* st) {
    if (st != NULL) {
		ids[st] = getNextId();
		labels[st] = "Class_decl class " + string(st->name);
		g[st].push_back(st->methods_declaraion_list);
        g[st].push_back(st->invariants_declaration_list);
        // print(st->methods_declaraion_list);
        // print(st->invariants_declaration_list);
	}
}

void print( Class_impl_st* st ) {
    if (st != NULL) {
		ids[st] = getNextId();
		labels[st] = "Class_impl class " + string(st->name);
		g[st].push_back(st->methods);
        // print(st->methods);
	}
}

void print( Enum_declaration_st* st) {
    if (st != NULL) {
		ids[st] = getNextId();
		labels[st] = "Enum_decl enum " + string(st->identifier);
		g[st].push_back(st->enumerator_list);
        // print(st->enumerator_list);
	}
}

void print( Func_declaration_st* st) {
    if (st != NULL) {
        ids[st] = getNextId();
		labels[st] = "Func_decl function " + string(st->name) + "()";
		g[st].push_back(st->return_type);
		g[st].push_back(st->args);
		printSpaces();
        printf("Func_decl function %s()\n", st->name);
        lvl++;
        // print( st->return_type);
        // printf( "function %s()\n", st->name);
        // print( st->args);
        lvl--;
    }
}

void print( Func_impl_st* st) {
    if (st != NULL) {
		ids[st] = getNextId();
		labels[st] = "Func_impl function " + string(st->name) + "()";
        if( st->return_type){
            g[st].push_back(st->return_type);
            // print( st->return_type);
        }

        if( st->args) {
            g[st].push_back(st->args);
            // print( st->args);
        }

        if( st->body){
            g[st].push_back(st->body);
            print( st->body);
        }
    }
}

void print( Extern_code_st* st) {
    if (st != NULL) {
		ids[st] = getNextId();
		labels[st] = "Extern code";
        if( st->class_decl) {
            g[st].push_back(st->class_decl);
            print( st->class_decl);
        }

        if( st->class_impl) {
            g[st].push_back(st->class_impl);
		    print( st->class_impl);
        }

        if ( st->enum_decl){
            g[st].push_back(st->enum_decl);
            print( st->enum_decl);
        }

        if( st->func_decl){
            g[st].push_back(st->func_decl);
            print( st->func_decl);
        }

        if( st->func_impl){
            g[st].push_back(st->func_impl);
            print( st->func_impl);
        }
    }
}

void print( Program_st* st ) {
    if (st != NULL) {
        ids[st] = getNextId();
        labels[st] = "Program";

        auto next = st;
        while( next){
            g[st].push_back(next->code);
            print( next->code);
            next = st->next;
        }
    }
    printDot();
}
