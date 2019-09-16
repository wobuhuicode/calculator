#include "node.h"

float node::value() {
	if (node_type == Lexer::NUMBER) {
		return number;
	}
	switch (node_type)
	{
	case Lexer::PLUS: return lc->value() + rc->value();
	case Lexer::MINUS: return lc->value() - rc->value();
	case Lexer::MUL: return lc->value() * rc->value();
	case Lexer::DIV: return lc->value() / rc->value();
	default:
		break;
	}
}
