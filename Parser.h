#pragma once
#include "Lexer.h"
#include "node.h"

class Parser
{
private:
	Lexer the_expr;
	node* the_tree = nullptr;
	node* expr();
	node* term();
	node* prim();
public:
	Parser(char* expression) :the_expr(expression) {};
	void creat_tree() {
		the_tree = expr();
	}
	float get_value() {
		return the_tree->value();
	}
};

