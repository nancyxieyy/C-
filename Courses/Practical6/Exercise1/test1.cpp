#include<iostream>
using namespace std;

double rsquare(int n)
{
    double sum = 0;
    for(double i = 1; i <= n; i++) {
        sum += 1. / (i * i);
    }
    return sum;
}

int main()
{
    cout << "当n=1时，结果sum=" << rsquare(1) << endl;
    cout << "当n=2时，结果sum=" << rsquare(2) << endl;
    cout << "当n=3时，结果sum=" << rsquare(3) << endl;
    cout << "当n=4时，结果sum=" << rsquare(4) << endl;
    cout << "当n=5时，结果sum=" << rsquare(5) << endl;

    return 0;
}