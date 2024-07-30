#pragma once
#include <string>
#include <vector>
using namespace std;

class word{
    string term;
    string definition;
    vector<string> synonyms;
    int searches;
public:
    word(string newTerm, string newDefinition);
    void addSynonyms(vector<string> newSynoymns); //add synonyms by vector
    void addSynonym(string synonym); //add single synonym to existing word
    int lookUp(); //increment searches and return current value
    string getTerm();
    string getDefinition();
    vector<string> getSynoynms();
};