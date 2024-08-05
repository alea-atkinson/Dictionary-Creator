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
    word(string newTerm, string newDefinition); //construct without synoymns
    word(string newTerm, string newDefinition, vector<string> newSynoymns); //construct with synoynms
    void addSynonyms(vector<string> newSynoymns); //add synonyms by vector
    void addSynonym(string synonym); //add single synonym to existing word
    int addSearch(); //increment searches and return current value
    int searchCount(); //return search count
    string getTerm() const;
    string getDefinition() const;
    vector<string> getSynoynms() const;
};