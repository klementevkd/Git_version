#include<iostream>//3
#include <list>
#include<iterator>
#include<algorithm>


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


	std::cout << "Removing the minimum element: ";
	it = std::min_element(this_list.begin(), this_list.end());
	this_list.erase(it);
	std::cout << "\n";
	copy(this_list.begin(), this_list.end(), std::ostream_iterator<int>(std::cout, " "));
}