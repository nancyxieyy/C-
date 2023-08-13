#include<iostream>
using namespace std;
/*
    reference 引用
    int a = 10;
    int &b = a;
    则b可以代表a
*/

void mul_div(double &first, double &second) {
    double temp = first * second;
    second = first / second;
    first = temp;
}

int main()
{
    double first = 4.0, second = 2.0;
    double *px = &first;
    double *py = &second;

    mul_div(first, second);

    cout << *px << " " << *py << endl;

    return 0;
}