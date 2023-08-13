#include<iostream>
#include "func.h"


//全局函数
void cmpFunc(int ar1, int ar2, int vo1, int vo2) {
    //比较两个立方体
    if(ar1 != ar2 && vo1 != vo2) {
        cout<<"两个立方体不相等!"<<endl;
    } else {
        cout<<"两个立方体相等!"<<endl;
    }
}

//主函数
int main()
{
    Cube cube1;
    Cube cube2;
    
    cube1.cubeInit();
    cube2.cubeInit();
    
    int ar1 = cube1.getArea();
    int vo1 = cube2.getVolume();
    cout<<"得出第一个立方体的面积是："<<ar1<<" 体积是："<<vo1<<endl;
    
    int ar2 = cube2.getArea();
    int vo2 = cube2.getVolume();
    cout<<"得出第二个立方体的面积是："<<ar2<<" 体积是："<<vo2<<endl;
    
    cmpFunc(ar1, ar2, vo1, vo2);

    return 0;
}