#pragma once
#include <iostream>
using namespace std;
#ifndef TREENODE_H
#define TREENODE_H

template <typename T>
class TreeNode
{
public:
	TreeNode(T i, TreeNode<T>* left = NULL, TreeNode<T>* right = NULL);
	~TreeNode();

	T item;
	TreeNode<T>* leftTree, * rightTree;

    TreeNode<T>* search(T key, TreeNode<T>* Tree);

    TreeNode<T>* bst();

    int sigma(TreeNode<int>* tree);

    int maxnum(TreeNode<int>* tree);
    

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

#endif //TREENODE_H

