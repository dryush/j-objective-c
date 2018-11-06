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
