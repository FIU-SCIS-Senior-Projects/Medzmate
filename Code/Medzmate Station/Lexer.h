#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct Token {
	char value;
        bool empty;
};

class Lexer
{
	bool skip(char c);

public:
	Lexer();
	Lexer(string file_name);
	Token Next();
	Token Peek();
	Token Get();
	void Match(string match);
	void Close();
};

