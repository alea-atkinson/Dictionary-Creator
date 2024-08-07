
#pragma once

#include <string>
#include <vector>
#include "word.h"

class Dictionary {
    std::vector<word> words;
    void merge(int l, int m, int r);
    void mergeSort(int l, int r);
    vector<word> heapSort(vector<word> words, int size);
    void buildHeap(vector<word>& words, int size);
    void heapifyDown(vector<word>& words, int size, int index);
    void extractMax(vector<word>& words, int size);
    int binarySearch(std::string word);
    bool alphabetic;
public:

    Dictionary();

    void addWord(const std::string& word, const std::string& definition, const std::vector<std::string>& synonyms);

    void heapSortAlphabetically();
    void mergeSortBySearchCount();

    vector<string> searchWord(std::string word);
    void sortAlphabetically();
    void sortBySearchCount();
    vector<string> displayAllWords() const;


};
