/*#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "word.h"
#include "HeapSort.h"
#include "dictionary.h"


TEST_CASE("HEAP SORT"){
    word term1("zebra", "test");
    word term2("horse", "test");
    word term3("llama", "test");
    word term4("anaconda", "test");
    word term5("bat", "test");
    word term6("monkey", "test");
    word term7("elephant", "test");
    vector<word> words={term1, term2, term3, term4, term5, term6, term7};
    vector<word>newWords=heapSort(words, words.size());
    REQUIRE(newWords.size()==7);
    REQUIRE(newWords[0].getTerm()=="anaconda");
    REQUIRE(newWords[1].getTerm()=="bat");
    REQUIRE(newWords[2].getTerm()=="elephant");
    REQUIRE(newWords[3].getTerm()=="horse");
    REQUIRE(newWords[4].getTerm()=="llama");
    REQUIRE(newWords[5].getTerm()=="monkey");
    REQUIRE(newWords[6].getTerm()=="zebra");
}

TEST_CASE("ADD WORDS"){
    Dictionary dict();
    word term1("zebra", "test");
    dict.addWord(term1);
    word term2("horse", "test");
    dict.addWord(term2);
    word term3("llama", "test");
    dict.addWord(term3);
    word term4("anaconda", "test");
    dict.addWord(term4);
    word term5("bat", "test");
    dict.addWord(term5);
    word term6("monkey", "test");
    dict.addWord(term6);
    word term7("elephant", "test");
    dict.addWord(term7);
    vector<string> expected={"zebra", "horse", "llama", "anaconda", "bat", "monkey", "elephant"};
    vector<word>actual=dict.displayAllWords();
    REQUIRE(actual.size()==expected.size());
    for(int i=0; i<actual.size(); i++){
        REQUIRE(expected[i]==actual[i].getTerm());
    }

}
TEST_CASE("MERGE SORT"){
    Dictionary dict();
    word term1("zebra", "test");
    term1.lookUp();
    term1.lookUp();
    dict.addWord(term1);
    word term2("horse", "test");
    dict.addWord(term2);
    word term3("llama", "test");
    dict.addWord(term3);
    term3.lookUp();
    word term4("anaconda", "test");
    dict.addWord(term4);
    word term5("bat", "test");
    dict.addWord(term5);
    word term6("monkey", "test");
    dict.addWord(term6);
    term6.lookUp();
    term6.lookUp();
    term6.lookUp();
    word term7("elephant", "test");
    dict.addWord(term7);
    vector<word> words={term1, term2, term3, term4, term5, term6, term7};
    vector<word>newWords=dict.mergeSortBySearchCount();
    REQUIRE(newWords.size()==7);
    //from least to most searched
    REQUIRE(newWords[0].getTerm()=="horse");
    REQUIRE(newWords[1].getTerm()=="anaconda");
    REQUIRE(newWords[2].getTerm()=="bat");
    REQUIRE(newWords[3].getTerm()=="elephant");
    REQUIRE(newWords[4].getTerm()=="llama");
    REQUIRE(newWords[5].getTerm()=="zebra");
    REQUIRE(newWords[6].getTerm()=="monkey");
}

TEST_CASE("SEARCH WORD"){
    Dictionary dict();
    word term1("zebra", "test");
    dict.addWord(term1);
    word term2("horse", "test");
    dict.addWord(term2);
    word term3("llama", "test");
    dict.addWord(term3);
    word term4("anaconda", "test");
    dict.addWord(term4);
    word term5("bat", "test");
    dict.addWord(term5);
    word term6("monkey", "test");
    dict.addWord(term6);
    word term7("elephant", "test");
    dict.addWord(term7);
    REQUIRE(dict.searchWord("horse")==true);
    REQUIRE(dict.searchWord("cat")==false);
}
TEST_CASE("IMPORT DICTIONARY"){

}*/

