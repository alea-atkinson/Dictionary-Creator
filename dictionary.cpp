#include "dictionary.h"
#include <iostream>
#include <algorithm>

Dictionary::WordEntry::WordEntry(const std::string& w, const std::string& def, const std::vector<std::string>& syns)
        : word(w), definition(def), synonyms(syns), searchCount(0) {}

Dictionary::Dictionary() {}

void Dictionary::addWord(const std::string& word, const std::string& definition, const std::vector<std::string>& synonyms) {
    words.push_back(WordEntry(word, definition, synonyms));
}

void Dictionary::heapify(int n, int i) {
}

void Dictionary::heapSortAlphabetically() {
}

void Dictionary::merge(int l, int m, int r) {
}

void Dictionary::mergeSort(int l, int r) {
}

void Dictionary::mergeSortBySearchCount() {
}

int Dictionary::binarySearch(const std::string& word) const {
    int left = 0, right = words.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (words[mid].word == word) {
            return mid;
        }
        if (words[mid].word < word)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

bool Dictionary::searchWord(const std::string& word, std::string& definition, std::vector<std::string>& synonyms) const {
    int index = binarySearch(word);
    if (index != -1) {
        definition = words[index].definition;
        synonyms = words[index].synonyms;
        return true;
    }
    return false;
}

void Dictionary::sortAlphabetically() {
}

void Dictionary::sortBySearchCount() {
}

void Dictionary::displayAllWords() const {
    for (const auto& entry : words) {
        std::cout << "Word: " << entry.word << "; Definition: " << entry.definition << "; Synonyms: ";

        // Print synonyms
        if (!entry.synonyms.empty()) {
            for (size_t i = 0; i < entry.synonyms.size(); ++i) {
                std::cout << entry.synonyms[i];
                // Print a comma if it's not the last synonym
                if (i < entry.synonyms.size() - 1) {
                    std::cout << ", ";
                }
            }
        } else {
            std::cout << "None";
        }

        std::cout << std::endl;
    }
}
