#include<iostream>
using namespace std;

//namespace _nmspl{

//节点标记
enum ECCHILDSIGN
{
    E_Root,
    E_ChildLeft,
    E_ChildRight,
};

//树中每个节点的定义
template <typename T>
struct BinaryTreeNode
{
    T data;//数据域，存放数据元素
    BinaryTreeNode *leftChild;//左子节点指针
    BinaryTreeNode *rightChild;//右子节点指针
};

//二叉树的定义
template <typename T>
class BinaryTree
{
public:
    //构造函数
    BinaryTree();
    //析构函数
    ~BinaryTree();

public:
    //创建一个树节点
    BinaryTreeNode<T> * CreateNode(BinaryTreeNode<T> *parentnode, ECCHILDSIGN pointSign, const T& e);
    
    //释放树节点
    void ReleaseNode(BinaryTreeNode<T> *pnode);
    
    //利用扩展二叉树的前序遍历序列来创建一棵二叉树
    void CreateBTreeAccordPT(char *pstr);

private:
    BinaryTreeNode<T> * root;//树根节点

    //利用扩展二叉树的前序遍历序列来创建二叉树的递归函数
    void CreateBTreeAccordPTRecu(BinaryTreeNode<T> * &tnode, char * &pstr);//参数类型为引用，确保递归调用中对参数的改变会影响调用者
};

//构造函数
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root == nullptr;
}

//析构函数
template <typename T>
BinaryTree<T>::~BinaryTree()
{
    ReleaseNode(root);
}

//释放树节点
template <typename T>
void BinaryTree<T>::ReleaseNode(BinaryTreeNode<T> *pnode)
{
    if(pnode != nullptr) {
        ReleaseNode(pnode->leftChild);
        ReleaseNode(pnode->rightChild);
    }
    delete pnode;
}

//创建一个树节点
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::CreateNode(BinaryTreeNode<T> *parentnode, ECCHILDSIGN pointSign, const T& e)
{
    //新节点创建出来
    BinaryTreeNode<T>* tmpnode = new BinaryTreeNode<T>;
    tmpnode->data = e;
    tmpnode->leftChild = nullptr;
    tmpnode->rightChild = nullptr;

    //把新节点放入正确的位置
    if(pointSign == E_Root) {
        //创建的是根节点
        root = tmpnode;
    }
    if(pointSign == E_ChildLeft) {
        //创建的左孩子节点
        parentnode->leftChild = tmpnode;
    }

    if(pointSign == E_ChildRight) {
        //创建的右孩子节点
        parentnode->rightChild = tmpnode;
    }
    return tmpnode;
}

//利用扩展二叉树的前序遍历序列来创建一棵二叉树
template <typename T>
void BinaryTree<T>::CreateBTreeAccordPT(char *pstr)
{
    CreateBTreeAccordPTRecu(root, pstr);
}


//利用扩展二叉树的前序遍历序列来创建二叉树的递归函数
template <typename T>
void BinaryTree<T>::CreateBTreeAccordPTRecu(BinaryTreeNode<T> * &tnode, char * &pstr)
{
    if(*pstr == '#') {
        tnode = nullptr;
    }
    else {
        tnode = BinaryTreeNode<T>;//创建根节点
        tnode->data = *pstr;

        CreateBTreeAccordPTRecu(tnode->leftChild, ++pstr);
        CreateBTreeAccordPTRecu(tnode->rightChild, ++pstr);
    }
}
//}


int main()
{
    //_nmspl::BinaryTree<int>
    
    //创建一个二叉树
    BinaryTreeNode<int> * rootpoint = CreateNode(nullptr, E_Root, 'A');
    BinaryTreeNode<int> * subpointB = CreateNode(rootpoint, E_ChildLeft, 'B');//A的左子节点
    BinaryTreeNode<int> * subpointD = CreateNode(subpointB, E_ChildLeft, 'D');//B的左子节点

    BinaryTreeNode<int> * subpointC = CreateNode(rootpoint, E_ChildRight, 'C');//A的右子节点
    BinaryTreeNode<int> * subpointE = CreateNode(subpointC, E_ChildRight, 'E');//C的左子节点

    //前序遍历序列ABCD###C#E##(能唯一确定一个二叉树)
    CreateBTreeAccordPT((char*)"ABD###C#E##");

    return 0;
}