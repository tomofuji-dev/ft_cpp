#pragma once
#include <algorithm>

template <class T>
typename T::iterator	easyfind(T& container, const int query) {
	return std::find(container.begin(), container.end(), query);
}
