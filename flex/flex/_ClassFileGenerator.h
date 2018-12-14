#pragma once
#include "TableFiller.h"
#include <fstream>
#include <string>

#define MY_DEBUG 0

template< typename TNumberType>
class U{
    union {
        TNumberType number;
        char bytes[sizeof(TNumberType)];
    } u;
public:
    U( TNumberType num){
        u.number = num;

    }
    
    U() {
        this->u.number = 0;
    }
    string toBytes(){
        int bl = sizeof(TNumberType);
        string bytes( bl, 0);
        for( int i = 0; i < bl; i++){
            bytes[ i] = this->u.bytes[bl- i - 1];
        }
        return bytes;
    }
};

class U4 : public U <int> {
public:
    U4():U(){
    }

    U4( int num):U(num){
    }

};

class U2 : public U <short int> {
public:
    U2():U(){
    }

    U2( short int num):U(num){
    }

};

class U1 : public U <char> {
public:
    U1():U(){
    }

    U1( char num):U(num){
    }

};

class ClassFileGenerator { 

protected:

    JavaConstantTable* table;

    string genMagicNumber(){
        long int n = 0xCAFEBABE;
        return U4(n).toBytes();
    }

    string genVersion(){
        string ver;
        ver.resize(4);
        ver[0] = 0;
        ver[1] = 0;
        ver[2] = 0;
        ver[3] = 0x34;
        return ver;
    }

    string genConstantSizePool(){
#if MY_DEBUG
        return U2(0).toBytes();
#endif
        return U2( this->table->records.size()).toBytes();
    }

    string genConstantPool(){
#if MY_DEBUG
        return "";
#endif        
        string consts;
        vector<JavaTableRecord> records( ++table->records.begin(), table->records.end());
        FOR_EACH( c, records){
            if( c->constantType == CONSTANT_UTF8){
                consts += U1(1).toBytes() + U2( c->strvalue.size()).toBytes() + c->strvalue;
            } else if ( c->constantType == CONSTANT_Integer){
                consts += U1(3).toBytes()  + /**S2**/ U2( c->intvalue).toBytes();
            } else if ( /*c->constantType  == CONSTANT_String*/ false) {

            } else if ( c->constantType == CONSTANT_NameAndType) {
                consts += U1(12).toBytes() + U2( c->twointvalue.first).toBytes() + U2( c->twointvalue.second).toBytes();
            } else if ( c->constantType == CONSTANT_Class) {
                consts += U1(7).toBytes() + U2( c->intvalue).toBytes();
            } else if( c->constantType == CONSTANT_Fieldref) {
                consts += U1(9).toBytes() + U2( c->twointvalue.first).toBytes() + U2( c->twointvalue.second).toBytes();
            } else if( c->constantType == CONSTANT_Methodref) {
                consts += U1(10).toBytes() + U2( c->twointvalue.first).toBytes() + U2( c->twointvalue.second).toBytes();
            }
        }
        return consts;
    }

    string genAccessFlags(){
        return U2( ACC_PUBLIC).toBytes();
    }
    string genThisClass(){
        return U2( table->classconst).toBytes();
    }

    string genSupperClass(){
        return U2( table->superclassconst).toBytes();
    }

    string genInterfacesCount(){
        return U2(0).toBytes();
    }

    string genInterfaces(){
        return "";
    }

    string genFieldsCount(){
#if MY_DEBUG
        return U2(0).toBytes();
#endif
        return U2( this->table->fieldsTable.size()).toBytes();
    }

    string genFields(){
#if MY_DEBUG
        return "";
#endif
        string fs;
        FOR_EACH( field, table->fieldsTable){
            fs += U2( field->access).toBytes() + U2( field->nameId).toBytes() 
                + U2( field->descriptorId).toBytes() + U2(0).toBytes();
        }
        return fs;
    }

    string genMethodsCount(){
#if MY_DEBUG
        return U2(0).toBytes();
#endif
        return U2( table->methodsTable.size()).toBytes();
    }

    string genMethods() {
#if MY_DEBUG
        return "";
#endif
        string ms;
        FOR_EACH( method, table->methodsTable) {
            ms += U2( method->access).toBytes() + U2( method->nameId).toBytes()
                + U2( method->descriptorId).toBytes() + U2(0).toBytes();
        }
        return ms;
    }

    string genAttributesCount(){
        return U2(0).toBytes();
    }

    string genAttributes(){
        return "";
    }

    string gen(){
        string str;
        if( ! this->table->isDefault) {
            str += this->genMagicNumber();
            str += this->genVersion();
            str += this->genConstantSizePool();
            str += this->genConstantPool();
            str += this->genAccessFlags();
            str += this->genThisClass();
            str += this->genSupperClass();
            str += this->genInterfacesCount();
            str += this->genInterfaces();
            str += this->genFieldsCount();
            str += this->genFields();
            str += this->genMethodsCount();
            str += this->genMethods();
            str += this->genAttributesCount();
            str += this->genAttributes();
        } else {
            //TODO:: стандартную либу прикрутить
        }
        return str;

    }

public:
    
    string sourceDir ;

    ClassFileGenerator(){
        this->sourceDir = "./source";
    }

    void setClass( JavaConstantTable* table){
        this->table = table;
    }

    void genClassFiles( vector< JavaConstantTable*>& classes){
        ofstream file;
        FOR_EACH( info, classes){
            this->setClass( *info);
            string classname = (*info)->classname;

            string path = this->sourceDir + "/" + classname + ".class";
            file.open( path, std::ios::out | std::ios::binary);
            if( file.is_open()){
                string str = gen();
                for( int i =0; i < str.size(); i++){
                    char ch = str[i];
                    file << ch;
                }
                file.close();
            } else {
                throw "Can`t create or open class file";
            }
            //Записать в файл
        }
    }
};