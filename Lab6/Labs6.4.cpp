/*4. Сравнить скороость выполнения поиска элемента в неотсортирвоанном и отсортированном массиве
    Результат вывести на экран
*/

#include <iostream>
#include <ctime>
#include "header.h"
#include <time.h>
#include <windows.h>
#include <chrono>

using namespace std;

int main() {
    int len = 10000;
    int *array = new int[len];
    srand(time(NULL));
    for (int i = 0; i<len; i++) {
        array[i] = rand() % 2001 -1000;
    }
    // Для неотсортированного
    auto beginFirst = chrono::steady_clock::now();
    Search(len, 100, array);
    auto endFirst = chrono::steady_clock::now();
    auto timeFirst = chrono::duration_cast<chrono::nanoseconds>(endFirst - beginFirst);
    cout << "Поиск в неотсортированном массиве занял " <<timeFirst.count() << " нс" << endl;

    recursionQuickSort(array, 0, len-1);
    // Для отсортированного
    auto beginSecond = chrono::steady_clock::now();
    recursionBSearch(array, 0, len-1, 100);
    auto endSecond = chrono::steady_clock::now();
    auto timeSecond = chrono::duration_cast<chrono::nanoseconds>(endSecond - beginSecond);
    cout << "Поиск в отсортированном массиве занял " << timeSecond.count() << " нс" << endl;
    return 0;
}