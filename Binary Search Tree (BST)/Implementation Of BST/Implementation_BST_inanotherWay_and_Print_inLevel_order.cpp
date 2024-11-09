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
    int val;
    TreeNode *LeftChild;
    TreeNode *RightChild;
    TreeNode(int data)
    {
        val=data;
        LeftChild=NULL;
        RightChild=NULL;
    }
};

void insert_In_BST(TreeNode *&root,int value)
{
    if(root==NULL)
    {
        TreeNode *newnode = new TreeNode(value);
        root=newnode;
        return;
    }
    if(value<root->val)
    {
        insert_In_BST(root->LeftChild,value);
    }
    else if(value>root->val)
    {
        insert_In_BST(root->RightChild,value);
    }
    return;
}


void Level_Order_Traversal(TreeNode *root)
{
    queue<TreeNode *>q;
    if(root==NULL) cout<<"Does not exist Tree"<<endl;
    q.push(root);
    while(!q.empty())
    {
        TreeNode *Current_Node=q.front();
        q.pop();
        cout<<Current_Node->val<<" ";
        if(Current_Node->LeftChild != NULL)
        {
           q.push(Current_Node->LeftChild);
        }
        if(Current_Node->RightChild != NULL)
        {
            q.push(Current_Node->RightChild);
        }
    }
}

int main()
{
    //optimize();
    TreeNode *root=NULL;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int value;
        cin>>value;
        insert_In_BST(root,value);
    }
    Level_Order_Traversal(root);
    return 0;
}

/*
input
9
11 5 9 43 34 1 2 7 21
output: 11 5 43 1 9 34 2 7 21
*/
