#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>

using namespace std;

ifstream inp("input.txt");

//метод деления по зарплате

struct people {//структура для записи инофрмации
	int merc, exper;
	string name, prof, data;
};



struct list {//создаем структуру лист
	people inf;
	list* next;
	list* prev;
};



void push(list*& h, list*& t, people x) {//функция заполнения
	list* r = new list;
	r->inf = x;
	r->next = NULL;//следующий в ноль
	if (!h && !t) {//если пустой лист
		//то предыдущий в ноль
		//а голову перезаписываем 
		r->prev = NULL;
		h = r;
	}
	else {// конец указываем на новый элемент
		t->next = r;
		r->prev = t;
	}
	t = r;
}



void del(list*& h, list*& t, list* r) {//удаление
	if (r == h && r == t) {
		h = t = NULL;
	}
	else if (r == h) {//если удаляем голову
		//перезаписываем голову на следующий элемент
		h = h->next;
		h->prev = NULL;
	}
	else if (r == t) {//если удаляем конец
		//то конец указываем на предыдущий
		t = t->prev;
		t->next = NULL;
	}
	else {//если удаляем середину 
		// то следующий указываем на предыдущий и обратно
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r;
}


int m = 13;
vector<pair <list*, list*>> hesh(m);//вектор листов


void find() {//поиск
	int k;
	cout << "Введите зарплату человека, которого хотите найти" << endl;
	cin >> k;
	list* p = hesh[k % m].first;//находим блок, в котором лежит ответ
	while (p) {//перебираем все элементы
		if (p->inf.merc == k) {//если наши подходящий, выводим на экран
			cout << p->inf.name << " " << p->inf.prof << " " << p->inf.data << " " << p->inf.exper << " " << p->inf.merc << endl;
		}
		p = p->next;
	}
}



void append() {//добавить
	people p;
	cout << "Введите данные человека: Фамилия, профессия, дата рождения(дд.мм.гггг), стаж работы, зарплата" << endl;
	cin >> p.name >> p.prof >> p.data >> p.exper >> p.merc;
	int a = p.merc % m;//определяем, в каком блоке должен лежать новый элемент
	push(hesh[a].first, hesh[a].second, p);//добавляем в соответствующий лист этот элемент
}



void remove() {//удаление
	cout << "Введите зарплату людей, которых хотите удалить" << endl;
	int k;
	cin >> k;
	int a = k % m;//определяем блок, который нужно удалить
	list* p = hesh[a].first;
	while (p) {//пока не дошли до конца
		if (p->inf.merc == k) {//если нашли элемент который нужно удалить 
			if (p == hesh[a].second && p == hesh[a].first) {//если элемент единственный
				del(hesh[a].first, hesh[a].second, p);//удаляем и выходим из цикла
				break;
			}
			else if (p == hesh[a].second) {//если удаляем последний элемент
				p = p->prev;//переходим на предыдущий, удаляем следующий и выходим из цикла
				del(hesh[a].first, hesh[a].second, p->next);
				break;
			}
			else {//иначе переходим к следующему элементу и удаляем предыдущий
				p = p->next;
				del(hesh[a].first, hesh[a].second, p->prev);
			}
		}//если элемент удалять не нужно, переходим к следующему
		else {
			p = p->next;
		}
	}
}



void print() {//вывод на экран
	for (int i = 0; i < m; i++) {//перебираем все блоки
		list* p = hesh[i].first;
		cout << i << ")";
		if (p == NULL) {//если блок пустой, выводим NULL
			cout << "NULL" << endl;
		}

		else {
			while (p) {//иначе перебираем блок отдельно
				cout << p->inf.name << "  \t";
				p = p->next;
			}
			cout << endl;
		}
	}
}

int main() {
	SetConsoleCP(1251);//для вывода на русском языке, ибо штука ниже не работает 
	SetConsoleOutputCP(1251);//это тоже
	//setlocale(LC_ALL, "RUS");
	for (int i = 0; i < m; i++) {//создание вектора листов
		list* h = NULL;
		list* t = NULL;
		hesh[i].first = h;
		hesh[i].second = t;
	}


	while (inp.peek() != EOF) {//заполнение
		people p;
		inp >> p.name >> p.prof >> p.data >> p.exper >> p.merc;
		int a = p.merc % m;
		push(hesh[a].first, hesh[a].second, p);//в соответствующий лист записываем информацию
	}

	bool b = 1;


	while (b) {//для удобства 
		int s;

		cout << "Какую операцию хотите выполнить?" << endl;
		cout << "Найти элемент: 1" << endl << "Добавить элемент: 2" << endl << "Удалить элемент: 3" << endl << "Вывести хеш-таблицу на экран: 4" << endl;

		cin >> s;
		cout << endl;
		switch (s) {
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
			//для удаления
			remove();
			cout << endl;
			break;
		case 4:
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