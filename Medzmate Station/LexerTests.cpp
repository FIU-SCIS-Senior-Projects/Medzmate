#include <iostream>
#include <list>
#include "Lexer.h"


int main(int argc, char **argv) {
    
    // init
    Lexer _lexer = Lexer("LexerTest.json");
    // Next();
    // Peek();
    // Get();
    // Match();
    // release resources
    _lexer.Close();
}