#include <iostream>
using namespace std;
#define MaxSize 10

template <typename T>
class SeqQueue
{
public:
    SeqQueue();
    ~SeqQueue();
public:
    bool EnQueue(const T& e);//入队
    bool DeQueue(T& e);//出队
    bool GetHead(T& e);//取读队头元素
    void ClearQueue();//清空

    void DispList();//输出队列中的所有元素
    int ListLenth();//长度
    bool IsEmpty();
    bool IsFull();

private:
    T* m_data;//促进方顺序队列中的元素
    int m_front;//队头指针，允许删除的一端，如果队列不为空，则指向队头元素
    int m_rear;//队尾指针，允许插入，如果队列不为空，则指向队列尾元素的下一个位置
};

template <typename T>
SeqQueue<T>::SeqQueue()
{
    m_data = new T[MaxSize];
    //空队列 m_front和m_rear都为0
    m_front = 0;
    m_rear = 0;
}

template <typename T>
SeqQueue<T>::~SeqQueue()
{
    delete []m_data;
}

template <typename T>
bool SeqQueue<T>::EnQueue(const T& e)
{
    if(IsFull() == true) {
        return false;
    }
    m_data[m_rear] = e;//将数据放入队尾巴
    m_rear++;//队尾指针向后走
    return true;
}

template <typename T>
bool SeqQueue<T>::DeQueue(T& e) {
    if(IsEmpty() == true) {
        return false;
    }
    e = m_data[m_front];
    m_front++;
    return true;
}

template <typename T>
bool SeqQueue<T>::GetHead(T& e)
{
    if(IsEmpty() == true) {
        return false;
    }
    e = m_data[m_front];
    return true;
}

template <typename T>
void SeqQueue<T>::ClearQueue()
{
    m_rear = m_front = 0;
}

template <typename T>
void SeqQueue<T>::DispList()
{
    if(IsEmpty() == true) {
        return ;
    }
    for(int i = m_front; i < m_rear; i++)
    {
        cout<<m_data[i]<<" ";
    }
    cout<<endl;
}

template <typename T>
int SeqQueue<T>::ListLenth()
{
    return m_rear - m_front;
}

template <typename T>
bool SeqQueue<T>::IsEmpty()
{
    if(m_front == m_rear) {
        return true;
    }
    return false;
}

template <typename T>
bool SeqQueue<T>::IsFull()
{
    if(m_rear >= MaxSize + 1) {
        return true;
    }
    return false;
}

int main()
{
    SeqQueue<int> seqobj;
    seqobj.EnQueue(10);
    seqobj.EnQueue(20);
    seqobj.EnQueue(30);
    seqobj.EnQueue(40);
    seqobj.DispList();

    int eval = 0;
    seqobj.DeQueue(eval);
    seqobj.DeQueue(eval);
    seqobj.DispList();

    seqobj.GetHead(eval);
    cout<<eval<<endl;
    return 0;
}