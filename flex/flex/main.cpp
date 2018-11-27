

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <process.h>

#include "ProgramNode.h"
#include "struct_print.h"
#include "objectivec.tab.c"
#include "lex.yy.c"

#include "FunctionLocalVarChecker.h"

using namespace std;

extern struct Program_st* root;

int main(int argc, char *argv[]) {
    
	//freopen("output.txt", "w", stdout);
	yyin = fopen("test.m", "r");
	yyparse();
	printf("\n\n");
	//print(root);
	ProgramNode* prog = new ProgramNode(root);
    FunctionAndMethodsLocalVarChecker lvc;
    prog->visit(&lvc);
    if( errors.size() > 0){
        for( auto ierror = errors.begin(); ierror != errors.end(); ierror++){
            cout << *ierror << endl;
        }
    }
    execlpe("cmd", "/c", "graph.bat", "", 0,0,0);
	return 0;
}