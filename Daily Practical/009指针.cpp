#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int num = 10;
    int *p = &num;//int *p; p = &num;
    cout<<"p="<<p<<endl;//p为num的地址
    cout<<"*p="<<*p<<endl;//*p为num地址里的值，为10
    return 0;
}