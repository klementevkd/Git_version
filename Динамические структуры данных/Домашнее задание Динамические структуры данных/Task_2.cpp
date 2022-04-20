#include<iostream>//2
#include <list>
#include<iterator>
#include<algorithm>

bool odd(int x) {//������
	return x % 2 == 0;
}

int main() {
	int kol, pr;
	std::list <int> this_list;
	std::cout << "Enter the dimension of the list" << std::endl;
	std::cin >> kol;

	for (int(i) = 0; i < kol; i++) {
		std::cin >> pr;
		this_list.push_back(pr);
	}

	std::list <int> ::iterator it;
	std::cout << "List: ";
	copy(this_list.begin(), this_list.end(), std::ostream_iterator<int>(std::cout, " "));

	std::cout << "\nThe last even element: ";
	it = std::remove_if(this_list.begin(), this_list.end(), odd);

	std::cout << *it << std::endl;
	return 0;
}