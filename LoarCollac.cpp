// ГЕПОТЕЗА ЛОТАРА КОЛАТСА -- 3X^2 + 1 or /2
// Данная программа считает количество шагов, увеличений и уменьшений по дереву, до самого зацикливания,
#include <iostream>

//using namespace std;
typedef unsigned long long ull;
ull itter1(0), itter2(0);

ull ITTER(ull);

int main()
{
    ull num, IT = 0;
    std::cin >> num;
    ull RESULTAT = ITTER(num);
    ++IT;
    while(RESULTAT > 4)
    {


        RESULTAT = ITTER(RESULTAT);
        IT++;


    };
    std::cout << IT;

    return 0;
}
ull ITTER(ull x)
{
    ull result = x;
    if(x % 2)
    {
        ++itter1;
        return result = x * 3 + 1; // - result = result * 3 + 1
    };

    ++itter2;
    return result /= 2;
}

// ГЕПОТЕЗА ЛОТАРА КОЛАТСА -- 3X^2 + 1 or /2
