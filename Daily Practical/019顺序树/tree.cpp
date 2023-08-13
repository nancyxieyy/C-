#include<iostream>
using namespace std;
#define MaxSize 100 //数组的尺寸
#include<math.h>

enum BCCHILDSIGN    //节点标记
{
    E_Root, //树根
    E_ChildLeft,    //左孩子
    E_ChildRIght,   //右孩子
};

//树中每个节点的定义
template <typename T> //T代表数据元素类型
struct BinaryTreeNode
{
    T data; //数据域，存放数元素
    bool isValid;   //该节点是否有效以应对非完全二叉树
};

//二叉树的定义
template <typename T>
class BinaryTree
{
public:
    BinaryTree()    //构造函数
    {
        for(int i = 0; i <= MaxSize; ++i) {
            SqBiTree[i].isValid = false;    //开始时节点无效，没有保存任何数据
        }
    }

    ~BinaryTree() {}   //析构函数

public:
    //创建一个树节点
    int CreateNode(int parindex, BCCHILDSIGN pointSign, const T& e);

    //获取父节点的下标
    int getParentIdx(int sonindex) {
        //位置不合理
        if(ifValidRangeIdx(sonindex) == false) {
            return -1;
        }
        //不是个合理的节点，不要尝试找父节点
        if(SqBiTree[sonindex].isValid == false) {
            return -1;
        }
        return int(sonindex / 2);   //i的父节点时i/2
    }

    //获取某个节点所在的高度
    //根据二叉树的性质5:具有n(n>0)个节点的完全二叉树的高度log(n+1)向上取整，log(n)向下取整 + 1.都是以2为底
    int getPointLevel(int index) {
        //位置不合理
        if(ifValidRangeIdx(index) == false) {
            return -1;
        }
        //不是个合理的节点，不要尝试找父节点
        if(SqBiTree[index].isValid == false) {
            return -1;
        }
        //采用公式计算，log(n)向下取整 + 1
        int level = int(log(index) / log (2) + 1);//log中以e为底，先换底
        return level;
    }

    //获取二叉树的深度
    int getLevel()
    {
        //没根
        if(SqBiTree[1].isValid == false) {
            return 0;
        }
        int i;
        for(i = MaxSize; i >= 1; --i) {
            //找到最后一个有效节点
            if(SqBiTree[i].isValid == true) {
                break;
            }
            return getPointLevel(i);
        }
    }

    //判断是否是个完全二叉树
    bool ifCompleteBT() {
        //没根
        if(SqBiTree[1].isValid == false) {
            return false;
        }
        int i;
        for(i = MaxSize; i >= 1; --i) {
            //找到最后一个有效节点
            if(SqBiTree[i].isValid == true) {
                break;
            }
        }
        for(int k = 1; k <= i; ++k) {
            if(SqBiTree[k].isValid == true) {
                return false;
            }
        }
        return true;
    }

    //前序遍历
    void preOrder() {
        //没根
        if(SqBiTree[1].isValid == false) {
            return;
        }
        preOrder(1);//根节点的数组下标事1，所有这里把根的下标传递下去
    }

    void preOrder(int index) {
        //位置不合理
        if(ifValidRangeIdx(index) == false) {
            return;
        }
        //不是个合理的节点，不要尝试找父节点
        if(SqBiTree[index].isValid == false) {
            return;
        }
        //根左右顺序
        cout << (char)SqBiTree[index].data << " ";
        //输出节点数据的值
        preOrder(2 * index);//左
        preOrder(2 * index + 1);//右
    }

private:
    bool ifValidRangeIdx(int index) //是否是一个有效的数组下标值
    {
        //位置是否合理
        if(index < 1 || index > MaxSize) {
            return false;
        }

        return true;
    }

private:
    BinaryTreeNode<T> SqBiTree[MaxSize + 1];    //存储二叉树节点的数组，为了写程序方便，下标为0的数组不使用
};

//创建一个树节点
template<class T>
//参数1:父节点所在的数组下标；参数2:标记所创建的树根，左右；参数3:插入的数据节点的元素值
int BinaryTree<T>::CreateNode(int parindex, BCCHILDSIGN pointSign, const T& e) {
    //非根节点，要求parindex一定是个合理值
    if(pointSign != E_Root) {
        if(ifValidRangeIdx(parindex) == false) {
            return -1;
        }
        if(SqBiTree[parindex].isValid == false) {
            return -1;
        }
    }
    int index = -1;
    if(pointSign == E_Root) {
        index = 1;
    }
    else if(pointSign == E_ChildLeft) {
        index = 2 * parindex;
        if(ifValidRangeIdx(index) == false) {
            return -1;
        }
    }
    else {
        index = 2 * parindex + 1;
        if(ifValidRangeIdx(index) == false) {
            return -1;
        }
    }
    SqBiTree[index].data = e;
    SqBiTree[index].isValid = true; //标记下标中有有效数据
}

int main()
{
    enum BCCHILDSIGN; 
    int indexRoot = CreateNode(-1, E_Root, 'A'); //创建树根节点
    int indexNodeB = CreateNode(indexRoot, E_ChildLeft, 'B'); //创建左节点
    int indexNodeC = CreateNode(indexRoot, E_ChildRight, 'C'); //创建右节点
    int indexNodeD = CreateNode(indexNodeB, E_ChildLeft, 'D'); //创建左节点
    int indexNodeE = CreateNode(indexNodeC, E_ChildRight, 'E'); //创建右节点

    int iParentIndexE = getParentIdx(indexNodeE);
    cout << "节点E的父节点的下标是：" << indexNodeE << endl;

    return 0;
}