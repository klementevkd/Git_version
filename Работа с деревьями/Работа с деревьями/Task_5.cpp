// Дано дерево. Удалить четные элементы
#include<iostream>
#include <string>
using namespace std;

struct tree{ // структура дерева
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
	tree* n = node(x); //создание узла
	if (!tr) // если дерево пустое 
		tr = n; // n корень дерева
	else { // иначе 
		tree* y = tr; // дерево 
		while (y) { // ищем куда вставлять 
			if (n->dual, y->dual) // правая ветка
				if (y->right) // если правый узел не ноль
					y = y->right; // правый узел 
				else { // иначе 
					n->parent = y; // узел становится правым ребенком 
					y->right = n; // правый узел 
					break; // выход из цикла 
				}
			else if(n->dual < y->dual) // левая ветка
				if (y->left) // если левый узел не ноль 
					y = y->left; // левый узел 
				else { // иначе 
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
	if (x < tr->dual) // если 
		return find(tr->left, x); // ищем по левой ветке
	else // иначе 
		return find(tr->right, x); // ищем по правой ветка
}

tree* Min(tree* tr) { // функция поиск минимума 
	if (!tr) // нет левого ребенка 
		return tr; // возврат tr
	else return Min(tr->left); // идем по левой ветке до конца 
}

tree* Next(tree* tr, int x) { // функция поиска следующего элемента
	tree* n = find(tr, x); // ищем узел со значением x
	if (n->right) // если есть правый ребенок
		return Min(n->right); // минимальный по правой ветке 
	tree* y = n->parent; // родитель
	while (y && n == y->right) { // пока не дошли до корня или узла - правый ребенок 
		n = y; // идем вверх по дереву 
		y = y->parent;  
	}
	return y; // возвращаем родителя 
}

void Delete(tree*& tr, tree* v) {//удаление узла
	 tree * p = v->parent; // p родитель v
	 if (!p) 
		 tr = NULL; //дерево содержит один узел
	 else if (!p->parent && !v->left && !v->right) {
		 delete v;
	 }
	 
	 else if (!p->parent && !v->left || !v->right) {
		 if (!p) {
			 if (!v->left) { //если есть правый ребенок
				 tr = v->right; //он становится корнем
				 v->parent = NULL;
			 }
			 else { //аналогично для левого
				 tr = v->left;
				 v->parent = NULL;
			 }
		 }
	 }

	 else if (!p->parent && v->right && v->left) {
		 
	 }

	 else if (!v->left && !v->right) {//если нет детей
		 if (p->left == v) //указатель у левого родителя меняем на NULL
			 p->left = NULL;
		 if (p->right == v) // указатель у правого родителя меняем на NULL
			 p->right = NULL;
		 delete v; // освобождение памяти

	 }

	 else if (!v->left || !v->right) {//если только один ребенок
		 if (!p) { //если удаляем корень, у которого 1 ребенок
			 if (!v->left) { //если есть правый ребенок
				tr = v->right; //он становится корнем
				v->parent = NULL;
			}
			 else { //аналогично для левого
					 tr = v->left;
				 v->parent = NULL;
			}
		}
		 else {
			 if (!v->left) { //если есть правый ребенок
				 if (p->left == v) //если удаляемый узел явл. левым ребенком
					 p->left = v->right; //ребенок удаляемого узла становится левым ребенком своего "деда"
					 else
					 p->right = v->right; //ребенок удаляемого узла становится правым ребенком своего "деда"
					 v->right->parent = p; //родителем ребенка становится его "дед"
				
			}
			 else { //аналогично для левого ребенка
				 if (p->left == v)
					 p->left = v->left;
				 else
					 p->right = v->left;
				 v->left->parent = p;
			}
			delete v;
		}
	}
	 else {//есть оба ребенка
		 tree * succ = Next(tr, v->dual);//следующий за удаляемым узлом
		 v->dual = succ->dual; //присваиваем значение
		 if (succ->parent->left == succ) {//если succ левый ребенок
			 succ->parent->left = succ->right; //его правый ребенок становится левым ребенком своего "деда"
				 if (succ->right) //если этот ребенок существует
				 succ->right->parent = succ->parent; //его родителем становится "дед"
		}
		 else {//аналогично если succ - правый ребенок
			 succ->parent->right = succ->right;
			 if (succ->right)
				succ->right->parent = succ->parent;
		}
		 delete succ;
	}
}

void deleteItem(tree* tr, tree* ptr){ // Функция удаления четных элементов
	if (ptr){ // Если узел не ноль 
			deleteItem(tr, ptr->left); // рекурсивный вызов удаления правой ветки
			if (ptr->dual % 2 == 0) { // если элемент четный 
				Delete(tr, ptr); // удаляем его 
				ptr = tr; // присвоение нового дерева
			}
			deleteItem(tr, ptr->right); // рекурсивный вызов удаления правой ветки
	}
}

int main() {
	int n, x; // объявление переменных
	cout << "n = "; // вывод на экран n
	cin >> n; // ввод n
	tree* tr = NULL; // объявления дерева 
	for (int i = 0; i < n; i++) { // заполнение дерева 
		cout << i << " : "; // вывод на экран 
		cin >> x; // ввод элемента 
		insert(tr, x); // вставка в дерево 
	}
	inorder(tr); // симметричный обход 
	cout << endl;
	tree* ptr = tr; // объявление  дополнительного дерева, который равен основному 
	deleteItem(tr, ptr); // вызов функции удаления четных элементов
	inorder(tr); // симметрический обход 
	return 0; // возвращение 
}