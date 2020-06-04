/*1.1. Работа со статической памятью.
    Создать двумерный массив типа int фиксированного размера 3х3 (квадратный), инициализировать произвольными значениями.
    Вычислить: сумму и произведение элементов главной и побочной диагонали, сумму элементов каждой строки, минимальное и максимальное значение в каждом столбце.
    ТЗ: Написать класс Matrix3x3, для класса определить:
    - конструктор по-умолчанию, инициализирующий значения элементов равных нулю;
    - метод чтения элементов матрицы с сигнатурой int element(const int i, const int j) const;
    - метод записи в элементы матрицы с сигнатурой void setElement(const int i, const int j, const int value);
    - метод void fillRandomElements(const int minVal, const int maxVal), заполняющий случайными значениями в диапазоне [minVal, maxVal) элементы матрицы;
    - метод int sumPrincipalDiag() const вычисляющий сумму элементов главной диагонали;
    - метод int sumSecondaryDiag() const вычисляющий сумму элементов побочной диагонали;
    - метод int productPrincipalDiag() const вычисляющий произведение элементов главной диагонали;
    - метод int productSecondaryDiag() const вычисляющий произведение элементов побочной диагонали;
    - метод int sumRow(const int iRow) const вычисляющий сумму элементов в строке iRow;
    - метод int minColumn(const int iCol) const вычисляющий минимальный элемент в столбце iCol;
    - метод int maxColumn(const int iCol) const вычисляющий максимальный элемент в столбце iCol;
    Произвести в главной программе создание экзмепляра, заполнить его случайными значениями методом fillRandomElements в диапазоне [-10, 10),
    вывести результирующу матрицу, посчитать суммы элементов всех строк, минимальный и максимальный элементы стролбцов, суммы и произведения главной и побочной диагоналей.

1.2. Работа со динамической памятью.  Создать двумерный массив типа int призвольного размера (квадратный), инициализировать произвольными значениями.
    Вычислить: сумму и произведение элементов главной и побочной диагонали, сумму элементов каждой строки, минимальное и максимальное значение в каждом столбце.
    ТЗ: Написать класс MatrixXnX, для класса определить:
    - конструктор по-умолчанию, принимающий размерность матрицы iDim с сигнатурой MatrixXnX(const int iDim) инициализирующий значения элементов равных нулю;
    - реализовать те же методы, что и для класса Matrix3x3.
    Задача подразумевает работу с динамической памятью (т.е. размер памяти изначально неизвестен).
    Необходимо создать класс, обслуживающий данную задачу.
    В классе следует хранить указатель на память, в которой лежит двухмерная матрица.
    Для выделения и освобождения памяти под элементы матрицы использовать функции new[] и delete[].

    РИ-280002, Хворенков Е.М. Лабораторная работа №6
*/
#include <iostream>
#include <ctime>

using namespace std;

//  Матрица 3x3
class Matrix3x3{
    public:
    const int static rows = 3, columns = 3;
    int nums[rows][columns] = {{0,0,0},{0,0,0},{0,0,0}};
    const int minVal = -10, maxVal = 10;

    const int element(const int i, const int j){
        return nums[i][j];
    }

    void setElement(const int i, const int j, const int value){
        nums[i][j] = value;
    }

    void fillRandomElements(const int minVal, const int maxVal){
        srand(time(NULL));
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<columns; j++){
                setElement(i,j,rand() % (maxVal * 2) + minVal);
                cout << nums[i][j] << " ";
            }
            cout << endl;
        }
    }

    const int sumPrincipalDiag(){
        int sum = 0;
        for (int i = 0; i < rows; i++){
            sum += nums[i][i];
            }
        cout << endl;
        return sum;
    }

    const int sumSecondaryDiag(){
        int sum = 0;
        for (int i = 0; i < rows; i++){
            sum += nums[i][rows - 1 - i];
        }
        cout << endl;
        return sum;
    }

    const int productPrincipalDiag(){
        int prod = 1;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (i == j)
                    prod *= nums[i][j];
        cout << endl;
        return prod;
    }

    const int productSecondaryDiag() {
        int prod = 1;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (i + j == rows - 1)
                    prod *= nums[i][j];
        cout << endl;
        return prod;
    }

    const int sumRow(const int iRow){
        int sum = 0;
        for (int i = 0; i<columns; i++)
            sum += nums[iRow][i];
        cout << endl;
        return sum;
    }

    const int minColumn(const int iCol){
        int min = maxVal;
        for (int i = 0; i<rows; i++)
            if (nums[i][iCol] <= min)
                min = nums[i][iCol];
        cout << endl;
        return min;
    }

    const int maxColumn(const int iCol){
        int max = minVal;
        for (int i = 0; i<rows; i++)
            if (nums[i][iCol] >= max)
                max = nums[i][iCol];
        cout << endl;
        return max;
    }
};

//  Матрица произвольного размера
class MatrixXnX{
    public:
    const int minVal = -10, maxVal = 10;

    MatrixXnX(const int iDim){
        this->p = iDim;
        nums = new int* [p];
        for (int i = 0; i < p; i++){
            nums[i] = new int[p];
            for (int j = 0; j<p; j++)
                nums[i][j] = 0;
        }
    }

    ~MatrixXnX(){
        for (int i = 0; i < p; i++)
            delete[] nums[i];
        delete[] nums;
    }

    const int element(const int i, const int j){
        return nums[i][j];
    }

    void setElement(const int i, const int j, const int value){
        nums[i][j] = value;
    }

    void fillRandomElements(const int minVal, const int maxVal){
        srand(time(NULL));
        for (int i = 0; i<p; i++){
            for (int j = 0; j<p; j++){
                setElement(i,j,rand() % (maxVal*2) + minVal);
                cout << element(i,j) << " ";
            }
            cout << endl;
        }
    }

    const int sumPrincipalDiag(){
        int sum = 0;
        for (int i = 0; i < p; i++)
            sum += nums[i][i];
        cout << endl;
        return sum;
    }

    const int sumSecondaryDiag(){
        int sum = 0;
        for (int i = 0; i < p; i++)
            sum += nums[i][p-1-i];
        cout << endl;
        return sum;
    }

    const int productPrincipalDiag(){
        int prod = 1;
        for (int i = 0; i < p; i++)
            for (int j = 0; j < p; j++)
                if (i == j)
                    prod *= nums[i][j];
        cout << endl;
        return prod;
    }

    const int productSecondaryDiag() {
        int prod = 1;
        for (int i = 0; i < p; i++)
            for (int j = 0; j < p; j++)
                if (i + j == p - 1)
                    prod *= nums[i][j];
        cout << endl;
        return prod;
    }

    const int sumRow(const int iRow){
        int sum = 0;
        for (int i = 0; i<p; i++)
            sum += nums[iRow][i];
        cout << endl;
        return sum;
    }

    const int minColumn(const int iCol){
        int min = maxVal;
        for (int i = 0; i<p; i++)
            if (nums[i][iCol] <= min)
                min = nums[i][iCol];
        cout << endl;
        return min;
    }

    const int maxColumn(const int iCol){
        int max = minVal;
        for (int i = 0; i<p; i++)
            if (nums[i][iCol] >= max)
                max = nums[i][iCol];
        cout << endl;
        return max;
    }

    private:
    int **nums;
    int p;
};

int main(){
    //  1.1
    Matrix3x3 m;
    m.columns;
    m.rows;
    cout << "Матрица 3x3" << endl;
    m.fillRandomElements(m.minVal, m.maxVal);
    cout << endl;
    cout << "Cумма элементов главной диагонали: " << m.sumPrincipalDiag() << endl;
    cout << "Сумма элементов побочной диагонали: " << m.sumSecondaryDiag() << endl;
    cout << "Произведение элементов главной диагонали: " << m.productPrincipalDiag() << endl;
    cout << "Произведение элементов побочной диагонали: " << m.productSecondaryDiag() << endl;
    cout << "Cумма элементов в третьей строке: "<< m.sumRow(2) << endl;
    cout << "Минимальный элемент во втором столбце: " << m.minColumn(1) << endl;
    cout << "Максимальный элемент в превом столбце" << m.maxColumn(0) << endl;

    //  1.2
    MatrixXnX n(6);
    n.maxVal;
    n.minVal;
    cout << "Матрица произвольного размера " << endl;
    n.fillRandomElements(n.minVal, n.maxVal);
    cout << endl;
    cout << "Cумма элементов главной диагонали: " << n.sumPrincipalDiag() << endl;
    cout << "Сумма элементов побочной диагонали: " << n.sumSecondaryDiag() << endl;
    cout << "Произведение элементов главной диагонали: " << n.productPrincipalDiag() << endl;
    cout << "Произведение элементов побочной диагонали: " << n.productSecondaryDiag() << endl;
    cout << "Cумма элементов в третьей строке: " << n.sumRow(2) << endl;
    cout << "Минимальный элемент во втором столбце: " << n.minColumn(1) << endl;
    cout << "Максимальный элемент в превом столбце" << n.maxColumn(0) << endl;

    return 0;
}
