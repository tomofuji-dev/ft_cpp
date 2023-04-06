#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>

#define OUTPUT_PREFIX "Time to process a range of 5 elements with "

typedef std::vector<int>::iterator  vec_iter;
typedef std::deque<int>::iterator   deq_iter;

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

    if (size <= 16) {
        insertion_sort(nums, start, end);
        return;
    }

    int mid = (start + end) / 2;
    ford_johnson_sort(nums, start, mid);
    ford_johnson_sort(nums, mid, end);
    merge(nums, start, mid, end);
}

template<typename iterator>
void print_iter(iterator start, iterator end) {
    static long print_size = 5;
    long        idx = 0;
    iterator    it = start;

    for (; it < end && idx < print_size - 1; it++, idx++) {
        if (it != start){
            std::cout << " ";
        }
        std::cout << *it;
    }
    if (end - start == print_size) {
        std::cout << " " << *it << std::endl;
    }
    else if (end - start > print_size) {
        std::cout << " [...]" << std::endl;
    }
    else {
        std::cout << std::endl;
    }
}

template<typename iterator>
bool is_sorted_iter(iterator start, iterator end) {
    for (iterator it = start + 1; it < end; it++) {
        if (*it < *(it - 1)) {
            return false;
        }
    }
    return true;
}

void output_result(std::vector<int>& vec, std::deque<int>& deq) {
    std::cout << "Before:   ";
    print_iter(vec.begin(), vec.end());

    std::clock_t start_time = std::clock();
    ford_johnson_sort(vec, 0, vec.size());
    std::clock_t end_time = std::clock();
    double time_vector = 1000000.0 * (end_time - start_time) / CLOCKS_PER_SEC;

    start_time = std::clock();
    ford_johnson_sort(deq, 0, deq.size());
    end_time = std::clock();
    double time_deque = 1000000.0 * (end_time - start_time) / CLOCKS_PER_SEC;

    std::cout << "After:   ";
    print_iter(vec.begin(), vec.end());
    std::cout << OUTPUT_PREFIX << "std::vector : " \
                << std::fixed << std::setprecision(6) << time_vector << " us | " \
                << (is_sorted_iter<vec_iter>(vec.begin(), vec.end()) ? "success" : "failed") \
                << std::endl;
    std::cout << OUTPUT_PREFIX << "std::deque : " \
                << std::fixed << std::setprecision(6) << time_deque << " us | " \
                << (is_sorted_iter<deq_iter>(deq.begin(), deq.end()) ? "success" : "failed") \
                << std::endl;
}

bool is_integer(const std::string& src) {
	size_t i = 0;

	if (src[0] == '-' || src[0] == '+') i++;
	for (; i < src.size(); i++) {
		if (!std::isdigit(src[i])) return false;
	}
	return true;
}

int convert_int(const std::string& src) {
    if (!is_integer(src)) {
        throw std::runtime_error("Error");
    }
    std::stringstream ss(src);
	int dest;
	ss >> dest;
    if (ss.fail() || dest <= 0) {
        throw std::runtime_error("Error");
    }
    return dest;
}

int main(int argc, char* argv[]) {
    std::vector<int> vec;
    std::deque<int> deq;

    if (argc < 2) {
        std::cerr << "argc error" << std::endl;
        return 1;
    }
    try {
        for (int i = 1; i < argc; i++) {
            vec.push_back(convert_int(std::string(argv[i])));
            deq.push_back(convert_int(std::string(argv[i])));
        }
        output_result(vec, deq);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
