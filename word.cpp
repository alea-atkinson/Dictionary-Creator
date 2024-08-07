#include "word.h"

word::word(){
    term = "";
    definition = "";
    synonyms = {};
    searches = 0;
}
word::word(string newTerm, string newDefinition) {
    term=newTerm;
    definition=newDefinition;
    synonyms={};
    searches=0;
}

word::word(string newTerm, string newDefinition, vector<string> newSynoymns) {
    term=newTerm;
    definition=newDefinition;
    synonyms=newSynoymns;
    searches=0;
}

void word::addSynonyms(vector<string> newSynoymns) {
    synonyms=newSynoymns;
}

void word::addSynonym(string synonym) {
    synonyms.push_back(synonym);
}

void word::addSearch() {
    searches++;
}

int word::searchCount(){
    return searches;
}
string word::getTerm() const{
    return term;
}
string word::getDefinition() const{
    return definition;
}
vector<string> word::getSynoynms() const{
    return synonyms;
}
