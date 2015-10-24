#include "Lexer.h"
#include <list>

struct NameValuePair {
	string name;
	string value;
};

class Parser
{
	Lexer _lexer;
public:
	Parser();
	Parser(string file);
	list <NameValuePair> Start();
	list <NameValuePair> ParsePropertyArray();
	NameValuePair Property();
	list<NameValuePair> Properties();
	NameValuePair ParseNameValuePair();
	string GetName();
	string GetValue();
};

