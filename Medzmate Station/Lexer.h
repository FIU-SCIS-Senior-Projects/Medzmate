#include <fstream>
#include <string>

using namespace std;

struct Token {
	char value;
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

