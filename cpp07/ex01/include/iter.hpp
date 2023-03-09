#pragma once
#include <cstddef>
#include <iostream>

template <class T>
void    iter(T array[], std::size_t len, void (*func)(T&)) {
    if (!array || !func) return;
    for (std::size_t i = 0; i < len; i++) {
        func(array[i]);
    }
}

template <class T>
void    iter(const T array[], std::size_t len, void (*func)(const T&)) {
    if (!array || !func) return;
    for (std::size_t i = 0; i < len; i++) {
        func(array[i]);
    }
}

template<typename T>
void increment(T& i) {
	i++;
}

template<typename T>
void print(const T& p) {
	std::cout << p << " ";
}
