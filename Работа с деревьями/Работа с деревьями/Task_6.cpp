// Дано дерево. Определить степень узла Х.
#include<iostream>
#include <string>
using namespace std;

struct tree { // структура дерева
	int dual; // значения узла
	tree* right; // правый узел
	tree* left; // левый узел
	tree* parent; // родитель 
};

tree* node(int x) { // начальный узел 
	tree* n = new tree; // выделение памяти под узел
	n->dual = x; // значение узла 
	n->left = NULL; // левый узел равен нулю
	n->right = NULL; // правый узел равен нулю
	n->parent = NULL; // родитель равен нулю 
	return n; // возврат 
}

void insert(tree*& tr, int x) { // вставка
	tree* n = node(x); // cоздание узла
	if (!tr) // если дерево пустое 
		tr = n; // n - корень
	else {// Иначе
		tree* y = tr; // дерево
		while (y){ // ищем куда вставлять элемент  
			if (n->dual > y->dual) // правая ветка
				if (y->right) // если правый узел не ноль
					y = y->right; // правый узел
				else {// Иначе
					n->parent = y; // узел становится правым ребенком
					y->right = n; // правый узел
					break; // выход из цикла
				}
			else if (n->dual < y->dual) // Левая ветка
				if (y->left) // если левый узел не ноль
					y = y->left; // левый узел
				else {
					n->parent = y; // узел становится левым ребенком
					y->left = n; // левый узел
					break; // выход из цикла
				}
		}
	}
}

void inorder(tree* tr) {//симметричный обход
	if (tr) { // если элемент не ноль 
		inorder(tr->left); //  обходим левый узел 
		cout << tr->dual << " "; // вывод на экран 
		inorder(tr->right); //  обходим правый узел 
	}
}

tree* find(tree* tr, int x) { // функция поиска
	if (!tr || x == tr->dual) // нашли или дошли до конца ветки 
		return tr; // возврат tr
	if (tr->dual != x)  // если элемента нет
		tr->dual = 0; // принимает значение 0
		return tr; // возврат tr
	if (x < tr->dual) // если x меньше корня 
		return find(tr->left, x); // ищем по левой ветке
	else // иначе 
		return find(tr->right, x); // ищем по правой ветка
}

int main() {
	setlocale(LC_ALL, "RUS"); // подключение русской раскладки 
	int n, X, k = 0, x; // Объявление переменных
	cout << "n = "; // вывод на экран
	cin >> n; // ввод n
	cout << "X = "; // вывод на экран
	cin >> X; // ввод x
	tree* tr = NULL; //объявление дерева 
	for (int i = 0; i < n; i++){ // заполнение дерева
		cout << i << ": "; // вывод на экран
		cin >> x; // ввод x
		insert(tr, x); // вставка в дерево
	}
	inorder(tr); // cимметричный обход
	cout << endl;
	tree* ptr = NULL; // Объявление узла
	ptr = find(tr, X); // присвоение ему узла с значением X
	if (ptr->dual == 0) { // если элемент равен нулю
		cout << "Элемент не найден" << endl; // вывод на экран
		return 0; // возврат 
	}
	else {
		if (ptr->left) // Если узел имеет левого ребенка
			k++; // увеличиваем на 1
		if (ptr->right) // если узел имеет правого ребенка
			k++; // увеличиваем на 1
	}
	cout << "k = " << k << endl; // Выводим счетчик
	return 0; // возврат 
}