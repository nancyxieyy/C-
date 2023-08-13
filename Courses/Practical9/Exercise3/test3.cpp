#include <iostream>
using namespace std;

void quickSort(int* a, int first, int last)
{
    if(first < last) {
        int tmp = a[first];
        int i = first, j = last;
        while (i < j) {
            while (i < j && a[j] >= tmp) {
                j--;
            }
            if(i < j) {
                a[i++] = a[j];
            }
            while (i < j && a[i] < tmp) {
                i++;
            }
            if(i < j) {
                a[j--] = a[i];
            }
            a[i] = tmp;
            quickSort(a, first, i - 1);
            quickSort(a, i + 1, last);
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

    quickSort(a, 0, N - 1);

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