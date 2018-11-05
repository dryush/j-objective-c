%{
	#define YY_NO_UNISTD_H 0
 	#include "tree_structs.h"
 	#include "objectivec.tab.h"

    #include <math.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <conio.h>
    #include <locale.h>

	
	extern int yyparse(void);
		
	void addToBuffer( char* str);
	void addToBufferOcto( char* str, int line);
	void addToBufferHex( char* str, int line);
	void clearBuffer();
	void endChar(int line);
	void handleToken(char * name, char * value, int startPos);
	int handleTokenInt(char * text, int system);
	void handleError(char * error, int line);


	int start = 0;
	char buffer[100000];
%}

%option noyywrap
%option never-interactive
%option yylineno

DIGIT	[0-9]
LETTER	[A-Za-z_]
CHAR_ [^\\\'\"\n]
WS	[ \t\n]
ID {LETTER}({LETTER}|{DIGIT})*

INT_10    		 ([1-9][0-9]*)|0
INT_16    		 0[xX][0-9a-fA-F]+
INT_8    		 	 0[0-7]+
FLOAT     		 ({DIGIT}*\.{DIGIT}+)|({DIGIT}+[\.]{DIGIT}*)
EXPONENT         		 (({DIGIT}*|{FLOAT})[eE][+-]?{DIGIT}+)

ONE_LINE_COMMENT \/\/.*\n

%x STRING_
%x MULTILINE_COMMENT
%x CHAR_
%x OCTO_CHAR


%%
%{

%}

{WS} 	{}

"/*"					{ BEGIN(MULTILINE_COMMENT); start = yylineno; }
<MULTILINE_COMMENT>[^*]*		{ addToBuffer(yytext); }
<MULTILINE_COMMENT>"*"+[^*/]* 	{ addToBuffer(yytext); }
<MULTILINE_COMMENT>"*"+"/" 		{ BEGIN(INITIAL);}
<MULTILINE_COMMENT><<EOF>> 		{ BEGIN(INITIAL); handleError("unterminated multiline_comment", start);}

\'					{ BEGIN(CHAR_); clearBuffer(); }
\"					{ BEGIN(STRING_); clearBuffer(); }
<CHAR_>{CHAR_}{CHAR_} 	{ BEGIN(INITIAL); handleError("More then one char in \'\'", yylineno); }
<CHAR_,STRING_>\\a			{ addToBuffer("\a"); }
<CHAR_,STRING_>\\b			{ addToBuffer("\b"); }
<CHAR_,STRING_>\\f			{ addToBuffer("\f"); }
<CHAR_,STRING_>\\n			{ addToBuffer("\n"); }
<CHAR_,STRING_>\\r			{ addToBuffer("\r"); }
<CHAR_,STRING_>\\t			{ addToBuffer("\t"); }
<CHAR_,STRING_>\\v			{ addToBuffer("\v"); }
<CHAR_,STRING_>\\\"			{ addToBuffer("\""); }
<CHAR_,STRING_>\\\'			{ addToBuffer("\'"); }
<CHAR_,STRING_>\\\?			{ addToBuffer("\?"); }
<CHAR_,STRING_>\\\\			{ addToBuffer("\\"); }
<CHAR_,STRING_>\\0				{ addToBuffer("\0"); }
<CHAR_,STRING_>\\[0-7]{1,3}		{ addToBufferOcto(yytext+1, yylineno); }
<CHAR_,STRING_>\\x[0-9a-fA-F]+	{ addToBufferHex(yytext, yylineno);}
<CHAR_,STRING_>{CHAR_}			{ addToBuffer(yytext); }
<CHAR_,STRING_>\\x				{ BEGIN(INITIAL);handleError("Expected hexadecimal number ", yylineno);}
<STRING_>\\\n			{ ; /*Ничего*/}
<CHAR_>\n				{ BEGIN(INITIAL); handleError("Expected \' ", yylineno); }
<STRING_>\n				{ BEGIN(INITIAL); handleError("Expected \" ", yylineno); }
<CHAR_>\' 				{ BEGIN(INITIAL); yylval.char_const=buffer[0]; return CHAR_CONST; }
<STRING_>\"				{ BEGIN(INITIAL); strcpy(yylval.string_const,buffer); return STRING_CONST; }


%{ /* Наверное константы, а не названия типов, назвать const_int, const_float, const_string, const_char */ %}

"void"		{ return VOID; }
"int"		{ return INT; }
"float"		{ return FLOAT; }
"char"		{ return CHAR_; }

"enum"		{ return ENUM; }

"if"		{ return IF; }
"else"		{ return ELSE; }

"while"		{ return WHILE; }
"do"		{ return DO; }

"return"	{ return RETURN; }

"@interface" 		{ return INTERFACE; }
"@implementation" 	{ return IMPLEMENTATION; }
"@end" 				{ return END; }

"@private" 		{ return PRIVATE; }
"@protected" 	{ return PROTECTED; }
"@public" 		{ return PUBLIC; }

"YES" 			{ yylval.bool_const = 1; return BOOL_CONST; }
"NO" 			{ yylval.bool_const = 0; return BOOL_CONST; }

{ID} 		{ yylval.id = yytext; return ID; }
{INT_10} 	{ yylval.int_const=atoi(yytext); return INT_CONST; };
{INT_16} 	{ yylval.int_const=handleTokenInt(yytext, 16); return INT_CONST; }; 
{INT_8} 	{ yylval.int_const=handleTokenInt(yytext, 8); return INT_CONST; };
{FLOAT}		{ yylval.float_const=atof(yytext); return FLOAT_CONST; }

{ONE_LINE_COMMENT} { }


"="			{ return '='; }

"+"			{ return '+'; }
"-"			{ return '-'; }
"*"			{ return '*'; }
"/"			{ return '/'; }
"%"			{ return '%'; }


"=="		{ return EQUAL; }
"<"			{ return '<'; }
"<="		{ return LESS_OR_EQUAL; }
">"			{ return '>'; }
">="		{ return GREATER_OR_EQUAL; }
"!="		{ return NOT_EQUAL; }
"!"			{ return '!'; }

"\|\|"		{ return OR; }
"&&"		{ return AND; }

"->"		{ return ARROW; }

"\["		{ return '['; }
"\]"		{ return ']'; }
"("			{ return '('; }
")"			{ return ')'; }
"{"			{ return '{'; }
"}"			{ return '}'; }
";"			{ return ';'; }
","			{ return ','; }

'\.'		{ return '.'; }
. 			{ handleToken("unknown character", yytext, yylineno); }

%%

void addToBuffer( char* str){
	strcat(buffer, str);
}

void addToBufferOcto( char* str, int line){
	int num = strtol(str, NULL, 8);
	if ( num > 255){
		handleError("too big number for char", line);
	}
	else {
		char sub[2];
		sub[0] = (char)num;
		sub[1] = 0;
		strcat(buffer, sub);
	}
}

void addToBufferHex( char* str, int line){
	char * buf = (char *)malloc(strlen(str));
	strcpy(buf, str);
	buf[0] = '0';
	int num = strtol(buf, NULL, 16);
	if ( num > 255){
		handleError("too big number for char", line);
	}
	else {
		char sub[2];
		sub[0] = (char)num;
		sub[1] = 0;
		strcat(buffer, sub);
	}
}


void clearBuffer(){
	buffer[0] = 0;
}

void endChar(int line){
	if ( strlen(buffer) == 0){
		handleError("Empty char",line);
	} else {
		handleToken("char", buffer, line);
	}
}

void handleToken(char * name, char * value, int startPos){
	printf("Founed: %s at line %d \nvalue: %s\n\n", name, startPos, value);
} 

int handleTokenInt(char * text, int system) {
	char numstr[40];
	int num = strtol(text, NULL, system);
	return num;
}

void handleError(char * error, int line){
	printf("Error at line %d: %s\n\n",line, error);
} 

int main(int argc, char *argv[]) {
    
	setlocale(LC_ALL, "russian");
	char * l = setlocale(LC_ALL, NULL);
	freopen("output.txt", "w", stdout);
	yyin = fopen("test.m", "r");
	yyparse();

	return 0;
}