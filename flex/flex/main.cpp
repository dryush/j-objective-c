#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <process.h>

#include <codecvt>

#include "ProgramNode.h"
#include "struct_print.h"
#include "objectivec.tab.c"
#include "lex.yy.c"

#include "_ClassFileGenerator.h"

#include "UnsupportChecker.h"
#include "FunctionLocalVarChecker.h"
#include "ArrayAndFieldAssignTransform.h"
#include "TableFiller.h"
#include "PrintNodes.h"
#include "VariableTypeChecker.h"
#include "TypeCalculation.h"
#include "PointerChecker.h"
#include "ReturnChecker.h"
#include "FunctionCallChecker.h"

#include "Super.h"

using namespace std;

extern struct Program_st* root;

namespace Win {
#include <Windows.h>
};


void dprint( const string& str){
	cout << str <<endl;
}

int main(int argc, char *argv[]) {
    
	//freopen("output.txt", "w", stdout);
 	
	if( argc > 1){
		yyin = fopen(argv[1], "r");
		dprint(string("open file: ") + string(argv[1]));
	}
	else {
		yyin = fopen("test.m", "r");
		dprint(string("open file: ") + string("test.m"));
	}
	yyparse();
	dprint(string("End parsing"));
	printf("\n\n");
	//print(root);
	dprint(string("Start semantic"));
	ProgramNode* prog = new ProgramNode(root);
    //prog->visit( new PrintNodes()); 
    //system("graphSemantic.bat");

	vector<NodeVisiter*> visiters;

	//visiters.push_back( new UnsupportChecher());
	visiters.push_back( new FunctionAndMethodsLocalVarChecker());
	visiters.push_back( new ArrayAndFieldAssignTransform());
    visiters.push_back( new ClassDeclarationTableFiller());
    visiters.push_back( new ClassImplementationTableFiller());
	visiters.push_back( new PointerChecker());
	visiters.push_back( new ThisRetType());
	visiters.push_back( new TableFiller());
	visiters.push_back( new SuperChecker());
	visiters.push_back( new ThisMethodCallChecker());
	visiters.push_back(new                    ClassImplementationTableChecker());
    // ������� ����������� "������", ����������� �� ���������� ����������
	visiters.push_back( new TypeCalculation());
    
    visiters.push_back( new FunctionCallChecker());

	visiters.push_back( new VariableTypeChecker());
	visiters.push_back( new ReturnChecker());
	
    //visiters.push_back( new TypeCalculation());
    
    visiters.push_back( new JVMTableFiller());
	visiters.push_back( new PrintNodes());
    //prog->visit( visiters.back());
   
    FOR_EACH( ivisiter, visiters){
	    prog->visit(*ivisiter);
	    //auto test = (*++prog->functions[0]->body->childs.begin())->expr;
        //auto test = (*++prog->functions[0]->body->childs.begin())->expr->right->returnType;
	    delete*ivisiter;
		freopen("CON","w", stdout);
		if( errors.size() > 0){
			for( auto ierror = errors.begin(); ierror != errors.end(); ierror++){
				cout << *ierror << endl;
			}
			dprint(string("Compilation stopped"));
			getch();
			return 0;
		}
    }
    


	/*
	freopen("table.csv","w", stdout);
    FOR_EACH( cl, classes){
        cout << cl->second->name << endl;
        cout << cl->second->table->to_csv_string() << endl;
    }
    */
    
    vector<JavaConstantTable*> tbls;
    FOR_EACH( cl, classes){
        tbls.push_back( cl->second->table);
    }

    ClassFileGenerator fileGen;
    
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    Win::CreateDirectoryW( converter.from_bytes( "./" + fileGen.sourceDir).c_str(), 0);
    fileGen.genClassFiles( tbls);
    //execlpe("cmd", "/c", "graph.bat", "", 0,0,0);
    //execlpe("cmd", "/c", "graphSemantic.bat", "", 0,0,0);
//	execlpe("cmd", "/c", "./source/javaCompiler.bat", "", 0,0,0);
	//system("graphSemantic.bat");
    //system("graph.bat");
	//freopen("CON","w", stdout);
	//freopen("CON","r", stdin);
	//system("javaCompiler.bat");
	
	dprint(string("Compilation end"));
	return 0;
}