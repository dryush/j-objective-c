#pragma once
#include "TableFiller.h"
#include <exception>
#include <string>


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

    U2( unsigned short int num):U(num){
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
    virtual string toBytes();
    //virtual int size();
};

class IConst : public JVMCommand {
    char number;
public:
    IConst( char num){
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
    short int num;
public:
    SIPush( short int num) {
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
    char num;
public:
    BIPush( char num) {
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
    char constnum;
public:
    LDC( char constnum) {
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
    short int constnum;
public:
    LDC_W( short int constnum) {
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
    short int constnum;
public:
    ILOAD( short int constnum) {
        this->constnum = constnum;
    }

    string toBytes() override {
        string c;
        c += U1( 0x15).toBytes();
        c += U2( constnum).toBytes();
        return c;
    }
};


class ALOAD : public JVMCommand {
    short int constnum;
public:
    ALOAD( short int constnum) {
        this->constnum = constnum;
    }

    string toBytes() override {
        string c;
        c += U1( 0x19).toBytes();
        c += U2( constnum).toBytes();
        return c;
    }
};



class ISTORE : public JVMCommand {
    short int constnum;
public:
    ISTORE( short int constnum) {
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
    short int constnum;
public:
    ASTORE( short int constnum) {
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
    short int shift;

public:
    IF_ICMP( OperationType compareType, short int shift){
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
    short int shift;
public:
    IF_ACMP( OperationType compareType, short int shift){
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
    short int shift;
public:
    GOTO( short int shift){
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
    short int methodConstNum;
public:
    INVOKE_STATIC( short int methodConstNum){
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
    short int methodConstNum;
public:
    INVOKE_SPECIAL( short int methodConstNum){
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
    short int methodConstNum;
public:
    INVOKE_VIRTUAL( short int methodConstNum){
        this->methodConstNum = methodConstNum;
    }

    string toBytes() override {
        string c;
        c += U1( 0xB7).toBytes();
        c += U2( methodConstNum).toBytes();
        return c;
    }
};