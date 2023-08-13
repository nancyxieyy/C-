#include <iostream> //头文件包含
//iostream 标准的输入输出流

//使用命名空间std
using namespace std;

//有且只有一个main，它是唯一入口
//int函数返回值类型
//main是函数名
//main右边（）里描述函数的形参（形参类型 形参名）
int main(int argc, char *argv[])
{
    //cout输出设备（终端，屏幕）
    //“”作用的是字符串
    //endl换行
    cout << "Hello World!" << endl <<"Hello C++";
    //return将其后面的表达式结果或数值作为函数的返回值返回
    return 0;
}