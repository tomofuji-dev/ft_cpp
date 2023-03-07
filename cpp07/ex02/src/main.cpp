#include "Array.hpp"

int main() {
	{
		Array<int> arr1;
		Array<int> arr2(arr1);
		std::cout << arr1 << std::endl;
		std::cout << arr2 << std::endl;
	}
	{
		try {
			Array<unsigned int> arr1(10);
			std::cout << arr1 << std::endl;
			for (unsigned int i = 0; i < arr1.size(); i++) {
				arr1[i] = i;
			}
			Array<unsigned int> arr2(arr1);
			std::cout << arr1 << std::endl;
			std::cout << arr2 << std::endl;
			std::cout << arr1[arr1.size()];
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
