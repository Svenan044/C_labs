#include <iostream>
#include <time.h>
#include <stack>
#include "header.h"
#include <chrono>

using namespace std;

int main() {

    // 1
    /*1. Реализовать алгоритм поиск Search() значения элемента в неотсортированном массиве Array[N], состоящего из случайных элементов (от -1000 до 1000), длины N=10000.
    Без использования сортировки
    */
    cout << endl <<"№1" << endl;
    int len = 10000;
    int *array = new int[len];
    for (int i = 0; i<len; i++) {
        array[i] = rand() % 2001 -1000;
    }

    cout << "Позиция элемента 10 - " << Search(len, 10, array) << endl;
    cout << "Позиция элемента 10 - " << Search(len, -10, array) << endl;
    cout << "Позиция элемента 10 - " << Search(len, 0, array) << endl;
    cout << "Позиция элемента 10 - " << Search(len, 1000, array) << endl;
    cout << "Позиция элемента 10 - " << Search(len, -1000, array) << endl;
    
    // 2
    /*2. Реализовать алгоритм быстрой сортировки массива QuickSort(), массив Array[N] состоит из случайных элементов (от -10 до 10), длины N=100.
        - метод QuickSort() принимет указатель на начало массива, индекс начальног элемента, индекс конечного элемента;
        - реализовать сортировку с рекурсией и без.
        На экран выводить массив до сортировки и после (вывод 50 первых элементов).
    */
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

    // 3
    /*3.  Реализовать алгоритм биарного поиска BSearch() значения элемента в полученном ранее отсортированном массиве.
        - метод BSearch() принимает искомое значение, массив, левый и правый элемент;
        - реализовать поиск с рекурсией и без.
        Поиск значения в массиве, начиная с элемента left и заканчивая элементом right
        В случае, если значение в массиве есть, функция возвращает индекс элемента, равного этому значению, в противном случае функция возвращает число -1.
        На экран выводить найденное значение или сообщение об его отсутствии.
    */
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
    cout << "Поиск числа 101" << endl;
    cout << "результат рекурсивного поиска" << endl;
    cout << recursionBSearch(arrayThree, 0, len-1, 101) << endl;
    cout << "результат нерекурсивного поиска" << endl;
    cout << nonRecursionBSearch(arrayThree, 0, len-1, 101) << endl;
    cout << "Поиск числа 3" << endl;
    cout << "результат рекурсивного поиска" << endl;
    cout << recursionBSearch(arrayThree, 0, len-1, 3) << endl;
    cout << "результат нерекурсивного поиска" << endl;
    cout << nonRecursionBSearch(arrayThree, 0, len-1, 3) << endl;

    // 4
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
    // Для неотсортированного
    auto beginFirst = chrono::steady_clock::now();
    Search(len, 100, arrayFour);
    auto endFirst = chrono::steady_clock::now();
    auto timeFirst = chrono::duration_cast<chrono::nanoseconds>(endFirst - beginFirst);
    cout << "Поиск в неотсортированном массиве занял " <<timeFirst.count() << " нс" << endl;

    recursionQuickSort(arrayFour, 0, len-1);
    // Для отсортированного
    auto beginSecond = chrono::steady_clock::now();
    recursionBSearch(arrayFour, 0, len-1, 100);
    auto endSecond = chrono::steady_clock::now();
    auto timeSecond = chrono::duration_cast<chrono::nanoseconds>(endSecond - beginSecond);
    cout << "Поиск в отсортированном массиве занял " << timeSecond.count() << " нс" << endl;
    return 0;
}