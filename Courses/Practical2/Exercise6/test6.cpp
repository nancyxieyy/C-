#include<iostream>
using namespace std;

bool bInster(int*& pi, int& size, int pos, int val) {
    int sizeNew = size + 1;
    int *piNew = new int [size];

    if(pos < 0 || piNew == NULL || pos >= sizeNew) {
        return false;
    }
    else {
        for(int i = 0; i < pos; i++) {
            piNew[i] = pi[i];
        }
        piNew[pos] = val;
        for(int i = pos + 1; i < sizeNew; i++) {
            piNew[i] = pi[i - 1];
        }
    }

    delete []pi;

    pi = piNew;
    size = sizeNew;

    return true;
}

int main()
{
    int size = 0;
    int *pi = NULL;

    for(int i = 0; i < 10; i++) {
        if(!bInster(pi, size, i, 40)) {
            cout<<"Insertion fails"<<endl;
            return 1;
        }
    }

    for(int i = 0; i < size; i++) {
        cout<<pi[i]<<" ";
    }
    cout<<endl;

    if(!bInster(pi, size, 3, 0)) {
        cout<<"Insertion fails"<<endl;
        return 1;
    }

    for(int i = 0; i < size; i++) {
        cout<<pi[i]<<" ";
    }
    cout<<endl;

    delete[] pi;

    return 0;
}