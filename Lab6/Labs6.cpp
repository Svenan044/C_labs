#include <iostream>
#include <time.h>
#include <stack>
#include "header.h"
#include <chrono>

using namespace std;

void swap(int* array, int leftBorder, int rightBorder){
    int temp = array[leftBorder];
    array[leftBorder] = array[rightBorder];
    array[rightBorder] = temp;
}

void Print(int *array, int len)
{
    std::cout << std::endl;
    for (int i = 0; i<50; i++) std::cout << array[i] << ' ';
    std::cout << std::endl;
}

    /*1. Реализовать алгоритм поиск Search() значения элемента в неотсортированном массиве Array[N], состоящего из случайных элементов (от -1000 до 1000), длины N=10000.
    Без использования сортировки
    */
   
int Search(int len, int value, int* array){
    for (int i = 0; i<len; i++){
        if (array[i] == value){
            std::cout << ' ';
            return i;
        }
    }
    return -1;
}

    /*2. Реализовать алгоритм быстрой сортировки массива QuickSort(), массив Array[N] состоит из случайных элементов (от -10 до 10), длины N=100.
        - метод QuickSort() принимет указатель на начало массива, индекс начальног элемента, индекс конечного элемента;
        - реализовать сортировку с рекурсией и без.
        На экран выводить массив до сортировки и после (вывод 50 первых элементов).
    */
void recursionQuickSort(int *array, int left, int right){
    int index =(left+right)/2;
    int bearing = array[left];
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

    /*3.  Реализовать алгоритм биарного поиска BSearch() значения элемента в полученном ранее отсортированном массиве.
        - метод BSearch() принимает искомое значение, массив, левый и правый элемент;
        - реализовать поиск с рекурсией и без.
        Поиск значения в массиве, начиная с элемента left и заканчивая элементом right
        В случае, если значение в массиве есть, функция возвращает индекс элемента, равного этому значению, в противном случае функция возвращает число -1.
        На экран выводить найденное значение или сообщение об его отсутствии.
    */

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

int main() {


    cout << endl <<"№1" << endl;
    int len = 10000;
    int *array = new int[len];
    for (int i = 0; i<len; i++) {
        array[i] = rand() % 2001 -1000;
    }

    cout << "Позиция элемента 10 - " << Search(len, 10, array) << endl;
    cout << "Позиция элемента -10 - " << Search(len, -10, array) << endl;
    cout << "Позиция элемента 0 - " << Search(len, 0, array) << endl;
    cout << "Позиция элемента 1000 - " << Search(len, 1000, array) << endl;
    cout << "Позиция элемента -1000 - " << Search(len, -1000, array) << endl;
    
    cout << endl <<"№2" << endl;
    int N = 100;
    int* arrayTwo = new int[N];
    srand(time(NULL));
    for (int i = 0; i<N; i++) {
        arrayTwo[i] = rand() % 21 -10;
    }
    cout << endl << "Изначальный массив";
    Print(arrayTwo, N);
    cout << endl << "Результат рекурсивной быстрой сортировки";
    recursionQuickSort(arrayTwo, 0,N-1);
    Print(arrayTwo, N);
    cout << endl << "Результат нерекурсивной быстрой сортировки";
    nonRecursionQuickSort(arrayTwo, 0, N-1);
    Print(arrayTwo, N);
    
    cout << endl <<"№3" << endl;
    len = 100;
    srand(time(NULL));
    int *arrayThree = new int[len];
    for (int i = 0; i<len; i++) {
        arrayThree[i] = rand() % 21 -10;
    }
    recursionQuickSort(arrayThree, 0, len-1);
    cout << "Отсортированный массив";
    Print(arrayThree, len);
    cout << "Поиск числа 95" << endl;
    cout << "результат рекурсивного поиска" << endl;
    cout << recursionBSearch(arrayThree, 0, len-1, 95) << endl;
    cout << "результат нерекурсивного поиска" << endl;
    cout << nonRecursionBSearch(arrayThree, 0, len-1, 95) << endl;
    cout << "Поиск числа 7" << endl;
    cout << "результат рекурсивного поиска" << endl;
    cout << recursionBSearch(arrayThree, 0, len-1, 7) << endl;
    cout << "результат нерекурсивного поиска" << endl;
    cout << nonRecursionBSearch(arrayThree, 0, len-1, 7) << endl;

    /*4. Сравнить скороость выполнения поиска элемента в неотсортирвоанном и отсортированном массиве
        Результат вывести на экран
    */
    cout << endl <<"№4" << endl;
    len = 10000;
    int *arrayFour = new int[len];
    srand(time(NULL));
    for (int i = 0; i<len; i++) {
        arrayFour[i] = rand() % 2001 -1000;
    }
    // Поиск в неотсортированном массиве
    auto beginFirst = chrono::steady_clock::now();
    Search(len, 50, arrayFour);
    auto endFirst = chrono::steady_clock::now();
    auto timeFirst = chrono::duration_cast<chrono::nanoseconds>(endFirst - beginFirst);
    cout << "Поиск в неотсортированном массиве занял " <<timeFirst.count() << " нс" << endl;

    recursionQuickSort(arrayFour, 0, len-1);
    // Поиск в отсортированном массиве
    auto beginSecond = chrono::steady_clock::now();
    recursionBSearch(arrayFour, 0, len-1, 50);
    auto endSecond = chrono::steady_clock::now();
    auto timeSecond = chrono::duration_cast<chrono::nanoseconds>(endSecond - beginSecond);
    cout << "Поиск в отсортированном массиве занял " << timeSecond.count() << " нс" << endl;
    return 0;
}