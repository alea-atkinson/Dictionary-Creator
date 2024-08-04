#include "word.h"

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

int word::lookUp() {
    searches++;
    return searches;
}
string word::getTerm() {
    return term;
}
string word::getDefinition() {
    return definition;
}
vector<string> word::getSynoynms() {
    return synonyms;
}

