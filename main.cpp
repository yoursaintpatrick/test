/**
 * @file main.cpp
 * @author Дмитрий Певцов
 * @brief 
 * @version 0.1
 * @date 2021-10-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <fstream> 
using namespace std;
/**
 * @brief Функция calculator
 * 
 * @details Вычисляет выражение из файла
 * @param fin поток ввода откуда берётся выражение
 * @return результат вычислений
 */
int calculator(ifstream& fin)
{
    int res; 
    int num;
    char op;
    fin >> res;
    while (!fin.eof())
    {
        fin >> op >> num;
        if (op == '+')
            res += num;
        else if (op == '-')
            res -= num;    
        else
            cerr << "invalid input" << endl;  
    }
    return res;
}

/**
 * @brief Функция тест  ирования
 * 
 * 3 теста, которые проверяют выражения из 3 файлов
 * 
 */
void test()
{
    int res;
    ifstream test1("test1.txt");
    res = calculator(test1);
    if (res == 110)
        cout << "test 1: correct, result = " << res << endl;
    else
        cout << "test 1: ERROR(wrong answer), result = " << res << endl;
    test1.close();

    ifstream test2("test2.txt");
    res = calculator(test2);
    if (res == 175)
        cout << "test 2: correct, result = " << res << endl;
    else
        cout << "test 2: ERROR(wrong answer), result = " << res << endl;
    test2.close();

    ifstream test3("test3.txt");
    res = calculator(test3);
    if (res == -29)
        cout << "test 3: correct, result = " << res << endl;
    else
        cout << "test 3: ERROR(wrong answer), result = " << res << endl;
    test3.close();
}

int main()
{
    test();
    return 0;
}