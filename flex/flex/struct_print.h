#include <unordered_map>
#include <map>
#include <string>
#include <vector>

#include "tree_structs.h"

int max_id = 0;

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

}

void print( Extern_code_st* st){
    //ids[st] = getNextId();
    print( st->class_decl);
    print( st->class_impl);
    print( st->enum_decl);
    print( st->func_decl);
    print( st->func_impl);
    
}

void print( Program_st* st ){
    //ids[st] = getNextId();
    print( st->code);
    if( st->next) {
        print( st->next);
    }
}
