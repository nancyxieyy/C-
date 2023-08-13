#include <iostream>
//#include <bitset>
using namespace std;

int main(int argc, char *argv[])
{
    int arr[5] = {10, 20, 30, 40, 50};
    cout<<arr[0]<<endl;
    cout<<arr[1]<<endl;
    cout<<arr[2]<<endl;
    cout<<arr[3]<<endl;
    cout<<arr[4]<<endl;
    cout<<"-----------------"<<endl;
    int i = 0;
    for(i = 0; i < 5; i++)
    {    
        cout<<arr[i]<<endl;
    }
    return 0;
}