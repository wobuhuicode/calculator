#include "Lexer.h"
#include <string>
using namespace std;

Lexer::Token_Type Lexer::get_token(){
//	delete curr_number;
	string ch;
	switch (*expr) {
	case '+': expr++; return curr_T = PLUS;
	case '-': expr++; return curr_T = MINUS;
	case '*': expr++; return curr_T = MUL;
	case '/': expr++; return curr_T = DIV;
	case '\0': expr++; return curr_T = End;
	case '(': expr++; return curr_T = LB;
	case ')': expr++; return curr_T = RB;
	case '0':case '1':case '2':case '3':case '4':
	case '5':case '6':case '7':case '8':case '9':
		ch += *expr;
		do {
			if (*(expr+1) >= '0' && *(expr+1) <= '9' || *(expr+1) == '.') {
				ch += *(++expr);
			}
			else  break;
		} while (true);
		curr_number = new float;
		*curr_number = stof(ch);
		expr++; return curr_T = NUMBER;
	default:
		return curr_T = Not_Define;
	}
} //»ñÈ¡
