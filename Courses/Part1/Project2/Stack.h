#ifndef STACK_H
#define STACK_H
#include "StackNode.h"
#include <iostream>
using namespace std;

template<typename T>
class Stack
{
public:
	Stack();		// parameter-less constructor
	Stack(const Stack<T>& sr);	// copy constructor
	~Stack();		// destructor

	T push(T i);	// push item i onto stack
	T pop();		// pop off top item 
	int size();		// return number of items in stack

	T operator+(T i);	// overload + for push
	T operator-();      // overload - for pop

    T print();

private:
	StackNode<T>* pTos;
	int stackSize;
};

template<typename T>
Stack<T>::Stack()
{
	pTos = NULL;
	stackSize = 0;
}

template<typename T>
Stack<T>::Stack(const Stack<T>& sr)
{
	// push sr content into a temp stack in LIFO
	Stack<T>* s_temp = new Stack;
	StackNode<T>* psrTos = sr.pTos;
	while (psrTos != NULL) {
		s_temp->push(psrTos->item);
		psrTos = psrTos->pNextNode;
	}

	// push temp stack content into THIS stack in LIFO
	while (s_temp->pTos)
		push(s_temp->pop());
	delete s_temp;
}

template<typename T>
Stack<T>::~Stack()
{
	while (pTos) {
		StackNode<T>* pNewTos = pTos->pNextNode;
		delete pTos;
		pTos = pNewTos;
	}
}

template<typename T>
T Stack<T>::push(T i)
{
	StackNode<T>* pNewTos = new StackNode<T>(i, pTos);
	pTos = pNewTos;
	stackSize++;
	return i;
}

template<typename T>
T Stack<T>::pop()
{
	if (pTos) {
		T item = pTos->item;
		StackNode<T>* pNewTos = pTos->pNextNode;
		delete pTos;
		pTos = pNewTos;
		stackSize--;
		return item;
	}
	exit(0);
}

template<typename T>
int Stack<T>::size()
{
	return stackSize;
}

template<typename T>
T Stack<T>::operator+(T i)
{
	return push(i);
}

template<typename T>
T Stack<T>::operator-()
{
	return pop();
}

template<typename T>
T Stack<T>::print()
{
	StackNode<T> *p = pTos;
    while(p != NULL) {
        cout<<p->item<<" ";
        p = p->pNextNode;
    }
    cout<<endl;
}

#endif //STACK_H