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
#include "ArrayAndFieldAssignTransform.h"
#include "TableFiller.h"
#include "PrintNodes.h"
#include "VariableTypeChecker.h"
#include "TypeCalculation.h"
#include "PointerChecker.h"
#include "ReturnChecker.h"

using namespace std;

extern struct Program_st* root;

int main(int argc, char *argv[]) {
    
	//freopen("output.txt", "w", stdout);
	yyin = fopen("test.m", "r");
	yyparse();
	printf("\n\n");
	print(root);
	ProgramNode* prog = new ProgramNode(root);
    //prog->visit( new PrintNodes()); 
    //system("graphSemantic.bat");

	vector<NodeVisiter*> visiters;

	visiters.push_back( new FunctionAndMethodsLocalVarChecker());
	visiters.push_back( new ArrayAndFieldAssignTransform());
    visiters.push_back( new ClassTableFiller());
	visiters.push_back( new PointerChecker());
	visiters.push_back( new TableFiller());
    // ������� ����������� "������", ����������� �� ���������� ����������
	visiters.push_back( new TypeCalculation());
	visiters.push_back( new VariableTypeChecker());
	visiters.push_back( new ReturnChecker());
	visiters.push_back( new JVMTableFiller());
	visiters.push_back( new PrintNodes());
    //prog->visit( visiters.back());
    try{
        FOR_EACH( ivisiter, visiters){
	        prog->visit(*ivisiter);
	        //auto test = (*++prog->functions[0]->body->childs.begin())->expr;
	        delete*ivisiter;
        }
    } catch ( ...) {
        printf("COMPLITION STOPPED!!!\n");

    }
	freopen("CON","w", stdout);
    if( errors.size() > 0){
        for( auto ierror = errors.begin(); ierror != errors.end(); ierror++){
            cout << *ierror << endl;
        }
    }
    
	freopen("table.csv","w", stdout);
    FOR_EACH( cl, classes){
        cout << cl->second->name << endl;
        cout << cl->second->table->to_csv_string() << endl;
    }
    //execlpe("cmd", "/c", "graph.bat", "", 0,0,0);
    execlpe("cmd", "/c", "graphSemantic.bat", "", 0,0,0);
	
    //system("graphSemantic.bat");
    //system("graph.bat");
	return 0;
}