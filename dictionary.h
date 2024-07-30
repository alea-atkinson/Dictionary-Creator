#ifndef DICTIONARY_CREATOR_DICTIONARY_H
#define DICTIONARY_CREATOR_DICTIONARY_H

#include <vector>
#include <string>

class Dictionary {
private:
    struct WordEntry {
        std::string word;
        std::string definition;
        std::vector<std::string> synonyms;
        int searchCount;

        WordEntry(const std::string& w, const std::string& def, const std::vector<std::string>& syns);
    };

    std::vector<WordEntry> words;

    void heapSortAlphabetically();
    void mergeSortBySearchCount();
    void heapify(int n, int i);
    void merge(int l, int m, int r);
    void mergeSort(int l, int r);
    int binarySearch(const std::string& word) const;

public:
    Dictionary();
    void addWord(const std::string& word, const std::string& definition, const std::vector<std::string>& synonyms);
    void sortAlphabetically();
    void sortBySearchCount();
    bool searchWord(const std::string& word, std::string& definition, std::vector<std::string>& synonyms) const;
    void displayAllWords() const;
};

#endif