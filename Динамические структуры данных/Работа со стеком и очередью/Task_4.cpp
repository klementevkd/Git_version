//Создать стек, содержащий целые числа. Удалить первый кратный Х элемент
#include <iostream> 
using namespace std;

struct stack{ // Структура стека
	int inf; // Значение текущего элемента
	stack* next; // Указатель на следующий элемент 
};

void push(stack*& NEXT, const int INF){ // Функция добавления элемента в стек
	stack* r = new stack;  // Объявляем переменную
	r->inf = INF; // Записываем значение переданное в функцию в стек
	r->next = NEXT; // Связываем новый элемент стека с предыдущим
	NEXT = r; // Новый элемент становится вершиной стека
}

int pop(stack*& NEXT){ // Функция извлечения элемента из стека
	int temp = NEXT->inf; // Находим значение из вершины стека и записываем в переменную temp
	stack* r = NEXT; // Запоминаем указатель на элемент стека
	NEXT = NEXT->next; // Вершиной становиться новый элемент, который был прошлой вершиной
	delete r; // Удаляем прошлую вершину
	return temp; // Возвращение элемента
}


int main(){
	setlocale(LC_ALL, "rus"); // Включаем русский язык
	int n, x, temp; // Объявление переменных
	bool flag = false; // добавляем флаг
	stack* st = NULL; // Объявление первого стека
	stack* new_st = NULL; // Объявление второго стека
	cout << "x = "; // Вывод на экран 
	cin >> x; // ввод х
	cout << "n =  "; // Вывод на экран
	cin >> n; // Ввод колличества элементов
	for (int i = 0; i < n; i++) { // заполнение стека
		cout << "a[" << i << "]: "; 
		cin >> temp; // Ввод элемента
		push(st, temp); // Отправляем его в конец стека
	}

	for (int i = 0; i < n; i++) // цикл для перевората стека
		push(new_st, pop(st)); 

	cout << "Новый стек: ";
	for (int i = 0; i < n; i++) { // Заполнение стека
		temp = pop(new_st); // Извлечение последнего элемента стека
		if ((temp % x == 0) && flag == false) // Если элемент кратен X и он не попадался раньше то обновляем флаг
			flag = true; // Обновление флага
		else
			cout << temp << " "; // вывод всех элементов
	}
	return 0;
}