#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#include "link.cpp"
/*
    以学生管理链表完成动态链表的学习
*/
STU *head = NULL;

int main()
{
    help();

    while (1) {
        char cmd[64] = " ";
        cout<<"请输入操作指令："<<endl;
        cin>>cmd;

        if(strcmp(cmd, "help") == 0) {
            help();
        } else if (strcmp(cmd, "insert") == 0) {
            cout<<"请输入要插入的节点信息(num, name):"<<endl;
            STU tmp;
            cin>>tmp.num>>tmp.name;
            head = insertLink(head, tmp);

        } else if (strcmp(cmd, "print") == 0) {
            printLink(head);

        } else if (strcmp(cmd, "search") == 0) {
            cout<<"-----search------"<<endl;
        } else if (strcmp(cmd, "delete") == 0) {
            cout<<"-----delete------"<<endl;
        } else if (strcmp(cmd, "free") == 0) {
            cout<<"-----free------"<<endl;
        } else if (strcmp(cmd, "cls") == 0) {
            cout<<"\033c";
        } else if (strcmp(cmd, "quit") == 0) {
            return 0;
        }
    }
    
    return 0;
}