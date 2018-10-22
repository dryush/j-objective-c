// flex.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "lex.yy.c"
#include <locale.h>
#include <string>

 
void _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "russian");
	char * l = setlocale(LC_ALL, NULL);
	freopen("output.txt", "w", stdout);
	yyin = fopen("test.m", "r");
	yylex();
}

