#include<iostream>
using namespace std;

void bubbleSort(int* a, int N)
{
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - 1 - i; j++){
            if(a[j] > a[j + 1]) {
                int tmp = 0;
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

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
    int N = 10;
    int* a = new int[N];
    
    srand(time(0));
    for(int i = 0; i < N; i++) {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;

    bubbleSort(a, N);

    for(int j = 0; j < N; j++) {
        cout << a[j] << " ";
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