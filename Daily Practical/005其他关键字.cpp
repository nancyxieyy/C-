#include <iostream>
//#include <bitset>
using namespace std;

int main(int argc, char *argv[])
{
    int i = 0, sum = 0;
    while(i < 100)
    {
	    i++;
	    sum += i;
    }
    cout<<sum<<endl;

    return 0;
}