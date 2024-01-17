/*
    Входное число лежит в диапазоне 0..232 -1 и вводится в десятичном виде.
    Если в числе содержится только один бит со значением 1, записать в выходной поток OK. Иначе записать FAIL
/*


#include <iostream>
#include <cassert>

bool only_one_1bit(int N) {
    assert(N >= 0);
    if (N == 0){
        return false;
    }

    unsigned short counter = 0;
    unsigned int mask = 1;
    for (int i = 0; i <= 32; i++) {
        if ((N & mask) != 0) {
            counter++;
            if (counter != 1) {
                return false;
            }
        }
        mask = mask << 1;
    }
    return true;
}

int main() {
    int N = 0;
    std:: cin >> N;
    if (!only_one_1bit(N)){
        std::cout << "FAIL";
        return 0;
    }
    std::cout << "OK";
    return 0;
}
