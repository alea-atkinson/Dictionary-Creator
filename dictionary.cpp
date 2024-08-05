#include "dictionary.h"
#include <iostream>
#include <algorithm>

Dictionary::Dictionary() {}

void Dictionary::addWord(const std::string& term, const std::string& definition, const std::vector<std::string>& synonyms) {
    words.push_back(word(term, definition, synonyms));
}

void Dictionary::heapSortAlphabetically() {
    words=heapSort(words, words.size());
}

void Dictionary::merge(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<word> L;
    std::vector<word> R;

    for (int i = 0; i < n1; i++)
        L[i] = words[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = words[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].searchCount() <= R[j].searchCount()) {
            words[k] = L[i];
            i++;
        } else {
            words[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        words[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        words[k] = R[j];
        j++;
        k++;
    }
}

void Dictionary::mergeSort(int l, int r) {
    if (l >= r)
        return;

    int m = l + (r - l) / 2;
    mergeSort(l, m);
    mergeSort(m + 1, r);
    merge(l, m, r);
}

void Dictionary::mergeSortBySearchCount() {
    mergeSort(0, words.size() - 1);
}

int Dictionary::binarySearch(const std::string& word) const {
    int left = 0, right = words.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (words[mid].getTerm() == word) {
            return mid;
        }
        if (words[mid].getTerm() < word)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

bool Dictionary::searchWord(const std::string& word, std::string& definition, std::vector<std::string>& synonyms) const {
    int index = binarySearch(word);
    if (index != -1) {
        definition = words[index].getDefinition();
        synonyms = words[index].getSynoynms();
        words[index].addSearch();
        return true;
    }
    return false;
}

void Dictionary::sortAlphabetically() {
    heapSortAlphabetically();
}

void Dictionary::sortBySearchCount() {
    mergeSortBySearchCount();
}

void Dictionary::displayAllWords() const {
    for (const auto& entry : words) {
        std::cout << "Word: " << entry.getTerm() << "; Definition: " << entry.getDefinition() << "; Synonyms: ";
        if (!entry.getSynoynms().empty()) {
            for (size_t i = 0; i < entry.getSynoynms().size(); ++i) {
                std::cout << entry.getSynoynms()[i];
                if (i < entry.getSynoynms().size() - 1) {
                    std::cout << ", ";
                }
            }
        } else {
            std::cout << "None";
        }

        std::cout << std::endl;
    }
}
