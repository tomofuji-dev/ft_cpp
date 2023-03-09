#pragma once
#include <algorithm>

template <class T>
typename T::iterator	easyfind(T& container, const int query) {
	return std::find(container.begin(), container.end(), query);
}

template <class T>
typename T::const_iterator	easyfind(const T& container, const int query) {
	return std::find(container.begin(), container.end(), query);
}
