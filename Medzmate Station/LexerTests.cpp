#include <iostream>
#include <list>
#include "Lexer.h"

void TestNext(Lexer _lexer){
    
}

void TestPeek(Lexer _lexer){
    
}

void TestGet(Lexer _lexer){
    
}

void TestMatch(Lexer _lexer){
    
}

int main(int argc, char **argv) {
    cout << "Starting Lexer Tests ...\n";    
    // initialize
    Lexer _lexer = Lexer("LexerTest.json");
    // Next();
    TestNext(_lexer);
    // Peek();
    TestPeek(_lexer);
    // Get();
    TestPeek(_lexer);
    // Match();
    TestMatch(_lexer);
    // release resources
    _lexer.Close();
    cout << "Completing Lexer Tests ...\n"; 
}