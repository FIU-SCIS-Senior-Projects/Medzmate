#include "Lexer.h"

ifstream ifs;

bool Lexer::skip(char c)
{
	return isspace(c);
}

Lexer::Lexer()
{
}

Lexer::Lexer(string file_name)
{
	const char* cstr = file_name.c_str();
	// load file
	ifs.open(cstr);
}

Token Lexer::Get() {
	if (ifs.good()) {
		char c = ifs.get();
		// it's a valid token
		Token t = Token();
		t.value = c;
		return t;
	}
	else {
		return Token();
	}
}

Token Lexer::Next()
{	
	if (ifs.good()) {
		char c = ifs.get();
		// skip empty spaces, tabs, and line breakers
		while (skip(c)) {
			c = ifs.get();
		}
		// it's a valid token
		Token t = Token();
		t.value = c;
		return t;
	}
	else {
		return Token();
	}
return Token();	
}

Token Lexer::Peek()
{
	if (ifs.good()) {
		char c = ifs.peek();
		// skip empty spaces, tabs, and line breakers
		while (skip(c)) {
			c = ifs.get();
			c = ifs.peek();
		}
		// it's a valid token
		Token t = Token();
		t.value = c;
		return t;
	}
	else {
		return Token();
	}
return Token();
}

void Lexer::Match(string match)
{
	for (int i = 0; match[i] != '\0'; i++) {	
		Token t = Next();
		if (match[i] != t.value)
			printf("Lexer Error Matching");
	}
}

void Lexer::Close()
{
	ifs.close();
}
