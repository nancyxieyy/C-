#include "Stack.h"
#include "StackNode.h"
#include <iostream>
using namespace std;

int main1()
{
    //(a)
    //(1)
    Stack<char>* pchs = new Stack<char>;
    //(2)
    char ch = '\0';
    while(cin>>ch) {
        if(ch == '#')
            break;
        pchs->push(ch);
    }
    //(3)
    pchs->print();
    //(4)
    Stack<char>* chs = pchs;
    //(5)
    chs->print();
    //(6)
    while(pchs->size() > 0) {
        cout<<pchs->pop()<<" ";
    }
    cout<<endl;

    delete pchs;

    return 0;
}

template<typename T>
int remover(Stack<T>& stack, T d)
{
    for(int i = 0; i < stack->size; i++) {
        if(stack->item == d){
            stack->pop();
            stack = stack->
        }
    }
    
}

int main()
{

}