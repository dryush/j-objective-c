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

int getNextId() {
    
    return max_id ++;
}

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

}

void print( Extern_code_st* st){
    if( st == NULL )
        return;
    ids[st] = getNextId();
    labels[st] = "Ѕла бла бла";
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
    }
}
