#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <set>

using namespace std;

int main() {
    string m = "aaabbcdddde";
     set <char> s;
    cout << "5) " << endl;
    cout << "string: ";
    for (string::iterator it = m.begin(); it != m.end(); it++) // заполнение контейнера различными символами строки
        cout << *it;
    cout << endl;
    for (string::iterator it = m.begin(); it != m.end(); it++) { // заполнение контейнера различными символами строки
        s.insert(*it);
    }
    cout << "count = " << s.size() << endl; // кол-во различных символов 
}