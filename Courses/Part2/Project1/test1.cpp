#include <iostream>
#include "TreeNode.h"
using namespace std;

//(a)Fix the bug
int alternating_sum(int n) 
{
    int sum = 0;
    if(n == 0) {
        return 0;
    }
    if (n % 2 == 1) 
        sum += n;
    else 
        sum -= n;
    return sum + alternating_sum(n - 1);
}

//(b)print binary tree by pre-order traversal
template<typename T>
void print(TreeNode<T>* tree)
{
    if(tree == NULL) {
        return;
    }
    cout << tree->item << endl;
    print(tree->leftTree);
    print(tree->rightTree);
}

template<typename T>
TreeNode<T>* search(T key, TreeNode<T>* tree)
{
    if (tree == NULL) // key not in tree, insert
        tree = new TreeNode<T>(key);
    else if (key < tree->item)
        tree->leftTree = search(key, tree->leftTree);
    else if (key > tree->item)
        tree->rightTree = search(key, tree->rightTree);
    return tree;
}

int main()
{
    //(a)
    cout << alternating_sum(100) << endl;

    /*(c)(1)rebuild a balanced BST
        212, 111, 20, 150, 531, 412, 718
        20, 111, 150, 212, 412, 531, 718 
    */    
    TreeNode<int>* tree = NULL;
    tree = search(212, tree);
    tree = search(111, tree);
    tree = search(20, tree);
    tree = search(150, tree);
    tree = search(531, tree);
    tree = search(412, tree);
    tree = search(718, tree);

    //(c)(2)
    print(tree);

    //(c)(3)
    cout << "The complexity of the balanced BST is O(log n)" << endl;

    delete tree;

    return 0;
}