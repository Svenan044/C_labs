/*1. Реализовать алгоритм поиск Search() значения элемента в неотсортированном массиве Array[N], состоящего из случайных элементов (от -1000 до 1000), длины N=10000.
    Без использования сортировки
*/

#include <iostream>
#include <time.h>
#include "header.h"

using namespace std;

int main(){
    int len = 10000;
    int *array = new int[len];
    for (int i = 0; i<len; i++){
        array[i] = rand() % 2001 -1000;
    }

    cout << Search(len, 10, array) << endl;
    cout << Search(len, -10, array) << endl;
    cout << Search(len, 0, array) << endl;
    cout << Search(len, 1000, array) << endl;
    cout << Search(len, -1000, array) << endl;
    return 0;
}


