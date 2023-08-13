#include<iostream>
using namespace std;

int find_first_not_in_range(int* pi, int N, int L, int U);

void print_duplicate(int* pi1, int N1, int* pi2, int N2);

int main1()
{
    int N = 10;
    int* pi = new int[N];

    for(int i = 0; i < N; i++) {
        pi[i] = rand() % 11;
        cout << pi[i] << " ";
    }


    cout << "The number is " << find_first_not_in_range(pi, N, 1, 50) << endl;

    cout<< "The complexity of find_first_not_in_range is" << "O(N)" << endl;
    delete[] pi;

    return 0;
}

//从0-N中搜索第一个不在[L, U]里的数
int find_first_not_in_range(int* pi, int N, int L, int U)
{
    for(int i = 0; i < N; i++) {
        if(!(pi[i] >= L && pi[i] <= U)) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int N1 = 0, N2 = 0;
    cout << "Please wirte down the N1 and N2" << endl;
    cin >> N1;
    cin >> N2;
    cout << "N1=" << N1 << " , N2=" << N2 << endl;
    
    int* pi1 = new int[N1];
    int* pi2 = new int[N2];
    
    //N1
    for(int i = 0; i < N1; i++) {
        pi1[i] = rand() % (N1 + 1);
        cout << pi1[i] << " ";
    }
    cout << endl;

    //N2
    for(int i = 0; i < N2; i++) {
        pi2[i] = rand() % (N2 + 1);
        cout << pi2[i] << " ";
    }
    cout << endl;

    print_duplicate(pi1, N1, pi2, N2);

    cout << "The complexity of print_duplicate is " << "O(N1 * N2)" << endl;

    delete []pi1;
    delete []pi2;

    return 0;
}

void print_duplicate(int* pi1, int N1, int* pi2, int N2)
{
    for(int i = 0; i < N1; i++) {
        for(int j = 0; j < N2; j++) {
            if(pi1[i] == pi2[j]) {
                cout << "The element is " << pi1[i] << endl;
                break;
            }
        }
    }
}