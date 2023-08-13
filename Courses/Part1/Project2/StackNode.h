#ifndef STACKNODE_H
#define STACKNODE_H
using namespace std;

template<typename T>
class StackNode
{
public:
	// parameterised constructor
	StackNode(T i, StackNode<T>* pNxtNode);
	// destructor
	~StackNode() {};

	// public members (data & functions)
	T item;
	StackNode<T>* pNextNode;

private:
    
};

// constructor - set the node's item, pNextNode with given item i, pNxtNode
template<typename T>
StackNode<T>::StackNode(T i, StackNode<T>* pNxtNode)
	: item(i), pNextNode(pNxtNode)
{
   
}

#endif //STACKNODE_H