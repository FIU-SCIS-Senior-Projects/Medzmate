
#include <list>
#include "Lexer.h"

void AssertEqual(char a, char b, string success, string error) {
    if (a != b) {
        cout << error << "\n";
    } else {
        cout << success << "\n";
    }
}

void TestNext() {
    // initialize
    Lexer _lexer = Lexer("TestResources/LexerTest.json");

    Token t = _lexer.Next();
    AssertEqual(t.value, '[', "TestNext Passed", "Failure on Next [");

    t = _lexer.Next();
    AssertEqual(t.value, '{', "TestNext Passed", "Failure on Next {");

    t = _lexer.Next();
    AssertEqual(t.value, '"', "TestNext Passed", "Failure on Next \" ");

    t = _lexer.Next();
    AssertEqual(t.value, 'n', "TestNext Passed", "Failure on Next n ");

    t = _lexer.Next();
    AssertEqual(t.value, 'a', "TestNext Passed", "Failure on Next a ");
    // release resources
    _lexer.Close();
}

void TestPeek() {
    // initialize
    Lexer _lexer = Lexer("TestResources/LexerTest.json");

    Token t = _lexer.Peek();
    AssertEqual(t.value, '[', "TestPeek Passed", "Failure on Next [");

    t = _lexer.Peek();
    AssertEqual(t.value, '[', "TestPeek Passed", "Failure on Next [");

    t = _lexer.Next();

    t = _lexer.Peek();
    AssertEqual(t.value, '{', "TestPeek Passed", "Failure on Next {");
    t = _lexer.Peek();
    AssertEqual(t.value, '{', "TestPeek Passed", "Failure on Next {");
    // release resources
    _lexer.Close();
}

void TestGet() {
    // initialize
    Lexer _lexer = Lexer("TestResources/LexerTest.json");

    Token t;
    // [
    t = _lexer.Next();
    // {
    t = _lexer.Next();
    // "
    t = _lexer.Next();
    // name
    _lexer.Match("name");
    // "
    t = _lexer.Next();
    // :
    t = _lexer.Next();
    // "
    t = _lexer.Next();
    // Medicin
    _lexer.Match("Medicin");
    // e
    t = _lexer.Get();
    AssertEqual(t.value, 'e', "TestGet Passed", "Failure on Get e");
    // " "
    t = _lexer.Get();
    AssertEqual(t.value, ' ', "TestGet Passed", "Failure on Get space");
    // N
    t = _lexer.Get();
    AssertEqual(t.value, 'N', "TestGet Passed", "Failure on Get N");
    // release resources
    _lexer.Close();
}

void TestMatch() {
    // initialize
    Lexer _lexer = Lexer("TestResources/LexerTest.json");

    Token t;
    // [
    t = _lexer.Next();
    // {
    t = _lexer.Next();
    // "
    t = _lexer.Next();
    // name
    _lexer.Match("name");
    // "
    t = _lexer.Next();
    AssertEqual(t.value, '"', "TestMatch Passed", "Failure on Match name");
    // release resources
    _lexer.Close();
}

int main(int argc, char **argv) {
    cout << "Starting Lexer Tests ...\n";
    // Next();
    TestNext();
    // Peek();
    TestPeek();
    // Get();
    TestGet();
    // Match();
    TestMatch();

    cout << "Completing Lexer Tests ...\n";
}