#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>

using namespace std;

ifstream inp("input.txt");
int m = 8;
double k = 0.61803;//золотое сечение 
//квадратичное, методом умножения. по зп


struct people {
	int merc, exper;
	string name, prof, data;
};


int n;
vector < pair <int, people>> hesh;
int c1, c2;



void find() {//функция поиска элемента
	int x;
	cout << "Введите зарплату человека, которого хотите найти" << endl;
	cin >> x;
	int pos = int((x * k - (int)(x * k)) * m);//определяем, примерную позицию числа x
	int j = 0;
	while (true) {//пока не нашли куда вставить
		pos = (pos + c1 * j + c2 * j * j) % (2 * n);//считаем новую позицию для числа х
		if (hesh[pos].first == x) {//если нашли, выводим на экран всю информацию
			cout << hesh[pos].second.name << " " << hesh[pos].second.prof << " " << hesh[pos].second.data << " " << hesh[pos].second.exper << " " <<  hesh[pos].second.merc;
			break;

		}
		j++;//увеличиваем коэфициент на 1
		if (j > 2 * n) {//если количество операций уйдет за количество всех элементов, значит свободных мест нет
			cout << "Некуда вставить элемент" << endl;
		}
	}
}



void append() {//вставка элемента
	people p;
	cout << "Введите данные человека: Фамилия, профессия, дата рождения(дд.мм.гггг), стаж работы, зарплата" << endl;
	cin >> p.name >> p.prof >> p.data >> p.exper >> p.merc;
	int x = p.merc;
	int pos = int((x * k - (int)(x * k)) * m);//считаем примерную позицию
	int j = 0;
	while (true) {//пока не нашли куда вставить
		pos = (int)(pos + c1 * j + c2 * j * j) % (2 * n);//новая позиция для х
		if (hesh[pos].first == 0) {//если место свободное место, ставим туда х
			hesh[pos].first = x;
			hesh[pos].second = p;
			break;//выходим из цикла 
		}
		j++;//увеличиваем коэфициент на 1
		if (j > 2 * n) {//если больше общего числа, значит мест нет
			cout << "Некуда вставить элемент" << endl;
			break;
		}
	}
}


void print() {
	//вывод на экран
	for (int i = 0; i < 2 * n; i++) {
		if (hesh[i].first)
			cout << hesh[i].second.name << endl;
	}
}



int main() {	
	setlocale(LC_ALL, "RUS");

	vector <people> a;//вектор, куда записываются информация о сотрудниках 
	while (inp.peek() != EOF) {//считываем с файла 
		people p;
		inp >> p.name >> p.prof >> p.data >> p.exper >> p.merc;
		a.push_back(p);
	}
	n = a.size();
	for (int i = 0; i < 2 * n; i++) {//заполняем хеш-таблицу
		people p;
		hesh.push_back(make_pair(0, p));
	}
	
	cout << "Введите параметры c1 и c2" << endl;
	cin >> c1 >> c2;

	//заполнение
	for (int i = 0; i < n; i++) {
		int pos = int((a[i].merc * k - (int)(a[i].merc * k)) * m);//считаем позицию х
		int j = 0;
		while (true) {//пока не нашли куда вставить
			pos = (pos + c1 * j + c2 * j * j) % (2 *  n);//новая позиция
			if (hesh[pos].first == 0) {//если есть место, вставляем туда х
				hesh[pos].first = a[i].merc;
				hesh[pos].second = 	a[i];
				break;
			}
			j++;
			if (j > 2 * n) {//есди больше общего количества, свободных мест нет
				cout << "Некуда вставить элемент" << endl;
			}
		}
	}
	
	bool b = 1;
	while (b) {//продолжаем пока не захотим закончить
		int s;

		cout << "Какую операцию хотите выполнить?" << endl;
		cout << "Найти элемент: 1" << endl << "Добавить элемент: 2" << endl << "Вывести хеш-таблицу на экран: 3" << endl;

		cin >> s;
		cout << endl;
		switch (s) {//операция над хеш-таблицей
		case 1:
			//фунция для поиска
			find();
			cout << endl;
			break;
		case 2:
			// для добавления
			append();
			cout << endl;
			break;
		case 3:
			//вывод хеш-таблицы
			print();
			cout << endl;
			break;
		default:
			break;
		}
		cout << "Хотите продолжить?" << endl << "Да: 1" << endl << "Нет: 0" << endl;;
		cin >> b;
		cout << endl;
	}
	cout << "Завершение работы" << endl;

}
