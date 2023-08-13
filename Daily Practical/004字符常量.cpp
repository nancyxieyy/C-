#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout<<'a'<<endl;//直接输出a
    cout<<(int)'a'<<endl;//ASCII得加个int

    char ch = '\0';
    cout<<"请输入一个字符";
    //cin会判断ch的类型为ch类型，一次只能获取一个字符
    cin>>ch;
    cout<<"ch = "<<ch<<endl;
    //cin会跳过起始的空格和回车

    char ch1 = '\0';
    cout<<"请输入一个字符";
    cin>>ch1;
    if (ch1 >= 'a' && ch1 <= 'z') {
        ch1 = ch1 - ('a' - 'A');
    }
    else if (ch1 >= 'A' && ch1 <= 'Z') {
        ch1 = ch1 + ('a' - 'A');
    }

    cout<<ch1<<endl;

    return 0;
}