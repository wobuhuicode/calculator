#include "Parser.h"
#include <iostream>
using namespace std;
node* Parser::expr() 
{
	node* the_root = term();
	for (;;) 
	{
		switch (the_expr.get_tokentype())
		{
		case Lexer::PLUS:
			the_root = new node(0, Lexer::PLUS, the_root, term()); break;
		case Lexer::MINUS:
			the_root = new node(0, Lexer::MINUS, the_root, term()); break;
		case Lexer::End: case Lexer::RB:
			return the_root;
		default:
			break;
		}
	}
}

node* Parser::term() {
	node* the_term = prim();
	for (;;) 
	{
		switch (the_expr.get_tokentype())
		{
		case Lexer::MUL:
			the_term = new node(0, Lexer::MUL, the_term, prim()); break;
		case Lexer::DIV:
			the_term = new node(0, Lexer::DIV, the_term, prim()); break;
		default:
			return the_term;
		}
	}
}

node* Parser::prim() {
	node* the_prim;
	the_expr.get_token();
	if (the_expr.get_tokentype() == Lexer::NUMBER) {
		the_expr.get_token();
		return the_prim = new node(the_expr.get_number(), Lexer::NUMBER);
	}
	else if (the_expr.get_tokentype() == Lexer::LB) {
		the_prim = expr(); 
		the_expr.get_token();
		return the_prim;
	}else ;
}