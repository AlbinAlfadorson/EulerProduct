/*
  Дан массив целых чисел А[0..n-1]
  Известно, что на интервале [0, m] значения массива строго возрастают,
  а на интервале [m, n-1] строго убывают!
  НАЙТИ:
        m за O(log m).
  Логика решения:  
                 Время работы O(log m).. Сначала необходимо определить диапазон для бинарного поиска
                 размером порядка m с помощью экспоненциального поиска,
                 после чего уже в нем делать бинарный поиск..
  2 ≤ n ≤ 10000..
*/
#include <iostream>
#include <cassert>

std::pair<int, int> exp_search(int *array, int arr_size) {
    std::pair<int, int> sub_array_index = {0, 1};
    while (sub_array_index.second < arr_size && array[sub_array_index.second] > array[sub_array_index.first]) {
        sub_array_index.first = sub_array_index.second;
        sub_array_index.second *= 2;
    }
    if (sub_array_index.first != 0) {
        sub_array_index.first -= 1;
    }
//    sub_array_index.second -= 1;   не вычитаем потому что нам нужен индекс указывающий на элемент сразу после последнего
    if (sub_array_index.second > arr_size) {
        sub_array_index.second = arr_size ;
    }
    return sub_array_index;
}

int binary_search(int *array, std::pair<int, int> index) {
    int mid = 0;
    while (index.first < index.second) {
        mid = index.first + ((index.second - index.first) / 2);
        if (array[mid] == array[index.first]) {
            break;
        }
        if (array[mid] > array[mid - 1]) {
            index.first = mid;
        } else {
            index.second = mid;
        }
    }
    return mid;
}


int main() {
    int N = 0;
    std::cin >> N;
    assert(N > 1 && N <= 10000);

    int *array = new int[N];
    for (int i = 0; i < N; i++) {
        std::cin >> array[i];
    }

    std::cout << binary_search(array, exp_search(array, N));
    delete [] array;
    return 0;
}
