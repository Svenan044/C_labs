#pragma once
#include <iostream>

void Print(int *array, int len){
    std::cout << std::endl;
    for (int i = 0; i<50; i++) std::cout << array[i] << ' ';
    std::cout << std::endl;
}

void swap(int* array, int leftBorder, int rightBorder){
    int temp = array[leftBorder];
    array[leftBorder] = array[rightBorder];
    array[rightBorder] = temp;
}

//1
int Search(int len, int value, int* array){
    for (int i = 0; i<len; i++){
        if (array[i] == value){
            std::cout << ' ';
            return i;
        }
    }
    return -1;
}

//2
void recursionQuickSort(int *array, int left, int right){
    int index =(left+right)/2;
    int bearing = array[left]; // опорный элемент
    int leftBorder = left;
    int rightBorder = right;

    while (leftBorder < rightBorder){
        while (bearing > array[leftBorder]) leftBorder++;
        while (bearing < array[rightBorder]) rightBorder--;
        if (leftBorder<=rightBorder){
            swap(array, leftBorder, rightBorder);
            leftBorder++;
            rightBorder--;
        }
    }
    if (rightBorder > left){
        recursionQuickSort(array, left, rightBorder);
    }
    if (leftBorder < right){
        recursionQuickSort(array, leftBorder, right);
    }
}

void nonRecursionQuickSort(int *array, int left, int right){
    int leftStack[1000], rightStack[1000];
    int stackPos = 1;
    leftStack[1] = 0;
    rightStack[1] = right;
    while (stackPos != 0){
        left = leftStack[stackPos];
        right = rightStack[stackPos];
        stackPos--;
        while(left<right){
            int leftBorder = left;
            int rightBorder = right;
            int midIndex = (left+right)/2;
            int bearing = array[midIndex];
            while(leftBorder<=rightBorder){
                while (array[leftBorder] < bearing) leftBorder++;
                while (array[rightBorder] > bearing) rightBorder--;
                if (leftBorder<=rightBorder){
                    swap(array, leftBorder, rightBorder);
                    leftBorder++;
                    rightBorder--;
                }
            }
            if (leftBorder < midIndex){
                if (leftBorder < right){
                    stackPos++;
                    leftStack[stackPos] = leftBorder;
                    rightStack[stackPos] = right;
                }
                right = rightBorder;
            }
            else{
                if (rightBorder>left){
                    stackPos++;
                    leftStack[stackPos] = left;
                    rightStack[stackPos] = rightBorder;
                }
                left = leftBorder;
            }
        }
    }
}

//3
int recursionBSearch(int* array, int left, int right, int value){
    int midIndex = (left+right)/2;
    int bearing = array[midIndex];
    if (bearing == value)
        return midIndex;
    if (left > right){
        std::cout <<"value not found" << std::endl;
        return -1;
    }
    if (bearing < value)
        recursionBSearch(array, midIndex+1, right, value);
    else if (bearing > value)
        recursionBSearch(array, left, midIndex-1, value);
}

int nonRecursionBSearch(int* array, int left, int right, int value){
    while(left <= right){
        int midIndex = (right+left)/2;
        int bearing = array[midIndex];
        if (value == bearing)
            return midIndex;
        else if (value<bearing)
            right = midIndex-1;
        else if (value > bearing)
            left = midIndex+1;
    }
    std::cout <<"value not found" << std::endl;
    return -1;
}