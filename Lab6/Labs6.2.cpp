/*2. Реализовать алгоритм быстрой сортировки массива QuickSort(), массив Array[N] состоит из случайных элементов (от -10 до 10), длины N=100.
 - метод QuickSort() принимет указатель на начало массива, индекс начальног элемента, индекс конечного элемента;
 - реализовать сортировку с рекурсией и без.
    На экран выводить массив до сортировки и после (вывод 50 первых элементов).
*/

#include <iostream>
#include <time.h>
#include <stack>
#include "header.h"

using namespace std;

int main(){
    int N =100;
    int* array = new int[N];
    srand(time(NULL));
    for (int i = 0; i<N; i++){
        array[i] = rand() % 21 -10;
    }
    cout << endl << "ARRAY";
    Print(array, N);
    cout << endl << "Recursion";
    recursionQuickSort(array, 0,N-1);
    Print(array, N);
    cout << endl << "NonRecursion";
    nonRecursionQuickSort(array, 0, N-1);
    Print(array, N);
}


