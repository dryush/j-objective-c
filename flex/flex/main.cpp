
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

#include "tree_structs.h"
#include "struct_print.h"
#include "objectivec.tab.c"
#include "lex.yy.c"

extern struct Program_st* root;

int main(int argc, char *argv[]) {
    
	//freopen("output.txt", "w", stdout);
	yyin = fopen("test.m", "r");
	yyparse();
	Program_st* prog = root;
	printf("\n\n");
	print(root);
	return 0;
}