#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void insertion_sort(std::vector<int>& vec, int start, int end) {
    for (int i = start + 1; i < end; ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= start && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void merge(std::vector<int>& vec, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    std::vector<int> left(n1), right(n2);

    std::copy(vec.begin() + start, vec.begin() + mid + 1, left.begin());
    std::copy(vec.begin() + mid + 1, vec.begin() + end + 1, right.begin());

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            vec[k++] = left[i++];
        } else {
            vec[k++] = right[j++];
        }
    }

    while (i < n1) {
        vec[k++] = left[i++];
    }

    while (j < n2) {
        vec[k++] = right[j++];
    }
}

void ford_johnson_sort(std::vector<int>& vec, int start, int end) {
    int size = end - start + 1;

    if (size <= 16) {
        insertion_sort(vec, start, end);
        return;
    }

    int mid = (start + end) / 2;
    ford_johnson_sort(vec, start, mid);
    ford_johnson_sort(vec, mid + 1, end);
    merge(vec, start, mid, end);
}

int main() {
    std::vector<int> data = {7, 2, 9, 4, 3, 8, 6, 1, 5};
    ford_johnson_sort(data, 0, data.size() - 1);

    std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
