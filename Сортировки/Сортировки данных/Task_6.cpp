//Сначала по фамилии, потом по должности с помощью сортировки Шелла с шагом d =n/2^i.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <list>
#include <cmath> 
#include <algorithm>
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
	if (a.lastname > b.lastname) return true;
	else if (a.lastname == b.lastname && a.post > b.post) return true;
	else {
		return false;
	}
}

vector<int> steps(int n) { // вектор шага
	vector<int> a;
	int i = 0, step = 1;
	a.push_back(step);
	while (n / (2 * step) < 1) { // описывается формула 
		step = step * 2; // формула d = n/2^i
		a.push_back(step);
	}
	return a;
}
vector<People> sortShell(vector<People> vec_c) { // сортировка Шелла
	int step;
	vector<int> a = steps(vec_c.size());
	for (int k = a.size() - 1; k >= 0; k--) {
		step = a[k];
	}
	for (int i = step; i < vec_c.size(); i++) { // перестановка элементов
		for (int j = i - step; j >= 0 && vec_c[j] < vec_c[j + step]; j -= step) {
			swap(vec_c[j], vec_c[j + step]); // меняеются элементы
		}
	}
	return vec_c; // возвращается вектор vec_c
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
	vec = sortShell(vec); // сортировка этого вектора
	outputVec(vec); // Вывод вектора
	system("pause");
	return 0;
}