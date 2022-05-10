// Дан неориентированный граф. Выяснить, является ли граф связным.
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

vector<vector<int>> input(){ // функция ввода списка смежности из файла
	ifstream in("input.txt"); // открываем файловый поток 
	vector<vector<int>> vec; // создаем двумерный вектор
	int pos_n = 0, pos_p = 0, i = 0; // объявляем переменные
	string yhy = "", deal = ""; //объявление строк 
	while (getline(in, yhy)){ // пока есть несчитанные строки
		vec.push_back(vector<int>()); // записываем вектор в вектор
		do{
			pos_n = yhy.find(" ", pos_p); // ищем пробел
			deal = yhy.substr(pos_p, pos_n - pos_p); // выделяем число
			vec[i].push_back(atoi(deal.c_str())); // добавляем его в вектор
			pos_p = pos_n + 1; // обновляем позиции
		} while (pos_n != -1); // пока можно считать цифры из строки
		i++; // обновляем строку вектора
	}
	return vec; // Возвращаем двумерный вектор
}

int main(){
	setlocale(LC_ALL, "RUS"); // подключение русской раскладки 
	vector<vector<int>> vec; // создаем двумерный вектор
	vec = input(); // записываем в него список смежности
	int* nodes = new int[vec.size()]; // создаем массив вершин
	for (int i = 0; i < vec.size(); i++){ // изначально они все равны 0
		nodes[i] = 0;
	}
	int count = 0; // переменная количества вершин
	stack<int> stark; // создаем стек
	stark.push(0); // записываем туда нулевую вершину
	while (!stark.empty()){ // пока очередь не пуста
		int node = stark.top(); // извлекаем вершину
		stark.pop();
		if (nodes[node] == 2) 
			continue;
		nodes[node] = 2; // отмечаем вершину как посещенную
		for (int i = vec[node].size() - 1; i != 0; i--){ // считываем все исходящие ребра из этой вершины
			if (nodes[vec[node][i]] == 0) // если эта вершина не встречена и не обнаружена
				stark.push(vec[node][i]); // записываем ее в стек
			nodes[vec[node][i]] = 1; // отмечаем вершину как обнаруженную
		}
		count++; // увеличиваем счетчик вершин
	}
	if (count == vec.size()) // если количество вершин не совпало с количеством пройденных вершин
		cout << "Связный граф" << endl; // вывод
	else  // иначе
		cout << "Несвязный граф" << endl; // вывод
	return 0; // возвращение 0
}