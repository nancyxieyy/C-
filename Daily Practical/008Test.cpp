#include <iostream>
using namespace std;

//函数声明
void inputIntArray(int arr[], int n);
void outputIntArray(int arr[], int n);
void sortIntArray(int arr[], int n);

int main()
{
    int arr[5] = {0};
    int n = sizeof(arr) / sizeof(arr[0]);

    //获取键盘输入
    inputIntArray(arr, n);

    //遍历数组
    outputIntArray(arr, n);

    //对数组排序
    sortIntArray(arr, n);

    //遍历数组
    outputIntArray(arr, n);

}

//获取键盘输入
void inputIntArray(int arr[], int n)
{
    cout<<"请输入"<<n<<"个int类型数："<<endl;
    int i = 0;
    for(i = 0; i < n; i++) {
        cin>>arr[i];
    }
    return;
}

//遍历数组
void outputIntArray(int arr[], int n)
{
    int i = 0;
    for(i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

//数组排序
void sortIntArray(int arr[], int n)
{
    int i = 0;
    for(i = 0; i < n - 1; i++) {
        int j = 0;
        for(j = 0; j < n-i-1; j++) {
             int temp;
             if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
             }
        }
    }
    return;
}