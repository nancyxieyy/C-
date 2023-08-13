#include "iClass.h"
#include<iostream>
using namespace std;

//(1)
iClass::iClass(int len)
{
    length = len;
    pints = new int[length];
    srand(time(0));
    for(int i = 0; i < length; i++) {
        pints[i] = rand()%26;
    }
}

//(2)
iClass::~iClass()
{
    delete [] pints;
}

//(3)
void iClass::print() const
{
    for(int i = 0; i < length; i++) {
        cout<<pints[i]<<" ";
    }
    cout<<endl;
}

//(4)
int iClass::count_of(int i) const
{
    int num = 0;
    for(int j = 0; j < length; j++) {
        if(pints[j] == i) {
            num++;
        }
    }
    return num;
}