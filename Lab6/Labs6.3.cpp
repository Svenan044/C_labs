/*3.  Реализовать алгоритм биарного поиска BSearch() значения элемента в полученном ранее отсортированном массиве.
 - метод BSearch() принимает искомое значение, массив, левый и правый элемент;
 - реализовать поиск с рекурсией и без.
    Поиск значения в массиве, начиная с элемента left и заканчивая элементом right
    В случае, если значение в массиве есть, функция возвращает индекс элемента, равного этому значению, в противном случае функция возвращает число -1.
    На экран выводить найденное значение или сообщение об его отсутствии.
*/

#include <iostream>
#include "header.h"
#include <time.h>

using namespace std;

int main(){
    int len = 100;
    srand(time(NULL));
    int *array = new int[len];
    for (int i = 0; i<len; i++){
        array[i] = rand() % 21 -10;
    }
    recursionQuickSort(array, 0, len-1);
    Print(array, len);
    cout << recursionBSearch(array, 0, len-1, 101) << endl;
    cout << nonRecursionBSearch(array, 0, len-1, 101);
    return 0;
}