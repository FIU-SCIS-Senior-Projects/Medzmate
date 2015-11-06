#include "Parser.h"

void AssertEqual(string a, string b, string success, string error) {
    if (a.compare(b) != 0) {
        cout << error << "\n";
    } else {
        cout << success << "\n";
    }
}

void ParseSinglePropertyNode() {
    // initialize parser with test file
    Parser _parser = Parser("TestResources/ParserTestSingleProperty.json");
    list<NameValuePair> properties = _parser.Start();
    for (list<NameValuePair>::iterator it = properties.begin(); it != properties.end(); it++) {
        AssertEqual(it->name, "Medicine Name", "ParseSinglePropertyNode Passed", "Property name parsed incorrectly!!!");
        AssertEqual(it->value, "Ibuprofen 2345", "ParseSinglePropertyNode Passed", "Property value parsed incorrectly!!!");
    }
}

void ParseMultiplePropertyNodes() {
    // initialize parser with test file
    Parser _parser = Parser("TestResources/ParserTestMultipleProperty.json");
    list<NameValuePair> properties = _parser.Start();
    // start the iterator
    list<NameValuePair>::iterator it = properties.begin();
    // assert first pair was read correctly
    AssertEqual(it->name, "Medicine Name", "ParseMultiplePropertyNodes Passed", "Property name parsed incorrectly!!!");
    AssertEqual(it->value, "Ibuprofen 2345", "ParseMultiplePropertyNodes Passed", "Property value parsed incorrectly!!!");
    it++;
    // assert second pair was read correctly
    AssertEqual(it->name, "Doctors Name", "ParseMultiplePropertyNodes Passed", "Property name parsed incorrectly!!!");
    AssertEqual(it->value, "Test Name", "ParseMultiplePropertyNodes Passed", "Property value parsed incorrectly!!!");
    it++;
    if (it != properties.end())
        cout << "Test ParseMultiplePropertyNodes() failed \n";
}

int main(int argc, char **argv) {
    cout << "Starting Parser Tests ...\n";
    ParseSinglePropertyNode();
    ParseMultiplePropertyNodes();
    cout << "Completing Parser Tests ...\n";
}