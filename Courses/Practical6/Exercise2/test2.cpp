#include <iostream>
#include "TreeNode1.h"
using namespace std;

int main()
{
    TreeNode<string> * fri = new TreeNode<string>("Friday");
    TreeNode<string> * sat = new TreeNode<string>("Saturday");
    TreeNode<string> * thur = new TreeNode<string>("Thursday");
    TreeNode<string> * wed = new TreeNode<string>("Wednesday");

    TreeNode<string> * mon = new TreeNode<string>("Monday", fri, sat);
    TreeNode<string> * tue = new TreeNode<string>("Tuesday", thur, wed);

    TreeNode<string> * sun = new TreeNode<string>("Sunday", mon, tue);

    cout << "the day you want to find:" << endl;
    string day;
    cin >> day;
    if(sun != NULL && sun->search(day))
        cout << "Found." << endl;
    else
        cout << "Not found." <<endl;
    
    if(sun != NULL) {
        cout << "The deepth is " << sun->depth() << endl;
    }
    else
        cout << "The deepth is 0" << endl;
    
    delete sun;

    return 0;
}