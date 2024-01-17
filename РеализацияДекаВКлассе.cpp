/* Необходимо описать структуру данных, обрабатывающую команды push* и pop* */

/* ФОРМАТЫ:
           Вход:
                В первой строке количество команд n. n ≤ 1000000.
                Каждая команда задаётся как 2 целых числа: a b.
                a = 1 - push front
                a = 2 - pop front
                a = 3 - push back
                a = 4 - pop back
                Команды добавления элемента 1 и 3 заданы с неотрицательным параметром b, для дека используются все четыре команды..
                Если дана команда pop*, то число b - ожидаемое значение..
                Если команда pop вызвана для пустой структуры данных, то ожидается “-1”
           Вывод:
                 Вывести YES - если все ожидаемые значения совпали, иначе, если хотя бы одно ожидание не оправдалось, то напечатать NO.
                 Реализовать дек с динамическим зацикленным буфером.
                 ДЕК ДОЛЖЕН БЫТЬ РЕАЛИЗОВАН В ВИДЕ КЛАССА!
 */



#include <iostream>
#include <cassert>
#include <cstring>

#define STARTING_BUFF_CAPACITY 3
#define ARRAY_INCREASING_COEFF 2
#define ARRAY_DECREASING_COEFF 2


class Deque {
public:
    Deque() : size(0), capacity(STARTING_BUFF_CAPACITY), head_index(0), tail_index(0) {
        buffer = new int[STARTING_BUFF_CAPACITY];
    }

    ~Deque() {
        delete[] buffer;
    }

    Deque(const Deque &) = delete;

    Deque &operator=(const Deque &) = delete;

    Deque(const Deque &&) = delete;

    Deque &operator=(const Deque &&) = delete;



//..........................................................................
    void push_front(const int val) {
        if(size == capacity){
            grow();
        }
        head_index = ((head_index - 1) + capacity) % capacity;

        buffer[head_index] = val;
        size++;
        return;
    }

    void push_back(const int val) {
        if(size == capacity){
            grow();
        }
        buffer[tail_index] = val;
        tail_index = (tail_index + 1) % capacity;

        size++;
        return;
    }

    int pop_front() {
        assert(!empty());

        int val = buffer[head_index];

        if (head_index == capacity - 1) {
            head_index = 0;
        } else {
            head_index++;
        }

        size--;
        return val;
    }

    int pop_back() {
        assert(!empty());

        if (tail_index == 0) {
            tail_index = capacity - 1;
        } else {
            tail_index--;
        }

        int val = buffer[tail_index];
        size--;
        return val;
    }

    const bool empty() const {
        return size == 0;
    }

private:
    void grow() {
        size_t new_capacity = ARRAY_INCREASING_COEFF * capacity;
        int *tmp_buffer = new int[new_capacity];

        memcpy(tmp_buffer, buffer + head_index, (capacity - head_index) * sizeof(int));

        if (head_index != 0) {
            memcpy(tmp_buffer + (capacity - head_index), buffer, tail_index * sizeof(int));
        }

        delete[] buffer;

        buffer = tmp_buffer;
        head_index = 0;
        tail_index = capacity;
        capacity = new_capacity;
    }

    void shrink() {
        size_t new_capacity = capacity / ARRAY_DECREASING_COEFF;
        int **buffer = new int *[new_capacity];
        if (size > 0) {
            size_t target = 0;

            if (head_index <= tail_index) {
                for (size_t i = head_index; i <= tail_index; i++) {
                    buffer[target] = buffer[i];
                    target++;
                }
            } else {
                for (size_t i = head_index; i < capacity; i++) {
                    buffer[target] = buffer[i];
                    target++;
                }
                for (size_t i = 0; i <= tail_index; i++) {
                    buffer[target] = buffer[i];
                    target++;
                }
            }
            head_index = 0;
            tail_index = target - 1;
        } else {
            head_index = 0;
            tail_index = 0;
        }
        capacity = new_capacity;
        delete[] buffer;
        buffer = buffer;
    }

private:
    int *buffer;
    size_t size;
    size_t capacity;
    size_t head_index;
    size_t tail_index;
};

int main() {
    int n = 0;
    Deque deque;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int command = 0;
        int value = 0;
        int result = 0;
        std::cin >> command >> value;

        switch (command) {
            case 1:
                deque.push_front(value);
                break;
            case 2:
                if (deque.empty()) {
                    result = -1;
                } else {
                    result = deque.pop_front();
                }
                if (value != result) {
                    std::cout << "NO" << std::endl;
                    return 0;
                }
                break;
            case 3:
                deque.push_back(value);
                break;
            case 4:
                if (deque.empty()) {
                    result = -1;
                } else {
                    result = deque.pop_back();
                }
                if (value != result) {
                    std::cout << "NO" << std::endl;
                    return 0;
                }
                break;
            default:
                std::cout << "NO" << std::endl;
                return 0;

        }
    }
    std::cout << "YES" << std::endl;

    return 0;
}
