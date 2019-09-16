#pragma once

class Lexer
{
public:
	enum Token_Type {
		PLUS, MINUS, MUL, DIV, NUMBER, LB, RB, Not_Define, End
	};
	Lexer(char* expr1) :expr(expr1), curr_T(Not_Define), curr_number(nullptr) {};
	Token_Type get_token();
	float get_number() { return *curr_number; }
	Token_Type get_tokentype() { return curr_T; }
	~Lexer() {};
	char* expr;  //表达式
protected:
	Token_Type curr_T;   //当前类型
	float* curr_number;  //当前值
};

