#include <iostream>
using namespace std;
/*
    尾部插，头部插
*/

template <typename T>
struct QueueNode
{
    T data;//数据域
    QueueNode<T>* next;//指针域
};

template <typename T>
class LinkQueue
{
public:
    LinkQueue();
    ~LinkQueue();

public:
    bool EnQueue(const T& e);//入队
    bool Dequeue(T& e);//出队
    bool GetHead(T& e);//读取队头元素

    void DispList();//显示所有元素
    int ListLenhth();//获取长度
    bool IsEmpty();
private:
    QueueNode<T>* m_front;//头节点
    QueueNode<T>* m_rear;//尾节点
    int m_length;
};

template <typename T>
LinkQueue<T>::LinkQueue()
{
    m_front = new QueueNode<T>;
    m_front->next = NULL;
    m_rear = m_front;
    m_length = 0;
}

template <typename T>
LinkQueue<T>::~LinkQueue()
{
    QueueNode<T>* pnode = m_front->next;
    QueueNode<T>* p_tmp;
    while(pnode != NULL)
    {
        p_tmp = pnode;
        pnode = pnode->next;
        delete p_tmp;
    }
    delete m_front;
}

template <typename T>
bool LinkQueue<T>::EnQueue(const T& e)
{
    QueueNode<T>* node = new QueueNode<T>;
    node->data = e;
    node->next = NULL;

    m_rear->next = node;//更新队尾指针
    m_rear = node;

    m_length++;
    return true;
}
    
template <typename T>
bool LinkQueue<T>::Dequeue(T& e)
{
    if(IsEmpty() == true) {
        cout<<"erro!"<<endl;
        return false;
    }
    QueueNode<T>* p_willdel = m_front->next;
    e = p_willdel->data;
    m_front->next = p_willdel->next;
    if(m_rear == p_willdel) {
        m_front = m_rear;
    }
    delete p_willdel;
    m_length--;
    return true;
}

template <typename T>
bool LinkQueue<T>::GetHead(T& e)
{
    if(IsEmpty() == true) {
        cout<<"error"<<endl;
        return false;
    }
    e = m_front->next->data;
    return true;
}
    
template <typename T>
void LinkQueue<T>::DispList()
{
    QueueNode<T> * p = m_front->next;
    while(p != NULL) {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

template <typename T>
int LinkQueue<T>::ListLenhth()
{
    return m_length;
}

template <typename T>
bool LinkQueue<T>::IsEmpty()
{
    if(m_length == 0 || m_front == m_rear)
    {
        return true;
    }
    return false;
}

int main()
{
    LinkQueue<int> queobj;
    queobj.EnQueue(150);
    queobj.EnQueue(250);
    queobj.EnQueue(350);
    queobj.EnQueue(450);

    int eval = 0;
    queobj.Dequeue(eval);

    queobj.DispList();

    return 0;
}