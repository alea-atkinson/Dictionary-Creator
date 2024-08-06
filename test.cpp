/*#define CATCH_CONFIG_MAIN
#include "C:\Users\maite\CLionProjects\Project1\Project1\test-unit\catch.hpp"
#include "word.h"
#include "HeapSort.h"
#include "dictionary.h"

TEST_CASE("ADD WORDS AND DISPLAY"){
    Dictionary dict;
    dict.addWord("zebra", "test", {});
    dict.addWord("horse", "test", {});
    dict.addWord("llama", "test", {});
    dict.addWord("anaconda", "test", {});
    dict.addWord("bat", "test", {});
    dict.addWord("monkey", "test", {});
    dict.addWord("elephant", "test", {});
    vector<string> expected={"zebra", "horse", "llama", "anaconda", "bat", "monkey", "elephant"};
    vector<string>actual=dict.displayAllWords();
    REQUIRE(actual.size()==expected.size());
    for(int i=0; i<actual.size(); i++){
        REQUIRE(expected[i]==actual[i]);
    }
}


TEST_CASE("HEAP SORT"){
    Dictionary dict;
    dict.addWord("zebra", "test", {});
    dict.addWord("horse", "test", {});
    dict.addWord("llama", "test", {});
    dict.addWord("anaconda", "test", {});
    dict.addWord("bat", "test", {});
    dict.addWord("monkey", "test", {});
    dict.addWord("elephant", "test", {});
    dict.sortAlphabetically();
    vector<string> expected={"anaconda", "bat", "elephant", "horse", "llama", "monkey", "zebra"};
    vector<string>actual=dict.displayAllWords();
    REQUIRE(actual.size()==expected.size());
    for(int i=0; i<actual.size(); i++){
        REQUIRE(expected[i]==actual[i]);
    }
}


TEST_CASE("SEARCH AND MERGE SORT"){
    Dictionary dict;
    dict.addWord("zebra", "test", {});
    dict.addWord("horse", "test", {});
    dict.addWord("llama", "test", {});
    dict.addWord("anaconda", "test", {});
    dict.addWord("bat", "test", {});
    dict.addWord("monkey", "test", {});
    dict.addWord("elephant", "test", {});
    dict.searchWord("zebra", "test",{});
    dict.searchWord("zebra", "test",{});
    dict.searchWord("llama", "test",{});
    dict.searchWord("monkey", "test",{});
    dict.searchWord("monkey", "test",{});
    dict.searchWord("monkey", "test",{});
    dict.mergeSortBySearchCount();
    vector<string> newWords=dict.displayAllWords();
    REQUIRE(newWords.size()==7);
    //from least to most searched
    REQUIRE(newWords[0]=="horse");
    REQUIRE(newWords[1]=="anaconda");
    REQUIRE(newWords[2]=="bat");
    REQUIRE(newWords[3]=="elephant");
    REQUIRE(newWords[4]=="llama");
    REQUIRE(newWords[5]=="zebra");
    REQUIRE(newWords[6]=="monkey");
}

TEST_CASE("WORD NOT FOUND"){
    Dictionary dict;
    dict.addWord("zebra", "test", {});
    dict.addWord("horse", "test", {});
    dict.addWord("llama", "test", {});
    dict.addWord("anaconda", "test", {});
    dict.addWord("bat", "test", {});
    dict.addWord("monkey", "test", {});
    REQUIRE(dict.searchWord("cat", "test", {})==false);
    dict.sortAlphabetically();
    REQUIRE(dict.searchWord("horse", "test", {})==true);

}

TEST_CASE("IMPORT DICTIONARY"){
    Dictionary dict;
    std::ifstream file("C:\\Users\\maite\\CLionProjects\\Dictionary-Creator\\data");

    std::string line;
    std::getline(file, line);
    std::vector<std::string> synonyms;

    for (int i = 0; i < stoi(line) / 2; ++i) {
        std::string word, definition;
        std::getline(file, word);
        std::getline(file, definition);
        dict.addWord(word, definition, synonyms);
    }

    REQUIRE(dict.searchWord("consider", "deem to be", {})==true);
    REQUIRE(dict.searchWord("minute", "infinitely or immeasurably small",{})==true);
    REQUIRE(dict.searchWord("accord", "concurrence of opinion" ,{})==true);
}*/
