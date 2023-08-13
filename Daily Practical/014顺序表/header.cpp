#include "header.h"
#include <iostream>
using namespace std;
#define InitSize 10
#define IncSize 5

template <typename T>
SeqList<T>::SeqList (int length)
{
    data = new T[length];
    mlength = 0;
    maxsize = length;
}

template <typename T>
SeqList<T>::~SeqList()
{
    delete []data;
}

template <typename T>
bool SeqList<T>::ListInsert(int i, const T& e)
{
    if(i > mlength || i < 1 || mlength >= maxsize) {
        cout<<"error"<<endl;
        return false;
    }

    for(int j = mlength; j >= i; j-- ) {
        data[j] = data[j - 1];
    }
    data[i - 1] = e;
    mlength++;
    return true;
}

bool ListDelete(int i);
    
bool GetElem(int i, T& e);