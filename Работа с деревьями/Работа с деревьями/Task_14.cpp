// Дано дерево. Вывести все листья.
#include<iostream>
#include <string>
using namespace std;

struct tree { // структура дерева
	int dual; // значения узла
	tree* right; // правый узел
	tree* left; // левый узел
};

tree * node(int x) { // функция создание узла 
	 tree * n = new tree; // выделение памяти
	 n->dual  = x; // значения узла х
	 n-> left = n-> right = NULL; // левый и правый узел ноль
	 return n; // возвращение готового узла
}

void create(tree*& tr, int n) { //функция создание идеально сбалансированного дерева 
	int x; // объявление переменной 
	if (n > 0) { // пока n больше нуля 
		cout << "Элемент:  "; // вывод на экран
		cin >> x; // ввод 
		tr = node(x); // создание узла
		int nl = n / 2; // нахождение кол-ва элементов в левой ветке
		int nr = n - nl - 1; // нахождение кол-ва элементов в правой ветке
		create(tr->left, nl); // рекурсивный вызов для левой ветки
		create(tr->right, nr); // рекурсивный вызов для левой правой
	}
}

void preorder(tree* tr){ // функция прямого обхода
	if (tr){ // если tr не ноль
		cout << tr->dual << " "; // вывод значения
		preorder(tr->left);  // рекурсивный вызов по левой ветке
		preorder(tr->right); // рекурсивный вызов по правой ветке
	}
}
 
void printLeaf(tree* tr) { // функция вывода листьев 
	if ((tr->left == NULL) && (tr->right == NULL)) // если у узла нет детей
		cout << "лист:" << tr->dual << "\n"; // выводим 
	else { // иначе 
		if (tr->left) printLeaf(tr->left); // вызов рекурсивной функции для левой ветки
		if (tr->right) printLeaf(tr->right); // вызов рекурсивной функции для правой ветки
	}
}

int main() {
	setlocale(LC_ALL, "RUS"); // подключение русской раскладки
	int n; // объявление переменной 
	cout << "n = "; // вывод на экран
	cin >> n; // ввод n
	tree* tr = NULL; // объявление дерева 
	create(tr, n); // вызов функции заполнения дерева
	preorder(tr);  // прямой обход
	cout << endl; 
	printLeaf(tr); // вызов функции вывода листьев 
	return 0;
}
