//Сначала по должности, потом по стажу ипотом по зарплате с помощью сортировки пузырьком
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <list>
#include <cmath> 
#include <algorithm>
#include<map>
using namespace std;


struct Date { // дата
	int dd; // день
	int mm; // месяц
	int yy; // год
};

struct People {//данные о человеке
	string lastname; //фамилия 
	string post; // должность
	Date date; //дата рождения
	int salary; //зарплата 
	int experience; // стаж 
};

Date strToDate(string str) {//из строки в дату
	Date date;
	string temp = str.substr(0, 2);//день
	date.dd = atoi(temp.c_str());
	temp = str.substr(3, 2);//месяц
	date.mm = atoi(temp.c_str());
	temp = str.substr(6, 4);//год
	date.yy = atoi(temp.c_str());
	return date;
}

vector<People> input() {// Функция ввода
	People people; // Объявление переменных
	vector<People> vec_c;
	string pr = "";
	int pos_s = 0, pos_s_p = 0; // объявление переменных
	ifstream in("input.txt"); // входной файловый поток
	while (getline(in, pr)) { // Пока считывается строка, разделяем ее по структуре
		// Фамилия
		pos_s = pr.find(" ", pos_s_p); // нахождение пробела
		people.lastname = pr.substr(pos_s_p, pos_s - pos_s_p); // выписываем фамилию
		pos_s_p = pos_s + 1; // позиция пробела + 1
		// Дата рождения
		pos_s = pr.find(" ", pos_s_p); // нахождение пробела
		people.date = strToDate(pr.substr(pos_s_p, pos_s - pos_s_p)); // выписываем дату рождения
		pos_s_p = pos_s + 1;// позиция пробела + 1
		// Должность
		pos_s = pr.find(" ", pos_s_p); // нахождение пробела
		people.post = pr.substr(pos_s_p, pos_s - pos_s_p); // выписываем должность
		pos_s_p = pos_s + 1;// позиция пробела + 1
		// Зарплата
		pos_s = pr.find(" ", pos_s_p); // нахождение пробела
		people.salary = atoi(pr.substr(pos_s_p, pos_s - pos_s_p).c_str()); // выписываем зарплату
		pos_s_p = pos_s + 1;// позиция пробела + 1
		// Опыт
		pos_s = pr.find(" ", pos_s_p); // нахождение пробела
		people.experience = atoi(pr.substr(pos_s_p, pos_s - pos_s_p).c_str()); // выписываем опыт
		pos_s_p = pos_s + 1;// позиция пробела + 1

		pos_s = 0; pos_s_p = 0; // обнуление позиций 
		vec_c.push_back(people); // записывает в конец вектора
	}
	in.close();
	return vec_c;
}

bool operator < (People a, People b) {//переопределяем оператор < в соотвествии с условием
	if (a.post < b.post) return true;
	if (a.post == b.post && a.experience < b.experience) return true;
	if (a.post == b.post && a.experience == b.experience && a.salary < b.salary) return true;
	return false;
}

vector<People> bubbleSort(vector<People> vec_с) { // сортировка пузырьком 
	for (int i = 0; i < vec_с.size() - 1; ++i) {//прогоняет весь вектор
		for (int j = 0; j < vec_с.size() - 1; ++j) {
			if (vec_с[j + 1] < vec_с[j]) {
				swap(vec_с[j + 1], vec_с[j]);// temp = arr[j];arr[j] = arr[j + 1];arr[j + 1] = temp; просто меняю местами
				
				
			}

		}
	}
	return vec_с; // возращает вектор
}
	




void outputVec(vector<People> vec_c) { // Функция вывода вектора
	ofstream out("output.txt");
	for (int i = 0; i < vec_c.size(); ++i) {
		out << vec_c[i].lastname << " "; // фамилия
		if (vec_c[i].date.dd < 10 && vec_c[i].date.mm < 10) out << '0' << vec_c[i].date.dd << "." << '0' << vec_c[i].date.mm << "." << vec_c[i].date.yy << " "; // если день и месяц меньше 10, то перед датой поставится 0 (вывод даты рождения)
		if (vec_c[i].date.dd > 10 && vec_c[i].date.mm < 10) out << vec_c[i].date.dd << "." << '0' << vec_c[i].date.mm << "." << vec_c[i].date.yy << " "; // если день больше 10, а месяц меньше, то перед  датой месяца поставится 0 (вывод даты рождения)
		if (vec_c[i].date.dd > 10 && vec_c[i].date.mm > 10 || vec_c[i].date.dd == 10 && vec_c[i].date.mm == 10) out << vec_c[i].date.dd << "." << vec_c[i].date.mm << "." << vec_c[i].date.yy << " "; // если день и месяц больше или равны 10, то выводится дата рождения
		out << vec_c[i].post << " "; // должность
		out << vec_c[i].experience << " "; // опыт
		out << vec_c[i].salary << " "; // зарплата
		out << endl;
	}
	out.close();
}

int main() {
	vector<People> vec; // Объявление вектора
	vec = input(); // Ввод данных в этот вектор
	vec = bubbleSort(vec); // сортировка этого вектора
	outputVec(vec); // Вывод вектора
	system("pause");
	return 0;
}