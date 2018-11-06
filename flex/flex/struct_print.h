#include <unordered_map>
#include <map>
#include <string>
#include <vector>

#include "tree_structs.h"

<<<<<<< HEAD
using namespace std;

int max_id = 1;
unordered_map<void*, int> ids;
unordered_map<void*, string> labels;
unordered_map<void*, vector<void*>> g;
=======
int max_id = 0;
int lvl = 0; // —É—Ä–æ–≤–µ–Ω—å –≥–ª—É–±–∏–Ω—ã

void printSpaces() {
    for (int i = 0 ; i < lvl; i++) {
        printf(" ");
    }
}
>>>>>>> e1a9a4418ba2ec6f06bbf14e9778497581054860

int getNextId() {
    return max_id ++;
}

<<<<<<< HEAD
void initId() {

}

void print( Class_declaration_st* st){
    ids[st] = getNextId();

}

void print( Class_impl_st* st ){
    ids[st] = getNextId();

}

void print( Enum_declaration_st* st){
    ids[st] = getNextId();

}

void print( Func_declaration_st* st){
    ids[st] = getNextId();

}

void print( Func_impl_st* st){
    if( st == NULL )
        return;
    ids[st] = getNextId();
=======
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
                printf("Var_decl_stmt %s\n", st->name);
                print(st->var_type);
                print(st->array_constant);
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
                printf(st->truth_stmt_list);
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
    //ids[st] = getNextId();

}

void print( Func_declaration_st* st) {
    //ids[st] = getNextId();
    if (st != NULL) {
        printSpaces();
        printf("Func_decl function %s()\n", st->name);
        lvl++;
        // print( st->return_type);
        // printf( "function %s()\n", st->name);
        // print( st->args);
        lvl--;
    }
}
>>>>>>> e1a9a4418ba2ec6f06bbf14e9778497581054860

void print( Func_impl_st* st) {
    //ids[st] = getNextId();
    if (st != NULL) {
        printSpaces();
        printf("Func_impl function %s()\n", st->name);
        lvl++;
        // print( st->return_type);
        // printf( "function %s()\n", st->name);
        // print( st->args);
        // print( st->body);
        lvl--;
    }
}

<<<<<<< HEAD
void print( Extern_code_st* st){
    if( st == NULL )
        return;
    ids[st] = getNextId();
    labels[st] = "¡Î‡ ·Î‡ ·Î‡";
    g[st].push_back( st->class_decl);
    print( st->class_decl);
    print( st->class_impl);
    print( st->enum_decl);
    print( st->func_decl);
    print( st->func_impl);
    
}

void print( Program_st* st ){
    ids[st] = getNextId();
    print( st->code);
    if( st->next) {
        print( st->next);
=======
void print( Extern_code_st* st) {
    //ids[st] = getNextId();
    if (st != NULL) {
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
    //ids[st] = getNextId();
    printSpaces();
    printf("Program");
    if (st != NULL) {
        lvl++;
        print( st->code);
        if( st->next) {
            print( st->next);
        }
        lvl--;
>>>>>>> e1a9a4418ba2ec6f06bbf14e9778497581054860
    }
}
