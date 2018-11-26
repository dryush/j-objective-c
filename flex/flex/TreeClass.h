#pragma once
#include <string>
#include <list>

using namespace std;

#include "tree_structs.h"
#include "NodeVisiter.h"

list<string> errors;
list<string> warnings;
void addError(string error) {
	errors.push_back(error);
}

void addWarning(string error) {
	errors.push_back(error);
}


class Node {
public:
	void visit(NodeVisiter&);
};

void Node::visit(NodeVisiter& visiter) {
	visiter.visit(this);
}

#include "CommonNodes.h"
#include "ClassNodes.h"
#include "FunctionNodes.h"
#include "ProgramNode.h"