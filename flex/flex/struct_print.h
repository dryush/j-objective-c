#include <unordered_map>
#include <map>
#include <string>
#include <vector>

#include "tree_structs.h"

using namespace std;

int max_id = 1;
unordered_map<void*, int> ids;
unordered_map<void*, string> labels;
unordered_map<void*, vector<void*>> g;
int lvl = 0; // уровень глубины

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
        lvl--;
    }
}

void print( Statements_List_st* st) {
    if (st != NULL) {
        printSpaces();
        printf("Statement list\n");
        lvl++;
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
		g[st].push_back(st->return_type);
		g[st].push_back(st->args);
		g[st].push_back(st->body);
        printSpaces();
        printf("Func_impl function %s()\n", st->name);
        lvl++;
        // print( st->return_type);
        // printf( "function %s()\n", st->name);
        // print( st->args);
        print( st->body);
        lvl--;
    }
}

void print( Extern_code_st* st) {
    if (st != NULL) {
		ids[st] = getNextId();
		labels[st] = "Extern code";
		g[st].push_back(st->class_decl);
		g[st].push_back(st->class_impl);
		g[st].push_back(st->enum_decl);
		g[st].push_back(st->func_decl);
		g[st].push_back(st->func_impl);
        printSpaces();
        printf("Extern code\n");
        lvl++;
        print( st->class_decl);
        print( st->class_impl);
        print( st->enum_decl);
        print( st->func_decl);
        print( st->func_impl);
        lvl--;
    }
}

void print( Program_st* st ) {
    printSpaces();
    printf("Program\n");
    if (st != NULL) {
        ids[st] = getNextId();
        labels[st] = "Program";
		g[st].push_back(st->code);
		g[st].push_back(st->next);
        lvl++;
        print( st->code);
        if( st->next) {
            print( st->next);
        }
        lvl--;
    }
}
