/*2. Напишите алгоритм создания бинарного дерева поиска с минимальной высотой для отсортированного (по возрастанию) массива с уникльными целочисленными элементами.
    ТЗ:
    - использовать класс BinaryTree из предыдущего задания;
    - метод CreateMinimalBST() принимет указатель на начало массива, индекс начальног элемента, индекс конечного элемента.
*/

#include <iostream>
#include "TreeNode.h"
#include "BinaryTree.h"

using namespace std;

int main(){
    int array[9]  = {2,5,7,9,15,16,27,48,56};
    BinaryTree* tree = new BinaryTree;
    tree->CreateMinimalBST(array, 0, 8);
    return 0;
}