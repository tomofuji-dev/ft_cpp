#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>

void insertion_sort(std::vector<int>& nums, int start, int end) {
    for (int i = start + 1; i < end; ++i) {
        int key = nums[i];
        int j = i - 1;
        while (j >= start && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

void insertion_sort(std::deque<int>& nums, int start, int end) {
    for (int i = start + 1; i < end; ++i) {
        int key = nums[i];
        int j = i - 1;
        while (j >= start && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

void merge(std::vector<int>& nums, int start, int mid, int end) {
    int n1 = mid - start;
    int n2 = end - mid;
    int L[n1 + 1], R[n2 + 1];

    for (int i = 0; i < n1; i++) L[i] = nums[start + i];  
    for (int i = 0; i < n2; i++) R[i] = nums[mid + i];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int j = 0, k = 0;
    for (int i = start; i < end; i++) {
        if (L[j] <= R[k]) {
            nums[i] = L[j++];
        }
        else {
            nums[i] = R[k++];
        }
    }
}

void merge(std::deque<int>& nums, int start, int mid, int end) {
    int n1 = mid - start;
    int n2 = end - mid;
    int L[n1 + 1], R[n2 + 1];

    for (int i = 0; i < n1; i++) L[i] = nums[start + i];  
    for (int i = 0; i < n2; i++) R[i] = nums[mid + i];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int j = 0, k = 0;
    for (int i = start; i < end; i++) {
        if (L[j] <= R[k]) {
            nums[i] = L[j++];
        }
        else {
            nums[i] = R[k++];
        }
    }
}

void ford_johnson_sort(std::vector<int>& nums, int start, int end) {
    int size = end - start + 1;

    if (size <= 2) {
        insertion_sort(nums, start, end);
        return;
    }

    int mid = (start + end) / 2;
    ford_johnson_sort(nums, start, mid);
    ford_johnson_sort(nums, mid, end);
    merge(nums, start, mid, end);
}

void ford_johnson_sort(std::deque<int>& nums, int start, int end) {
    int size = end - start + 1;

    if (size <= 2) {
        insertion_sort(nums, start, end);
        return;
    }

    int mid = (start + end) / 2;
    ford_johnson_sort(nums, start, mid);
    ford_johnson_sort(nums, mid, end);
    merge(nums, start, mid, end);
}

int main() {
    std::vector<int> vec = {7, 2, 9, 4, 3, 8, 6, 1, 5};
    std::deque<int> deq = {7, 2, 9, 4, 3, 8, 6, 1, 5};
    ford_johnson_sort(vec, 0, vec.size());
    ford_johnson_sort(deq, 0, deq.size());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::copy(deq.begin(), deq.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
