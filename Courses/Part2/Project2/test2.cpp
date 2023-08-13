#include <iostream>
using namespace std;

//a
/* demonstration program for linear search */
int main1()
{
    // L1. allocate an int array, pointed by pi, and store each number in an
    // element of the array (e.g., pi[0] = 12, pi[1] = 211, ..., pi[7] = 4)
    int N = 8;
    int* pi = new int[N];
    pi[0] = 12;
    pi[1] = 211;
    pi[2] = 48;
    pi[3] = 501;
    pi[4] = 91;
    pi[5] = 82;
    pi[6] = 110;
    pi[7] = 4;

    // run three search tests
    for (int test = 1; test <= 3; test++) {
        // take a search request from keyboard
        cout << "Specify the number to be searched for: ";
        int key;
        cin >> key;

        // L2. implement linear search through the array for the 1st occurrence
        // of the key number; print the index if found or -1 otherwise
        int index = -1;
        for(int i = 0; i < N; i++) {
            if(pi[i] == key) {
                index = i;
                break;
            }
        }
        cout << index << endl;
        
        // L3. complete the statement, where XXX is what you think the
        // complexity is in terms of the order(s) of the size of the data set
        cout << "The complexity of the linear search is O(N)" << endl;
    }

    // L4. free the memory used by the array
    delete []pi;

    return 0;
}

//(b)
/* demonstration program for binary search */
// B1. implement binary search, below, through an int array pointed by pi from first
// to last for a specified key number; return the index if found or -1 otherwise
int binarySearch(int* pi, int first, int last, int key)
{
    int mid = (first + last) / 2;
    if(first > last) {
        return -1;
    }
    if(key < pi[mid]) {
        return binarySearch(pi, first, mid - 1, key);
    }
    if(key == pi[mid]) {
        return mid;
    }
    if(key > pi[mid]) {
        return binarySearch(pi, mid + 1, last, key);
    }
}

int main2()
{
    // B2. allocate an int array, pointed by pi, and store each number in an
    // element of the array
    int N = 8;
    int* pi = new int[N];
    pi[0] = 12;
    pi[1] = 211;
    pi[2] = 48;
    pi[3] = 501;
    pi[4] = 91;
    pi[5] = 82;
    pi[6] = 110;
    pi[7] = 4;

    // run three search tests
    for (int test = 1; test <= 3; test++) {
        // take a search request from keyboard
        cout << "Specify the number to be searched for: ";
        int key;
        cin >> key;

        // B3. call binarySearch to search for the key number; print the
        // index if found or -1 otherwise
        cout << binarySearch(pi, 0, N -1, key) << endl;

        // B4. complete the statement, where XXX is what you think the
        // complexity is in terms of the order(s) of the size of the data set
        cout << "The complexity of the binary search is O(log N)" << endl;
    }
    delete[] pi;

    return 0;
}

//(c)
/* demonstration program for hashing-based search */
// H1. write a good hash function (such as the one used in the lecture notes), which
// converts a string key to a hash index in a hash table of the given tableSize
size_t Hash(string key, size_t tableSize)
{

}

int main()
{
    // choose a suitable tableSize (e.g. 223), allocate an int array (i.e. the hash
    // table) of this size pointed by pht
    int tableSize = 223;
    int* pht = new int[tableSize];

    // H2. store the numbers in the hash table, e.g., 12 in a location specified by
    // Hash("12", tableSize)

    // run three search tests
    for (int test = 1; test <= 3; test++) {
        // take a search request from keyboard
        cout << "Specify the number to be searched for: ";
        int key;
        cin >> key;

        // H3. perform hashing-based search for the key number in the table;
        // print the index if found or -1 otherwise

        // H4. complete the statement, where XXX is what you think the
        // complexity is in terms of a suitable measure
        cout << "The hashing-based search is potentially O(XXX)" << endl;
    }
    
    delete[] pht;
    
    return 0;
}