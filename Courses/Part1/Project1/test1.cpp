#include<iostream>
using namespace std;

int sum(int n)
{
    int sum = 0;

    if(n <= 0) {
        cout<<"error!"<<endl;
    }

    for(int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main()
{
    int n = 0, result = 0;
    cout<<"Please input an integer number n: "<<endl;
    cin>>n;
    result = sum(n);
    cout<<"The integer number is "<<n<<endl;
    cout<<"The result is "<<result<<endl;

    return 0;
}