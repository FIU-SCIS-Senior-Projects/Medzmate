#include "Parser.h"


Parser::Parser()
{
}

Parser::Parser(string file)
{
	_lexer = Lexer(file);
}

list<NameValuePair> Parser::Start()
{
	list<NameValuePair> properties;
	Token token = _lexer.Peek();
	if (token.value == '[') {
		_lexer.Match("[");
		properties = ParsePropertyArray();
		_lexer.Close();
	}
        else if(!token.empty)
		printf("Parsing Error %c\n", token.value);
	return properties;
}

list<NameValuePair> Parser::ParsePropertyArray()
{
	NameValuePair p = Property();
	list<NameValuePair> properties = Properties();
	properties.push_front(p);
	return properties;
}

NameValuePair Parser::Property()
{
	Token token = _lexer.Peek();
	if (token.value == '{') {
		_lexer.Match("{");
		return ParseNameValuePair();
	}
	else
		printf("Parsing Error %c\n", token.value);
	return NameValuePair();
}

list<NameValuePair> Parser::Properties()
{
	Token token = _lexer.Peek();
	if (token.value == ',') {
		_lexer.Match(",");
		NameValuePair p = Property();
		list<NameValuePair> properties = Properties();
		properties.push_front(p);
		return properties;
	}
	else if (token.value == ']') {
		_lexer.Match("]");
		// return empty array
		return list<NameValuePair>();
	}
	else 
		printf("Parsing Error %c\n", token.value);
}

NameValuePair Parser::ParseNameValuePair()
{
	NameValuePair result = NameValuePair();
	// NameValuePair --> "name":"NAME", "value":"VALUE"}
	Token token = _lexer.Next();
	if (token.value != '"')
		printf("Parsing Error %c\n", token.value);
	// see if it's name or value
	token = _lexer.Peek();
	if (token.value == 'n')
	{
		result.name = GetName();
		_lexer.Match(",");
		// "
		_lexer.Next();
		result.value = GetValue();
		_lexer.Match("}");
	}
	else if (token.value == 'v') {
		result.value = GetValue();
		_lexer.Match(",");
		// "
		_lexer.Next();
		result.name = GetName();
		_lexer.Match("}");
	}
	return result;
}

string Parser::GetName()
{
	_lexer.Match("name");
	// "
	_lexer.Next();
	// :
	_lexer.Next();
	// "
	_lexer.Next();
	string name = "";
	Token t = _lexer.Get();
	char c[2];
	c[0] = t.value;
	c[1] = '\0';
	while (t.value != '"') {
		name.append(c);
		t = _lexer.Get();
		c[0] = t.value;
		c[1] = '\0';
	}
	return name;
}

string Parser::GetValue()
{
	_lexer.Match("value");
	// "
	_lexer.Next();
	// :
	_lexer.Next();
	// "
	_lexer.Next();
	string value = "";
	Token t = _lexer.Get();
	char c[2];
	c[0] = t.value;
	c[1] = '\0';
	while (t.value != '"') {
		value.append(c);
		t = _lexer.Get();
		c[0] = t.value;
		c[1] = '\0';
	}
	return value;
}


