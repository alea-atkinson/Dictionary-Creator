#pragma once
#include "word.h"
vector<word> heapSort(vector<word> words, int size);
void buildHeap(vector<word> words, int size);
void heapifyDown(vector<word> words, int size, int index);
void extractMax(vector<word> words, int size);

//replace int with Word
vector<word> heapSort(vector<word> words, int size){
    buildHeap(words, size);
    int sizeIndex=size;
    for(int i=0; i<size; i++){
        extractMax(words, sizeIndex);
        sizeIndex--; //"delete" the last element (already sorted)
    }
    return words;
}
//from discussion slides: Discussion 8 - Sorting.pdf (slide 15)
void buildHeap(vector<word> words, int size){
    int startNode= (size/2)-1; //position of last internal node
    for(int i=startNode; i>=0; i--){
        heapifyDown(words, size, i);
    }
}
//adapted from programming quiz 6
void extractMax(vector<word> words, int size){
    //swap first and last element (put max at the back of the array)
    word temp= words[0];
    words[0]=words[size-1];
    words[size-1]=temp;
    heapifyDown(words, size, 0);
}

void heapifyDown(vector<word> words, int size, int index){
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


