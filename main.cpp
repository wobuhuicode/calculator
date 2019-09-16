#include "Parser.h"
#include <iostream>
using namespace std;
int main() {
	char* test = new char[10];
	cin >> test;
	Parser Ptest(test);
	Ptest.creat_tree();
	cout<<Ptest.get_value();
}