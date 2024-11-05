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
    TreeNode(int val)
    {
        this->val=val;
        LeftChild=NULL;
        RightChild=NULL;
    }
};

TreeNode* insertionBST(TreeNode *root, int value)
{
    if(root==NULL)
    {
       TreeNode *newnode=new TreeNode(value);
       root=newnode;
       return root;
    }
    if(value<root->val)
    {
       root->LeftChild=insertionBST(root->LeftChild,value);
    }
    if(value>root->val)
    {
       root->RightChild=insertionBST(root->RightChild,value);
    }
    return root;
}

void Inorder_Traversal(TreeNode *root, string &S)
{
   if(root==NULL)
   {
       return;
   }
   Inorder_Traversal(root->LeftChild,S);
   S+=to_string(root->val)+" ";
   Inorder_Traversal(root->RightChild,S);
   return;
}
int main()
{
    //optimize();
    TreeNode *root=NULL;
    cout<<"Enter How many Node do you want to give: ";
    int n;
    cin>>n;
    cout<<"Enter the value:"<<endl;
    for(int i=0; i<n; i++)
    {
        int value;
        cin>>value;
        root=insertionBST(root,value);
    }
    //How can will we understand that the BST is created successfully? Answer: Inorder Treversal
    //If we traverse the tree via inorder traversal there will create a sorted sequence of nodes.
    string s="";
    Inorder_Traversal(root,s);
    cout<<"Inorder Traversal Of Binary Search Tree (BST): "<<s<<endl;
    return 0;
}
/*
input:
9
11 5 9 43 34 1 2 7 21
output: 1 2 5 7 9 11 21 34 43
*/

