//Дан неориентированный граф. Вывести на экран все вершины, не смежные с данной.
#include <iostream> 
#include <fstream> 
#include <vector> 
#include <string> 
using namespace std; 

vector<vector<int>> input(){ // функция ввода списка смежности из файла
	ifstream in("input.txt"); // открываем файловый поток 
	vector<vector<int>> vec; // создаем двумерный вектор
	int pos_prob = 0, pos_chess = 0, i = 0; // объявляем переменные
	string yhy = "", deal = ""; // объявление строк
	while (getline(in, yhy)){ // пока есть несчитанные строки
		vec.push_back(vector<int>()); // записываем вектор в вектор
		do{
			pos_prob = yhy.find(" ", pos_chess); // ищем пробел
			deal = yhy.substr(pos_chess, pos_prob - pos_chess); // выделяем число
			vec[i].push_back(atoi(deal.c_str())); // добавляем его в вектор
			pos_chess = pos_prob + 1; // обновляем позиции

		} while (pos_prob != -1); // пока можно считать цифры из строки
		i++; //обновляем строку вектора
	}
	return vec; // Возвращаем двумерный вектор
}

int main(){
	setlocale(LC_ALL, "RUS"); // подключение русской раскладки
	vector<vector<int>> vec; // создаем двумерный вектор
	vec = input(); // записываем в него список смежности
	int peak = 0; // переменная вершины
	cout << "Вершина: "; 
	cin >> peak; // ввод вершины
	vector<int> buf; // создаем буфферный вектор с вершинами
	for (int i = 0; i < vec[peak].size(); i++){ // считываем все вершины исходящие из вершины peak
		buf.push_back(vec[peak][i]); // записываем их в буфферный вектор
	}
	for (int i = 0; i < vec.size(); i++){ // идем по всем вершинам
		bool flag = false; // создаем флаг
		for (int k = 0; k < buf.size(); k++){
			if (i == buf[k] || i == peak){ // если мы встречаем смежную вершину или саму вершину
				flag = true; // то flag = true
				break; // прерываем цикл
			}
		}
		if (flag) // если встретили смежные вершины
			continue; // продолжанием
		else // иначе 
			cout << i << endl; // если не встретили выводим эту вершину
	}
	return 0; // возвращение 0
}