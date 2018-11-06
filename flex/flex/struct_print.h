#include <unordered_map>
#include <map>
#include <string>
#include <vector>

#include "tree_structs.h"

int max_id = 0;
int lvl = 0; // уровень глубины

void printSpaces() {
    for (int i = 0 ; i < lvl; i++) {
        printf(" ");
    }
}

int getNextId() {
    return max_id ++;
}

void print( Class_declaration_st* st){
    //ids[st] = getNextId();

}

void print( Class_impl_st* st ){
    //ids[st] = getNextId();

}

void print( Enum_declaration_st* st){
    //ids[st] = getNextId();

}

void print( Func_declaration_st* st){
    //ids[st] = getNextId();

}

void print( Func_impl_st* st){
    //ids[st] = getNextId();
    if (st != NULL) {
        lvl++;
       // print( st->return_type);
        printf( "function %s()\n", st->name);
        //print( st->args);
       // print( st->body);
        lvl--;
    }
}

void print( Extern_code_st* st){
    //ids[st] = getNextId();
    printSpaces();
    printf("Extern code\n");
    if (st != NULL) {
        lvl++;
        print( st->class_decl);
        print( st->class_impl);
        print( st->enum_decl);
        print( st->func_decl);
        print( st->func_impl);
        lvl--;
    }
}

void print( Program_st* st ){
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
    }
}
