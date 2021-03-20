#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if (lhs != nullptr && rhs != nullptr) {
        int temp = *lhs;
        *lhs = *rhs;
        *rhs = temp;
    } else return;
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_rows <= 0 || num_cols <= 0) {
        return nullptr;
    } else {
        int **arr = new int *[num_rows];
        for (int i = 0; i < num_rows; i++) {
            arr[i] = new int[num_cols];
        }
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                arr[i][j] = init_value;
            }
        }
        return arr;
    }
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if (num_rows < 0 || num_cols < 0 || arr_2d_source == nullptr || arr_2d_target == nullptr)
        return false;
    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_cols; j++)
            arr_2d_source[i][j] = arr_2d_target[i][j];
    return true;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    for (int j = 0; j < arr.size() / 2; j++) {
        int temp = arr[j];
        arr.at(j) = arr.at(arr.size() - j - 1);
        arr.at(arr.size() - j - 1) = temp;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (arr_begin != nullptr && arr_end != nullptr) {
        int arrSize = arr_end - arr_begin + 1;
        for (int i = 0; i < arrSize / 2; i++) {
            int temp = arr_begin[i];
            arr_begin[i] = arr_begin[arrSize - 1 - i];
            arr_begin[arrSize - 1 - i] = temp;
        }
    }
}

// Задание 6
int *find_max_element(int *arr, int size) {
    int *max = &arr[0];
    if (!arr || size < 0) {
        return nullptr;
    } else {
        for (int i = 0; i < size; i++) {
            if (*max < arr[i]) {
                max = &arr[i];
            }
        }
    }
    return max;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    auto odd_numbers_ref = std::vector<int>{};
    for (int element: arr) {
        if (std::abs(element) % 2 == 1) {
            odd_numbers_ref.push_back(element);
        }
    }

    return odd_numbers_ref;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    auto newArr = std::vector<int>{};
    for (int element: arr_a) {
        for (int element2: arr_b) {
            if (element == element2) {
                newArr.push_back(element);
            }
        }
    }
    return newArr;
}
