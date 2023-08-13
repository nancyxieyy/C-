#include <iostream>
using namespace std;

//定义链表节点类型
struct STU
{
    //数据域
    int num;
    char name[32];

    //指针域
    STU *next;
};

void help(void)
{
    cout<<"*****************************"<<endl;
    cout<<"help:帮助信息                *"<<endl;
    cout<<"insert:插入链表节点           *"<<endl;
    cout<<"print:遍历链表               *"<<endl;
    cout<<"search:查询链表某个节点        *"<<endl;
    cout<<"delete:删除链表某个节点        *"<<endl;
    cout<<"free:释放整个链表             *"<<endl;
    cout<<"quit:退出程序                *"<<endl;
    cout<<"cls:清空屏幕                 *"<<endl;
    cout<<"*****************************"<<endl;
}

STU *insertLink(STU *head, STU tmp)
{
    //从堆区申请带插入的节点空间
    STU *pi = new STU;
    //给空间赋值
    *pi = tmp;
    pi->next = NULL;

    //判断是否为空
    if(NULL == head) {
        //不存在
        head = pi;
    } else {
        //链表存在
        pi->next = head;
        head = pi;
    }
    return head;
}

//遍历链表
void printLink(STU *head)
{
    //判断链表是否为空
    if(NULL == head) {
        //不存在
        cout<<"link not exist"<<endl;
        return;
    }
    STU *pb = head;
    while(pb != NULL) {
        cout<<pb->num<<" "<<pb->name<<endl;
        pb = pb->next;
    }
    return;
}