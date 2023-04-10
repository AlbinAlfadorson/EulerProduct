#include <iostream>

using namespace std;

double ABS(double );


int main()
{

    double x;
    cin >> x;
    double result = ABS(x);
    cout << result << endl;
    return 0;
}

double ABS(double n)
{

    return n > 0.0 ? n : -n;
}
