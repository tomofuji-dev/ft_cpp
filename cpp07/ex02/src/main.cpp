#include "Array.hpp"

// int main() {
// 	{
// 		Array<int> arr1;
// 		Array<int> arr2(arr1);
// 		std::cout << arr1 << std::endl;
// 		std::cout << arr2 << std::endl;
// 	}
// 	{
// 		try {
// 			Array<unsigned int> arr1(100);
// 			std::cout << arr1 << std::endl;
// 			for (unsigned int i = 0; i < arr1.size(); i++) {
// 				arr1[i] = i;
// 			}
// 			Array<unsigned int> arr2(arr1);
// 			std::cout << arr1 << std::endl;
// 			std::cout << arr2 << std::endl;
// 			std::cout << arr1[arr1.size()];
// 		}
// 		catch (std::exception& e) {
// 			std::cerr << e.what() << std::endl;
// 		}
// 	}
// 	return 0;
// }

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

__attribute__((destructor))
void destructor() {
	system("leaks -q exe");
}
