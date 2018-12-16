#pragma once
#include <exception>
#include <string>
#include "TableFiller.h"


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

class U4 : public U <unsigned int> {
public:
    U4():U(){
    }

    U4( unsigned int num):U(num){
    }

};



class U2 : public U <unsigned short int> {
public:
    U2():U(){
    }

    U2( unsigned unsigned short int num):U(num){
    }

};

class U1 : public U <unsigned char> {
public:
    U1():U(){
    }

    U1( unsigned char num):U(num){
    }

};

class S2 : public U <signed short int> {
public:
    S2():U(){
    }

    S2( signed short int num):U(num){
    }

};


class S1 : public U <signed char> {
public:
    S1():U(){
    }

    S1( signed char num):U(num){
    }

};

class JVMCommand {
public:
    virtual string toBytes() =0;
    //virtual int size();
};

class IConst : public JVMCommand {
    char number;
public:
    IConst( unsigned char num){
        if( num < -1 || num > 5)
            throw new runtime_error("IConst > 5 || <-1");
        this->number = num;
    }
    string toBytes() override {
        string c = "";
        c += 0x3 + number;
        return c;
    }
};

class SIPush : public JVMCommand {
    signed short int num;
public:
    SIPush( signed short int num) {
        this->num = num;
    }

    string toBytes() override {
        string c;
        c += 0x10;
        c += S2( num).toBytes();
        return c;
    }
};


class BIPush : public JVMCommand {
    signed char num;
public:
    BIPush( signed char num) {
        this->num = num;
    }

    string toBytes() override {
        string c;
        c += 0x11;
        c += S1( num).toBytes();
        return c;
    }
};
    
class LDC : public JVMCommand {
    unsigned char constnum;
public:
    LDC( unsigned char constnum) {
        this->constnum = constnum;
    }

    string toBytes() override {
        string c;
        c += U1( 0x12).toBytes();
        c += U1( constnum).toBytes();
        return c;
    }
};

  
class LDC_W : public JVMCommand {
    unsigned short int constnum;
public:
    LDC_W( unsigned short int constnum) {
        this->constnum = constnum;
    }

    string toBytes() override {
        string c;
        c += U1( 0x13).toBytes();
        c += U2( constnum).toBytes();
        return c;
    }
};



class ILOAD : public JVMCommand {
    unsigned char constnum;
public:
    ILOAD( unsigned char constnum) {
        this->constnum = constnum;
    }

    string toBytes() override {
        string c;
        c += U1( 0x15).toBytes();
        c += U1( constnum).toBytes();
        return c;
    }
};


class ALOAD : public JVMCommand {
    unsigned char constnum;
public:
    ALOAD( unsigned char constnum) {
        this->constnum = constnum;
    }

    string toBytes() override {
        string c;
        c += U1( 0x19).toBytes();
        c += U1( constnum).toBytes();
        return c;
    }
};



class ISTORE : public JVMCommand {
    unsigned char constnum;
public:
    ISTORE( unsigned char constnum) {
        this->constnum = constnum;
    }

    string toBytes() override {
        string c;
        c += U1( 0x36).toBytes();
        c += U1( constnum).toBytes();
        return c;
    }
};


class ASTORE : public JVMCommand {
    unsigned char constnum;
public:
    ASTORE( unsigned char constnum) {
        this->constnum = constnum;
    }

    string toBytes() override {
        string c;
        c += U1( 0x3A).toBytes();
        c += U1( constnum).toBytes();
        return c;
    }
};



class POP : public JVMCommand {
public:

    string toBytes() override {
        string c;
        c += U1( 0x3A).toBytes();
        return c;
    }
};


class DUP2 : public JVMCommand {
public:

    string toBytes() override {
        string c;
        c += U1( 0x5C).toBytes();
        return c;
    }
};

class IADD : public JVMCommand {
public:

    string toBytes() override {
        string c;
        c += U1( 0x60).toBytes();
        return c;
    }
};

class IMUL : public JVMCommand {
public:

    string toBytes() override {
        string c;
        c += U1( 0x64).toBytes();
        return c;
    }
};

class ISUB : public JVMCommand {
public:

    string toBytes() override {
        string c;
        c += U1( 0x68).toBytes();
        return c;
    }
};

class IDIV : public JVMCommand {
public:

    string toBytes() override {
        string c;
        c += U1( 0x6C).toBytes();
        return c;
    }
};

class IINC : public JVMCommand {
public:

    string toBytes() override {
        string c;
        c += U1( 0x84).toBytes();
        return c;
    }
};


class IF_ICMP : public JVMCommand {
    OperationType compType;
    signed short int shift;

public:
    IF_ICMP( OperationType compareType, signed short int shift){
        this->shift = shift;
        this->compType = compareType;
    }

    string toBytes() override {
        
        string c;
        if( this->compType == OP_EQUAL)
            c += U1( 0x9F).toBytes();
        else if( this->compType == OP_NOT_EQUAL)
            c += U1( 0xA0).toBytes();
        else if( this->compType == OP_LESS)
            c += U1( 0xA1).toBytes();
        else if( this->compType == OP_LESS_OR_EQUAL)
            c += U1( 0xA4).toBytes();
        else if( this->compType == OP_GREATER)
            c += U1( 0xA3).toBytes();
        else if( this->compType == OP_GREATER_OR_EQUAL)
            c += U1( 0xA2).toBytes();
        else throw new runtime_error("IF_ICMP must have compare OP_TYPE");
        c+= S2( shift).toBytes();
        return c;
    }
};


class IF_ACMP : public JVMCommand {
    OperationType compType;
    signed short int shift;
public:
    IF_ACMP( OperationType compareType, signed short int shift){
        this->compType = compareType;
        this->shift = shift;
    }

    string toBytes() override {
        
        string c;
        if( this->compType == OP_EQUAL)
            c += U1( 0xA5).toBytes();
        else if( this->compType == OP_NOT_EQUAL)
            c += U1( 0xA6).toBytes();
        else throw new runtime_error("IF_ACMP must be OP_EQUAL or OP_NOT_EQUAL");
        c+= S2( shift).toBytes();
        return c;
    }
};

class GOTO : public JVMCommand {
    signed short int shift;
public:
    GOTO( signed short int shift){
        this->shift = shift;
    }

    string toBytes() override {
        string c;
        c += U1( 0x84).toBytes();
        c += S2(shift).toBytes();
        return c;
    }
};

class INVOKE_STATIC : public JVMCommand {
    unsigned short int methodConstNum;
public:
    INVOKE_STATIC( unsigned short int methodConstNum){
        this->methodConstNum = methodConstNum;
    }

    string toBytes() override {
        string c;
        c += U1( 0xB8).toBytes();
        c += U2( methodConstNum).toBytes();
        return c;
    }
};


class INVOKE_SPECIAL : public JVMCommand {
    unsigned short int methodConstNum;
public:
    INVOKE_SPECIAL( unsigned short int methodConstNum){
        this->methodConstNum = methodConstNum;
    }

    string toBytes() override {
        string c;
        c += U1( 0xB7).toBytes();
        c += U2( methodConstNum).toBytes();
        return c;
    }
};


class INVOKE_VIRTUAL : public JVMCommand {
    unsigned short int methodConstNum;
public:
    INVOKE_VIRTUAL( unsigned short int methodConstNum){
        this->methodConstNum = methodConstNum;
    }

    string toBytes() override {
        string c;
        c += U1( 0xB7).toBytes();
        c += U2( methodConstNum).toBytes();
        return c;
    }
};

class IRETURN : public JVMCommand {
public:
    string toBytes() override {
        string c;
        c += U1( 0xAC).toBytes();
        return c;
    }
};

/*Размер - на  стеке*/
class NEW_ARRAY : public JVMCommand {
    
    enum {

        T_BOOLEAN = 4,
        T_CHAR = 5,
        T_FLOAT = 6,
        T_DOUBLE = 7,
        T_BYTE = 8,
        T_SHORT = 9,
        T_INT = 10,
        T_LONG = 11
    } type;

public:
    NEW_ARRAY( VarType type){
        if( type == TYPE_BOOL)
            this->type = T_BOOLEAN;
        else if ( type == TYPE_CHAR)
            this->type = T_CHAR;
        else if ( type == TYPE_INT)
            this->type = T_INT;
        else if ( type == TYPE_FLOAT)
            this->type = T_FLOAT;
        else throw new runtime_error("Unsupported array type");
    }

    string toBytes() override {
        string c;
        c += U1( 0xBC).toBytes();
        c += U1( this->type).toBytes();
        return c;
    }
};

class ANEW_ARRAY : public JVMCommand {
    unsigned short int typeNum;
public:
    ANEW_ARRAY( unsigned short int typeNum){
        this->typeNum = typeNum;
    }

    string toBytes() override {
        string c;
        c += U1( 0xBD).toBytes();
        c += U2( this->typeNum).toBytes();
        return c;
    }
};

/*
Стек до команды 
Индекс элемента массива
Ссылка на массив 
*/
class IALOAD : public JVMCommand {
public:
    string toBytes() override {
        string c;
        c += U1( 0x2E).toBytes();
        return c;
    }
};

/*
Стек до команды 
Индекс элемента массива
Ссылка на массив 
*/
class AALOAD : public JVMCommand {
public:
    string toBytes() override {
        string c;
        c += U1( 0x2E).toBytes();
        return c;
    }
};

/*
Стек до команды
Записываемое значение
Индекс элемента массива
Ссылка на массив 
*/
class IASTORE : public JVMCommand {
public:
    string toBytes() override {
        string c;
        c += U1( 0x4F).toBytes();
        return c;
    }
};


/*
Стек до команды
Записываемое значение
Индекс элемента массива
Ссылка на массив 
*/
class AASTORE : public JVMCommand {
public:
    string toBytes() override {
        string c;
        c += U1( 0x53).toBytes();
        return c;
    }
};

