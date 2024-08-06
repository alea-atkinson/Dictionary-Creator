#include "dictionary.h"
#include <iostream>
#include <algorithm>

Dictionary::Dictionary() {}

void Dictionary::addWord(const std::string& term, const std::string& definition, const std::vector<std::string>& synonyms) {
    words.push_back(word(term, definition, synonyms));
    alphabetic=false;
}

void Dictionary::heapSortAlphabetically() {
    words=heapSort(words, words.size());
    alphabetic=true;
}

void Dictionary::merge(int l, int m, int r) {
    // Calculate sizes of the two subarrays
    int n1 = m - l + 1;
    int n2 = r - m;

    //std::vector<word> L;
    //std::vector<word> R;
    std::vector<word> L(n1);
    std::vector<word> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = words[l + i];
    for (int i = 0; i < n2; ++i)
        R[i] = words[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].searchCount() <= R[j].searchCount()) {
            words[k] = L[i];
            ++i;
        } else {
            words[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        words[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        words[k] = R[j];
        ++j;
        ++k;
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

int Dictionary::binarySearch(std::string word) {
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

vector<string> Dictionary::searchWord(std::string word) {
    int index = -1;
    vector<string>wordInfo;
    if(alphabetic){
        index = binarySearch(word);
    }
    else{
        for(int i=0; i<words.size(); i++){
            if(words[i].getTerm()==word){
                index=i;
            }
        }
    }
    if (index != -1) {
            words[index].addSearch();
            wordInfo.push_back(words[index].getDefinition());
            for(int i=0; i<words[index].getSynoynms().size(); i++){
                wordInfo.push_back(words[index].getSynoynms()[i]);
            }
            //return true;
    }
    return wordInfo;
}

void Dictionary::sortAlphabetically() {
    heapSortAlphabetically();
}

void Dictionary::sortBySearchCount() {
    mergeSortBySearchCount();
}

vector<string> Dictionary::displayAllWords() const {
    vector<string> display; //return vector for testing
    for (const auto& entry : words) {
        std::cout << "Word: " << entry.getTerm() << "; Definition: " << entry.getDefinition() << "; Synonyms: ";
        display.push_back(entry.getTerm());
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
    return display;
}

void Dictionary::heapifyDown(vector<word>& words, int size, int index){
    if(2*(index)+1>=size && 2*(index)+2>=size){
        //leaf node
    }
        //only left node
    else if(2*(index)+1<size && 2*(index)+2>=size){
        //if child is greater than parent
        if(words[2*(index)+1].getTerm()>words[index].getTerm()){
            //swap
            word temp=words[index];
            words[index]=words[2*(index)+1];
            words[2*(index)+1]=temp;
            //call heapify on child
            heapifyDown(words, 2*(index)+1, size);
        }
    }
        //both children
    else{
        //one or more children is greater
        if(words[2*(index)+1].getTerm()>words[index].getTerm() ||  words[2*(index)+2].getTerm()>words[index].getTerm()){
            //left is greater
            if(words[2*(index)+1].getTerm()>words[2*(index)+2].getTerm()){
                //swap
                word temp=words[index];
                words[index]=words[2*(index)+1];
                words[2*(index)+1]=temp;
                //call heapify on child
                heapifyDown(words, 2*(index)+1, size);
            }
                //right is greater
            else{
                //swap
                word temp=words[index];
                words[index]=words[2*(index)+2];
                words[2*(index)+2]=temp;
                //call heapify on child
                heapifyDown(words, 2*(index)+2, size);
            }
        }
    }
}
void Dictionary::extractMax(vector<word>& words, int size){
    //swap first and last element (put max at the back of the array)
    word temp= words[0];
    words[0]=words[size-1];
    words[size-1]=temp;
    size--; //decrement size before calling heapify
    heapifyDown(words, size, 0);
}
//from discussion slides: Discussion 8 - Sorting.pdf (slide 15)
void Dictionary::buildHeap(vector<word>& words, int size){
    int startNode= (size/2)-1; //position of last internal node
    for(int i=startNode; i>=0; i--){
        heapifyDown(words, size, i);
    }
}
vector<word> Dictionary::heapSort(vector<word> words, int size){
    buildHeap(words, size);
    int sizeIndex=size;
    for(int i=0; i<size; i++){
        extractMax(words, sizeIndex);
        sizeIndex--; //"delete" the last element (already sorted)
    }
    return words;
}


