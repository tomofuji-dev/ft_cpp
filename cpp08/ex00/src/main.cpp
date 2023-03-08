#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <set>

template <class T>
void print_container(T& c) {
	std::cout << "[";
	for (typename T::iterator it = c.begin(); it != c.end(); it++) {
		if (it != c.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << "]" << std::endl;
}

template <class T>
void print_find_result(T& c, int query) {
	typename T::iterator it = easyfind<T>(c, query);
	if (it != c.end())
		std::cout << "easy_find (" << query <<") : " << *it << std::endl;
	else
		std::cout << "easy_find (" << query << ") : not found." << std::endl;
}


int main() {
	std::cout << "=== test vector ===" << std::endl;
	std::vector<int> test1;
	for (int i = 0; i < 5; i++) {
		test1.push_back(i + 1);
	}
	print_container(test1);
	for (int i = 0; i < 7; i++) {
		print_find_result(test1, i);
	}
	std::cout << "=== test set ===" << std::endl;
	std::set<int> test2;
	for (int i = 0; i < 5; i++) {
		test2.insert(i + 1);
	}
	print_container(test2);
	for (int i = 0; i < 7; i++) {
		print_find_result(test2, i);
	}
	return 0;
}
