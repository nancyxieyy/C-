#include<iostream>
using namespace std;

bool isSorted(int* a, int N)
{
    for(int i = 0; i < N - 1; i++) {
        if(a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

int main()
{
    int N = 3;
    int* a = new int[N];
    srand(time(0));
    for (int i = 0; i < N; i++) {
        a[i] = 3 * i + 1;
        a[i] = rand() % 1000;
        cout << a[i] << " ";
    }
    cout << endl;
    
    if(isSorted(a, N)) {
        cout << "The arrat is sorted in ascending order." << endl;
    }
    else {
        cout << "The arrat isn't sorted in ascending order." << endl;
    }
    
    delete []a;
    
    return 0;
}