// flex.cpp: ���������� ����� ����� ��� ����������� ����������.
//

extern int yyparse(void);
extern int yylex(void)

#include "struct_print.h"
#include "objectivec.tab.h"
#include "lex.yy.c"
#include <locale.h>
#include <string>


int main()
{
	setlocale(LC_ALL, "russian");
	char * l = setlocale(LC_ALL, NULL);
	freopen("output.txt", "w", stdout);
	yyin = fopen("test.m", "r");
	yyparse();
}

