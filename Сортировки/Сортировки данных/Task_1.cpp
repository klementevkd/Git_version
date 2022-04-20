#include <string> //Библиотека для работы со строками
#include <iostream>  //Библиотека потока ввода-вывода данных
#include <vector>  //Библиотека для работы с вектором
#include <cmath>  //Библиотека для работы с математическими функциями
#include <algorithm> //Библиотека для работы с алгоритмами
#include <cstdlib>  //Библиотека для работы с динамической памятью
#include <ctime> //Возвращает указатель на строку следующего формата
#include <fstream> //Бибилотека для работы с файлами 
#include <iomanip>  //Библиотека для работы с манипуляторами

using namespace std; //Пространство имен std

struct date {   //Создаем структуру
    int dd, mm, yy; //Указываем тип 
};

struct person {  //Создаем структуру
    string surname;   //Фамилия
    string doljnost;   //Должность
    date dt; //Дата
    int staj; //Стаж работы
    int salary;  //Зарплата

};

bool operator < (person a, person b) {  //Сортировка по зарплате 
    if (a.salary < b.salary) return true;
    else return false;
}


bool operator > (person a, person b) {
    if (a.salary > b.salary) return true;
    else return false;

}

void q_sort(vector <person>& v, int b0, int e0)  //Быстрая сортировка
{
    person d = v[e0];
    int e = e0;
    int b = b0;
    do {
        while (v[b] < d)  //Пока условие выполняется
            ++b;
        while (v[e] > d)  //Пока условие выполняется
            --e;
        if (b <= e) {
            swap(v[b], v[e]);  //Меняем местами
            ++b;  //Прибавляем единицу
            --e;  //Убавляем единицу
        }
    } while (b <= e);  //Пока условие выполняется
    if (e > b0) {
        q_sort(v, b0, e);
    }
    if (b < e0) {
        q_sort(v, b, e0);
    }
}

void print(vector <person>& v) {  //Выдача результата
    ofstream out;
    out.open("output.txt");
    for (int i = 0; i < v.size(); i++) {
        out << left << setw(11) << v[i].surname;  
        out << left << setw(14) << v[i].doljnost;
        if (v[i].dt.dd < 10) out << left << "0" << v[i].dt.dd << ".";  //Если условие выполняется то выдаем 
        else out << left << v[i].dt.dd << ".";
        if (v[i].dt.mm < 10) out << "0" << v[i].dt.mm << ".";  //Если условие выполняется то выдаем 
        else out << v[i].dt.mm << ".";
        out << left << setw(6) << v[i].dt.yy;  //Вывод
        out << left << setw(4) << v[i].staj;    //Вывод
        out << left << setw(9) << v[i].salary << endl;   //Вывод
    }
}

int main()
{
    ifstream in;
    in.open("input.txt");  //Открываем файл
    vector <person> v;
    while (!in.eof()) {  //Пока условие выполняется выполняем цикл

        person p;
        in >> p.surname >> p.doljnost >> p.dt.dd;  //Считываем фамилию должность дату
        in.ignore(1, '.');
        in >> p.dt.mm;
        in.ignore(1);
        in >> p.dt.yy >> p.staj >> p.salary;  //Считываем дату стаж и зарплату
        v.push_back(p);

    }

    q_sort(v, 0, v.size() - 1);
    print(v);  //Вывод
    return 0;
}