#include "header.h"
#include "header.cpp"
#include <iostream>
using namespace std;
#define InitSize 10
#define IncSize 5

int main()
{
    SeqList<int>ob;
    ob.ListInsert(1, 1);
    cout<<ob.data[0]<<endl;

    return 0;
}