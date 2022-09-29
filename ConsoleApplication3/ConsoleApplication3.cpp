#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int f1(int number = 1)
{
    int res = 0;
    if (number > 0)
    {
        for (int i = 1; i <= number; i++)
        {
            res += i;
        }
    }
    return res;
}

void f2(int m, int n, int& linkm, int& linkn)
{
    linkm = m + n;
    linkn = m * n;
}

int main() {
    srand(time(0));
    setlocale(LC_ALL, "");

    float** array = new float* [2]; // создание динамического двумерного массива на 2 строк
    for (int i(0); i < 2; i++) // создание каждого одномерного массива в динамическом двумерном массиве, или иначе - создание столбцов размерность 3
        array[i] = new float[3];

    //заполнение массива от -10 до 10
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            array[i][j] = rand() % 21 - 10;
        }
    }

    //вывод чисел
    cout << "Array: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << array[i][j];
        }
        cout << endl;
    }
        
    /*for (int i(0); i < 2; i++) // освобождение памяти каждого одномерного массива в двумерном массиве - удаление столбцов
        delete array[i];
    delete array; // освобождение памяти двумерного массива*/

    int sum = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            sum = sum + array[i][j];
    }
    cout << "Сумма всех чисел в массиве = " << sum<<endl;

    //сумму чисел из столбцов двумерного массива
    cout << "New Array: { ";
    for (int j = 0; j < 3; j++) {
        int a = 0;
        for (int i = 0; i < 2; i++) {
            a += array[i][j];
        }
        cout << a << ", ";
    }
    cout << "}"<<endl<<endl;

    //ссылки
    float z = 20.84;
    float& link1 = z;
    float& link2 = z;
    link1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 6));
    printf("z = %.2f", z);
    printf("\nlink2 = %.2f\n", link2);
    cout << endl << endl;
        
    //функция на возврат 0 или суммы последовательности от 1
    cout << f1(17) << endl << f1(-9) << endl << f1(0) << endl << f1(1) << endl << f1(2) << endl << f1() << endl << endl;

    int linkm = 0;
    int linkn = 0;
    cout << "m = 17, n = 5, linkm = " << linkm << ", linkn = " << linkn << endl;
    f2(17, 5, linkm, linkn);
    cout << "linkm = " << linkm << ", linkn = " << linkn << endl << endl;

    //цикл
    double x1 = 17.3;
    cout << "Переменная x1 = " << x1<<endl;

    for (int replay = 1; replay <= 3; replay++) {
        double x2 = 21;
        cout << replay << " повтор переменных х1 = " << x1 << " и х2 = " << x2 << endl;
    }
}