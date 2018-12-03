#pragma once
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "NodeVisiter.h"
#include "ProgramNode.h"
#include "ClassNodes.h"
#include "CommonNodes.h"
#include "FunctionNodes.h"

typedef long long ll;
typedef long double ld;

using namespace std;

class PrintNodes : public NodeVisiter {

public:
    int max_id;
    unordered_map<void*, int> ids;
    unordered_map<void*, string> labels;
    
    struct Edge{
        void* st;
        string label;

        Edge( void* st){ this->st = st;}
        Edge( void* st, string label){ this->st = st; this->label =label; }
        const Edge& operator= (void * st){ this->st = st;}
        static Edge left( void* st) { return Edge(st, "left"); }
        static Edge right( void* st) { return Edge(st, "right"); }
        static Edge numb( void* st, int num) { return Edge(st, to_string((ll)num)); }
    };

    unordered_map<void*, vector<Edge>> g;

    PrintNodes() {
        this->max_id = 1;
    }

    void printDot() {
        string dot = "digraph Program {\n";
        for( auto i = ids.begin(); i != ids.end(); i++) {
            dot += "\t" + to_string((long long)i->second) + "  [label=\"" + labels[i->first] + "\"];\n"; 
        }
        dot += "\n\n\n";
        for( auto i = g.begin(); i != g.end(); i++){ 
            for( auto in = i->second.begin(); in != i->second.end(); in++) {
                if ( ids[in->st] != 0) {
                    dot += "\t" + to_string((long long)ids[i->first]) + "->" + to_string((long long)ids[in->st]) + 
                        + "[label=\"" + in->label +"\"];\n";
                }
            }
        }
        dot += "}";
        freopen("graphSemantic.txt","w", stdout);
        cout << dot;
        //freopen("CON","w", stdout);
    }

    int getNextId() {
        return max_id++;
    }

	void visit( TypeNode* node ) override {
		if (node != NULL) {
			ids[node] = getNextId();
			switch(node->varType) {
				case TYPE_VOID: {
					labels[node] = "void";
					break;
				}
				case TYPE_INT: {
					labels[node] = "int";
					break;
				}
				case TYPE_FLOAT: {
					labels[node] = "float";
					break;
				}
				case TYPE_CHAR: {
					labels[node] = "char";   
					break;
				}
				case TYPE_STRING: {
					labels[node] = "string";
					break;
				}
				case TYPE_BOOL: {
					labels[node] = "bool";  
					break;
				}
				case TYPE_CUSTOM: {
					labels[node] = string(node->name);   
					break;
				}
				case TYPE_POINTER: {
					labels[node] += "* (pointer)";
					g[node].push_back(node->childType);
					node->childType->visit(this);
					break;
				} 
			}
		}
	}

	void visit( FunctionParamNode* node ) override {
		if (node != NULL) {
			ids[node] = getNextId();
			labels[node] = node->name;
			g[node].push_back(Edge(node->type, "type"));
			node->type->visit(this);
		}
	}
	
	// Add statement body
	void visit( FunctionNode* node ) override {
		if (node != NULL) {
			ids[node] = getNextId();
			labels[node] = "Func_impl function " + node->name + "()" ;

			g[node].push_back(Edge(node->returnType, "return type"));
			node->returnType->visit(this);

			g[node].push_back(&(node->params));
			ids[&(node->params)] = getNextId();
			labels[&(node->params)] = "Func_arg_list";
			
			int number = 1;
			for (int i = 0; i < node->params.size(); i++) {
				g[&(node->params)].push_back(Edge::numb(node->params[i], number));
				node->params[i]->visit(this);
				number++;
			}


		}
	}
	
	void printAccess( FieldAccess* access) {
		if (access != NULL) { 
			ids[access] = getNextId();
			switch(*access) {
				case ACCESS_PUBLIC: {
					labels[access] = "Public";
					break;
				}
				case ACCESS_PROTECTED: {
					labels[access] = "Protected";
					break;
				}
				case ACCESS_PRIVATE: {
					labels[access] = "Private";
					break;
				}
			}
		}
	}

	void printMethodType( MethodType* type) {
		if (type != NULL) { 
			ids[type] = getNextId();
			switch(*type) {
				case METHOD_STATIC: {
					labels[type] = "Static";
					break;
				}
				case METHOD_LOCAL: {
					labels[type] = "Local";
					break;
				}
			}
		}
	}

	void visit( ClassFieldDeclarationNode* node ) override {
		if (node != NULL) {
			ids[node] = getNextId();
			labels[node] = node->name;
			g[node].push_back(Edge(node->type, "type"));
			node->type->visit(this);
			
			g[node].push_back(Edge(&(node->access), "access"));
			printAccess(&(node->access));
		}
	}

	void visit( ClassMethodParamNode* node ) override {
		if (node != NULL) {
			ids[node] = getNextId();
			labels[node] = "inner name: " + node->innerName + ", outer name: " + node->outerName;
			g[node].push_back(Edge(node->type, "type"));
			node->type->visit(this);
		}
	}

	void visit( ClassMethodDeclarationNode* node ) override {
		if (node != NULL) {
			ids[node] = getNextId();
			labels[node] = node->name;
			g[node].push_back(Edge(node->returnType, "return type"));
			node->returnType->visit(this);
			
			g[node].push_back(Edge(&(node->access), "access"));
			printAccess(&(node->access));

			g[node].push_back(Edge(&(node->methodType), "method type"));
			printMethodType(&(node->methodType));

			g[node].push_back(&(node->params));
			ids[&(node->params)] = getNextId();
			labels[&(node->params)] = "Method_arg_list";
			
			int number = 1;
			for (auto it = node->params.begin(); it != node->params.end(); it++) {
				g[&(node->params)].push_back(Edge::numb(*it, number));
				(*it)->visit(this);
				number++;
			}
		}
	}

	void visit( ClassDeclarationNode* node ) override {
		if (node != NULL) {
			ids[node] = getNextId();
			labels[node] = "Class_decl class " + node->name;
			if (node->parentName != "") {
				labels[node] += " : " + node->parentName;
			}

			g[node].push_back(&(node->fields));
			ids[&(node->fields)] = getNextId();
			labels[&(node->fields)] = "Fields";

			int number = 1;
			for (auto it = node->fields.begin(); it != node->fields.end(); it++) {
				g[&(node->fields)].push_back(Edge::numb(*it, number));
				(*it)->visit(this);
				number++;
			}

			g[node].push_back(&(node->methods));
			ids[&(node->methods)] = getNextId();
			labels[&(node->methods)] = "Methods";

			number = 1;
			for (auto it = node->methods.begin(); it != node->methods.end(); it++) {
				g[&(node->methods)].push_back(Edge::numb(*it, number));
				(*it)->visit(this);
				number++;
			}
		}
	}

	void printEnumElem( EnumElem* node ) {
		if (node != NULL) {
			ids[node] = getNextId();
			labels[node] = "Enum element " + node->name + " = " + to_string((long long)node->value);
		}
	}

	void visit( EnumNode* node ) override {
		if (node != NULL) {
			ids[node] = getNextId();
			labels[node] = "Enum_decl enum " + node->name ;

			int number = 1;
			for (int i = 0; i < node->elems.size(); i++) {
				g[node].push_back(Edge::numb(&(node->elems[i]), number));
				printEnumElem(&(node->elems[i]));
				number++;
			}
		}
	}

	// add implem class
	void visit( ProgramNode* node ) override {
		if (node != NULL) {
			ids[node] = getNextId();
			labels[node] = "Program";

			int number = 1;
			for (int i = 0; i < node->enums.size(); i++) {
				g[ node ].push_back(Edge::numb(node->enums[i], number));
				node->enums[i]->visit(this);
				number++;
			}

			for (int i = 0; i < node->classDeclarations.size(); i++) {
				g[ node ].push_back(Edge::numb(node->classDeclarations[i], number));
				node->classDeclarations[i]->visit(this);
				number++;
			}

			for (int i = 0; i < node->classImplementations.size(); i++) {
				g[ node ].push_back(Edge::numb(node->classImplementations[i], number));
				//node->classImplementations[i]->visit(this);
				number++;
			}

			for (int i = 0; i < node->functions.size(); i++) {
				g[ node ].push_back(Edge::numb(node->functions[i], number));
				node->functions[i]->visit(this);
				number++;
			}

		}
		printDot();
	}
};