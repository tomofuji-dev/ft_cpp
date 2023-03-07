#pragma once
#include <cstddef>

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
