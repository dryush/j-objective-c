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
        switch(st->stmt_type) {
            case STMT_WHILE: {
                printf("While_stmt\n");
                print(st->condition);
                print(st->truth_stmt_list);
                break;
            }
            case STMT_IF: {
                printf("If_stmt\n");
                print(st->condition);
                print(st->truth_stmt_list);
                print(st->wrong_stmt_list);
                break;
            }
            case STMT_EXPR: {
                printf("Expr\n");
                print(st->expr);
                break;
            }
            case STMT_VAR_DECL: {
                printf("Var_decl_stmt %s\n", st->identifier);
               // print(st->var_type);
               // print(st->array_constant);
                print(st->expr);
                break;
            }
            case STMT_RETURN: {
                printf("Return_stmt\n");
                print(st->expr);
                break;
            }
            case STMT_COMPOUND: {
                printf("Compound_stmt\n");
                print(st->truth_stmt_list);
                break;
            }
        }
        lvl--;
    }
}

void print( Class_declaration_st* st) {
    //ids[st] = getNextId();

}

void print( Class_impl_st* st ) {
    //ids[st] = getNextId();

}

void print( Enum_declaration_st* st) {
    if (st != NULL) {
		ids[st] = getNextId();
		labels[st] = "Enum_decl enum " + string(st->identifier) + "()";
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
