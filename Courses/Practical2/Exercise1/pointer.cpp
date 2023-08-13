#include<iostream>
using namespace std;

int main()
{
    int i = 27;
    int *pi = &i;//pi = &i
    cout << "value of i is " << i << endl;//27
    cout << "value of pi (i.e. address of i) is " << pi << endl;//daaress
    cout << "value pi is pointing to, or from dereferencing pi, is " << *pi <<endl;// *pi = i = 27 

    *pi = 35;
    cout << "value of i is " << i <<endl;//35
    *pi = *pi * 2;//*pi = 35 * 2 =70
    cout << "value of i is " << i <<endl;//70

    double *pd = NULL;//pd = NULL;
    cout << "value of pd is " << pd << endl;//NULL

    return 0;
}
