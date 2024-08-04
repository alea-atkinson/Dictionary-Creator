#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>

class Dictionary {
public:
    struct WordEntry {
        std::string word;
        std::string definition;
        std::vector<std::string> synonyms;
        int searchCount;

        WordEntry();
        WordEntry(const std::string& w, const std::string& def, const std::vector<std::string>& syns);
    };

    Dictionary();

    void addWord(const std::string& word, const std::string& definition, const std::vector<std::string>& synonyms);

    void heapSortAlphabetically();
    void mergeSortBySearchCount();

    bool searchWord(const std::string& word, std::string& definition, std::vector<std::string>& synonyms) const;
    void sortAlphabetically();
    void sortBySearchCount();
    void displayAllWords() const;

private:
    std::vector<WordEntry> words;

    void heapify(int n, int i);
    void merge(int l, int m, int r);
    void mergeSort(int l, int r);
    int binarySearch(const std::string& word) const;
};

#endif // DICTIONARY_H
