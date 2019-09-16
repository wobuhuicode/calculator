#pragma once
#include "Lexer.h"
class node
{
public:
	Lexer::Token_Type node_type;
	node* lc;
	node* rc;
	float number;
	node(float num = 0, Lexer::Token_Type type = Lexer::Not_Define, node * lchild = nullptr, node * rchild = nullptr)
		:lc(lchild), rc(rchild), number(num), node_type(type) {};
	float value();
};

