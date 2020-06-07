#pragma once
#include <iostream>

void Print(int *array, int len);
void swap(int* array, int leftBorder, int rightBorder);
int Search(int len, int value, int* array);
void recursionQuickSort(int *array, int left, int right);
void nonRecursionQuickSort(int *array, int left, int right);
int recursionBSearch(int* array, int left, int right, int value);
int nonRecursionBSearch(int* array, int left, int right, int value);