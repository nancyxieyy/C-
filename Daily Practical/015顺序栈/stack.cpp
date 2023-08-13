#define InitSize 10
#define IncSize 5
#include<iostream>
using namespace std;

template <typename T>
class SeqStack
{
public:
	SeqStack(int length = InitSize);
    ~SeqStack();

public:
    bool Push(const T& e);//入栈
    bool Pop(T& e);//出栈
    bool GetTop(T& e);//读取，并没有出栈

    void DispList();//输出所有元素
    int ListLength();//获取顺序栈的长度
    bool IsEmpty();
    bool IsFull();

private:
    void IncreaseSize();//扩容

private:
    T * m_data;//存放顺序栈元素
    int m_maxsize;//动态数组最大容量
    int m_top;//栈顶指针（用作数组下标），指向栈顶元素
};

template <typename T>
SeqStack<T>::SeqStack(int length)
{
    m_data = new T[length];
    m_maxsize = length;//最多可以存储
    m_top = -1;//空栈
}

template <typename T>
SeqStack<T>::~SeqStack()
{
    delete [] m_data;
}

//入栈
template <typename T>
bool SeqStack<T>::Push(const T& e)
{
    if(IsFull() == true) {
        cout<<"已经满了"<<endl;
        IncreaseSize();
    }

    m_top++;//栈顶指针向后走
    m_data[m_top] = e;
    return true;
}

template <typename T>
void SeqStack<T>::IncreaseSize()
{
    T *p = m_data;
    m_data = new T[m_maxsize + IncSize];
    for(int i = 0; i <= m_top; ++i) {
        m_data[i] = p[i];
    }
    m_maxsize = m_maxsize + IncSize;
    delete[]p;
}

template <typename T>
bool SeqStack<T>::Pop(T& e)
{
    if(IsEmpty() == true) {
        cout<<"为空，不能出栈"<<endl;
        return false;
    }

    e = m_data[m_top];//返回到e中
    m_top--; 
    return true;
}

template <typename T>
bool SeqStack<T>::GetTop(T& e)
{
    if(IsEmpty() == true) {
        cout<<"为空，不能获取"<<endl;
        return false;
    }

    e = m_data[m_top];//返回到e中
    return true;
}

template <typename T>
void SeqStack<T>::DispList()
{
    if(IsEmpty() == true) {
        cout<<"为空，不能获取"<<endl;
    }

    for(int i = m_top; i >= 0; --i) {
        cout<<m_data[i]<<" ";
    }
    cout<<endl;
}

template <typename T>
int SeqStack<T>::ListLength()
{
   return m_top + 1; 
}

template <typename T>
bool SeqStack<T>::IsEmpty()
{
    if(m_top == -1) {
        return true;
    }
    return false;
}

template <typename T>
bool SeqStack<T>::IsFull()
{
    if(m_top >= m_maxsize - 1) {
        return true;
    }
    return false;
}


/*************************/
int main()
{
    SeqStack<int> seqobj(10);
    seqobj.Push(100);
    seqobj.Push(200);
    seqobj.Push(300);
    seqobj.Push(400);
    seqobj.DispList();

    int eval = 0;
    seqobj.Pop(eval);
    seqobj.Pop(eval);

    seqobj.DispList();

    return 0;
}