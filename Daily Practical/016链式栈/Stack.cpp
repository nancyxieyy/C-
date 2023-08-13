#define InitSize 10
#define IncSize 5
#include<iostream>
using namespace std;

template <typename T>
struct StackNode
{
    T data;//数据域
    StackNode<T>* next;//指针域，指向下一个同类型节点
};

template <typename T>
class LinkStack
{
public:
	LinkStack();
    ~LinkStack();

public:
    bool Push(const T& e);//入栈
    bool Pop(T& e);//出栈
    bool GetTop(T& e);//读取，并没有出栈

    void DispList();//输出所有元素
    int ListLength();//获取顺序栈的长度
    bool Empty();
    bool IsFull();

private:
    void IncreaseSize();//扩容

private:
    StackNode<T> * m_top;//栈顶指针
    int m_length;//链式栈当前长度
};

template <typename T>
LinkStack<T>::LinkStack()
{
    m_top = NULL;
    m_length = 0;
}

template <typename T>
LinkStack<T>::~LinkStack()
{
    T tmpnousevlaue = {0};
    while(Pop(tmpnousevlaue) == true) {}//把栈顶元素删光
}

template <typename T>
bool LinkStack<T>::Push(const T& e)
{
    StackNode<T> *node = new StackNode<T>;
    node->data = e;
    node->next = m_top;
    m_top = node;
    m_length++;
    return true;
}

template <typename T>
bool LinkStack<T>::Pop(T& e)
{
    if(Empty() == true) {
        return false;
    }

    StackNode<T>* p_willdel = m_top;
    m_top = m_top->next;
    m_length--;
    e = p_willdel->data;
    delete p_willdel;
    return true;
}

template <typename T>
bool LinkStack<T>::GetTop(T& e)
{
    if(Empty() == true) {
        return false;
    }
    e = m_top->data;
    return true;
}

template <typename T>
void LinkStack<T>::DispList()
{
    if(Empty() == true) {
        return ;
    }

    StackNode<T>* p = m_top;
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

template <typename T>
int LinkStack<T>::ListLength()
{
    return m_length;
}

template <typename T>
bool LinkStack<T>::Empty()
{
    if(m_top == NULL)
    return true;
    return false;
}

int main()
{
    LinkStack<int> slinkobj;
    slinkobj.Push(12);
    slinkobj.Push(48);
    slinkobj.Push(100);
    slinkobj.Push(36);
    slinkobj.DispList();

    int eval = 0;
    slinkobj.Pop(eval);
    slinkobj.DispList();
}