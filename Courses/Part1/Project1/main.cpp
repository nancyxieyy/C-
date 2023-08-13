#include "iClass.h"
#include "iClass.cpp"
#include<iostream>
using namespace std;

int main()
{
    iClass obj(200);

    obj.print();

    int i = 12;

    cout<<obj.count_of(i)<<endl;

    obj.~iClass();

    return 0;
}