#include "dictionary.h"
#include <iostream>
#include <algorithm>

Dictionary::WordEntry::WordEntry() : searchCount(0) {}

Dictionary::WordEntry::WordEntry(const std::string& w, const std::string& def, const std::vector<std::string>& syns)
        : word(w), definition(def), synonyms(syns), searchCount(0) {}

Dictionary::Dictionary() {}

void Dictionary::addWord(const std::string& word, const std::string& definition, const std::vector<std::string>& synonyms) {
    words.push_back(WordEntry(word, definition, synonyms));
}

void Dictionary::heapify(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && words[left].word > words[largest].word)
        largest = left;

    if (right < n && words[right].word > words[largest].word)
        largest = right;

    if (largest != i) {
        std::swap(words[i], words[largest]);
        heapify(n, largest);
    }
}

void Dictionary::heapSortAlphabetically() {
    int n = words.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(words[0], words[i]);
        heapify(i, 0);
    }
}

void Dictionary::merge(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<WordEntry> L(n1);
    std::vector<WordEntry> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = words[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = words[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].searchCount <= R[j].searchCount) {
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
    heapSortAlphabetically();
}

void Dictionary::sortBySearchCount() {
    mergeSortBySearchCount();
}

void Dictionary::displayAllWords() const {
    for (const auto& entry : words) {
        std::cout << "Word: " << entry.word << "; Definition: " << entry.definition << "; Synonyms: ";

        if (!entry.synonyms.empty()) {
            for (size_t i = 0; i < entry.synonyms.size(); ++i) {
                std::cout << entry.synonyms[i];
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
