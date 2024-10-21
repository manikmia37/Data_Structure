#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dl;
#define MOD 1000000007
#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(5); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a,b,sizeof(a));
const int inf = 2000000000;
const ll infLL = 9000000000000000000;

class TreeNode
{
public:
    int data;
    TreeNode* LeftChild;
    TreeNode* RightChild;
    TreeNode(int val)
    {
        data=val;
        LeftChild=NULL;
        RightChild=NULL;
    }
};

void SpacePrint(int level)
{
    for(int i=0; i<level; i++)
    {
        cout<<"   ";
    }
}

void printTree(TreeNode *root, int level)
{
    if(root==NULL)
    {
        return;
    }
    if(root->LeftChild==NULL && root->RightChild==NULL)
    {
        cout<<root->data<<endl;
        return;
    }
    else
    {
        if(level != 0)
        {
            cout<<endl;
            SpacePrint(level);
            cout<<"Root: "<<root->data<<endl;
        }
        else{
            cout<<"Root: "<<root->data<<endl;
        }
    }
    if(root->LeftChild != NULL)
    {
        SpacePrint(level);
        cout<<"Left: ";
        printTree(root->LeftChild,level+1);
    }
    if(root->RightChild != NULL)
    {
        SpacePrint(level);
        cout<<"Right: ";
        printTree(root->RightChild,level+1);
    }
    return;
}

int main()
{
    //optimize();
    int n;
    cin>>n;
    TreeNode *Allnodes[n];
    for(int i=0; i<n; i++)
    {
        Allnodes[i]=new TreeNode(-1);
    }
    for(int i=0; i<n; i++)
    {
        int value,left,right;
        cin>>value>>left>>right;
        if(left>n-1 || right>n-1)
        {
            cout<<"Invalid Index"<<endl;
            break;
        }
        Allnodes[i]->data=value;
        if(left != -1)
        if(left != -1)
        {
            Allnodes[i]->LeftChild=Allnodes[left];
        }
        if(right != -1)
        {
            Allnodes[i]->RightChild=Allnodes[right];
        }
    }

    printTree(Allnodes[0],0); //Preorder Traversal Root Left Right

    return 0;
}
/*
input:
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

output:
According To the asking patter output in Preorder Traversal:
Root: 0
Left:
    Root: 1
    Left: 3
    Right: 4
Right:
     Root: 2
     Left:
         Root: 5
         Left: 7
         Right: 8
     Right: 6
*/

