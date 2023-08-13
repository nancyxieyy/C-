#include <iostream>
using namespace std;
/*
    Person有name和age属性，
    提供初始化函数(Init)，
    提供对name和age的读写函数(set, get)，
    但必须确保age的赋值在有效范围内(0~100)，
    超出有效范围则拒绝赋值，并提供方法输出姓名和年龄
*/

class Person {
private:
    char name[32];
    int age;
public:
    void Init(void) {
        //初始化函数
        cout<<"请输入姓名：";
        cin>>name;
        cout<<"请输入年龄(0-100)：";
        cin>>age;
        if(age > 100 || age <= 0) {
            cout<<"请重新输入正确年龄(0-100)：";
            cin>>age;
        } else {
            cout<<"输入完成！"<<endl;
        }
    }

    void setAge(void) {
        //改年龄函数        
        cout<<"请输入新的年龄：";
        cin>>age;
        if(age > 100 || age <= 0) {
            cout<<"请重新输入正确年龄(0-100)：";
            cin>>age;
        } else {
            cout<<"输入完成！"<<endl;
        }
    }

    void getAge(void) {
        //读年龄
        cout<<age<<endl;
    }

    void setName(void) {
        cout<<"请重新输入姓名：";
        cin>>name;
    }

    void getName(void) {
        cout<<name<<endl;
    }

    void showPerson(void) {
        cout<<"姓名："<<name<<endl;
        cout<<"年龄："<<age<<endl;
    }
};

int main()
{
    Person lucy, bob;

    lucy.Init();
    lucy.showPerson();
    
    bob.Init();
    bob.showPerson();

    lucy.showPerson();
  
    return 0;
}