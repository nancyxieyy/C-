#pragma once
#include <iostream>
using namespace std;

template <typename T>
class TreeNode
{
public:
	TreeNode(T i, TreeNode<T>* left = NULL, TreeNode<T>* right = NULL);
	~TreeNode();

	T item;
	TreeNode<T>* leftTree, * rightTree;

    bool search(T key);

    int depth();

private:
};

//构造
template <typename T>
TreeNode<T>::TreeNode(T i, TreeNode<T>* left, TreeNode<T>* right)
	: item(i), leftTree(left), rightTree(right)
{
}

//析构
template <typename T>
TreeNode<T>::~TreeNode()
{
	delete leftTree;
	delete rightTree;
}

template <typename T>
bool TreeNode<T>::search(T key)
{
    if(item == key) {
        return true;
    }
    if(leftTree) {
        bool bl = leftTree->search(key);
        return bl;
    }
    if(rightTree) {
        bool br = rightTree->search(key);
        return br;
    }
}

template <typename T>
int TreeNode<T>::depth()
{
    int dl = 0, dr = 0;
    if(leftTree) {
        dl = leftTree->depth();
    }
    if(rightTree) {
        dr = rightTree->depth();
    }
    if(dl > dr) {
        return dl + 1;
    }
    else
        return dr + 1;
}