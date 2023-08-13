#include <iostream>
using namespace std;

int search(char *pchs, int size, char key) {
    int i = 0, count = 0;
    /*
    for(i = 0; i < size; i++) {
        if(pchs[i] == key) {
            count++;
        }
    }
    */

    for(i = 0; i < size; i++) {
        if(*(pchs++) == key) {
            count++;
        }
    }
    
    return count;
}

int main()
{
    int size;
    cout << "Please input the size of the array: ";
    cin >> size;

    char key;
    cout << "Please input the character you want to search(a-z): ";
    cin >> key;

    char *pchs = new char[size];
    int i = 0;

    if(pchs != NULL) {
        for(i = 0; i < size; i++) {
            pchs[i] = rand()%26 + 97;
            //cout << pchs[i] << " ";
            cout << *(pchs++) << " ";
        }
        cout << endl;
    }

    int count = search(pchs, size, key);
    cout << "Occurrences = " << count << endl;

    delete [] pchs;
    return 0;
      
}