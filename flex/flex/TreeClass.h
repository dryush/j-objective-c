#pragma once
#include <string>
#include <list>

using namespace std;

#include "tree_structs.h"



list<string> errors;
list<string> warnings;
void addError(string error) {
	errors.push_back(error);
}

void addWarning(string error) {
	errors.push_back(error);
}

class NodeVisiter;

class Node {
public:
	virtual void visit(NodeVisiter*);
};




