/*
2. Напишите  код для удаления дубликатов из несортированного связного списка.
3. Реализуйте алгоритм для нахождения в односвязном списке k-го элемента с конца.

    РИ-280002, Хворенков Е.М. Лабораторная работа №6
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

// Реализация связного списка
class Node {
    public:
        int data;
        Node* next;
};

class LinkedList {
    public:
        int len;
        Node* head;
        LinkedList() {
            len = 0;
            head = nullptr;
        }
        ~LinkedList();

        //Добавление элемента
        void push(int data) {
            Node* node = new Node;
            node->data = data;
            node->next = head;
            head = node;
            len++;
        }

        //Удаление элемента с конца
        void pop() {
            Node* temp = head;
            head = head->next;
            delete temp;
            len--;
        };

        int getLenght() {
            return len;
        }

        //Вывод
        void print() {
            Node* newHead = this->head;
            int i = 0;
            while(newHead) {
                cout << i << ": " << newHead->data << endl;
                newHead = newHead->next;
                i++;
            }
        }

        // Получение значения по индексу
        Node* operator[](const int index) {
            Node* head = this->head;
            int counter = 0;
            while (head != nullptr) {
                if (counter == index) {
                    return head;
                }
            head = head->next;
            counter++;
            }
        }

        //Удаление элемента из списка
        void removeAt(int index){
            if (index == 0){
                pop();
            }
            else{
                Node *prev = this->head;
                for (int i = 0; i<index-1; i++)
                    prev = prev->next;
                Node *toDel = prev->next;
                prev->next = toDel->next;
                delete toDel;
                len--;
            }
}
        // №2
        // Удаление дубликатов
        void duplicateDelete() {
            for (int i = 0; i < len; i++) {
                int count = 0;
                int pointNum = operator[](i)->data;
                for (int j = i; j < len; j++) {
                    int num = operator[](j)->data;
                    if (pointNum == num) {
                        count++;
                    }
                }
                if (count > 1) {
                    removeAt(i);
                    i--;
                }
            }
        }

        // №3
        //Поиск элемента с конца
        int searchBack(int index) {
            int i = len - index;
            if (i < 0) {
                cout << "Значение не найдено";
                return 0;
            }
            else {
                return operator[](i)->data;
            }
        }
};

int main() {
    LinkedList* list = new LinkedList;
    list->push(5);
    list->push(2);
    list->push(1);
    list->push(3);
    list->push(2);
    list->push(7);
    list->push(9);
    list->push(5);
    list->push(9);
    list->push(5);
    list->push(4);
    list->print();
    // 2
    cout << endl << "Удаляем дубликаты";
    list->duplicateDelete();
    cout << endl;
    list->print();
    // 3
    cout << "Второй элемент с конца: " << list->searchBack(2) << endl;
    cout << "Пятый элемент с конца: " << list->searchBack(5) << endl;
    return 0;
}



