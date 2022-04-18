#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <set>

using namespace std;

int main() {
    list <int> a = { 2, 3, 5, 8, 1, 7, 9, 4, 6, 10 };
    list <int> b = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "list 1: ";
    for (list<int>::iterator iter = a.begin(); iter != a.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
    cout << "list 2: ";
    for (list<int>::iterator iter = b.begin(); iter != b.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
    cout << "pr = " << inner_product(a.begin(), a.end(), b.begin(), 0) << endl; // перемножение значений на соответсвующих позициях
}