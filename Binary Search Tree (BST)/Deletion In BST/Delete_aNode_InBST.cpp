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

TreeNode* InorderSuccessor(TreeNode* root)
{
   while(root->LeftChild != NULL)
   {
       root=root->LeftChild;
   }
   return root;
}

TreeNode* Deletion_In_BST(TreeNode *root,int delete_value)
{
    if(delete_value<root->val)
    {
       root->LeftChild=Deletion_In_BST(root->LeftChild,delete_value);
    }
    else if(delete_value>root->val)
    {
       root->RightChild=Deletion_In_BST(root->RightChild,delete_value);
    }
    else{
        if(root->LeftChild==NULL)
        {
            TreeNode *temp=root->RightChild;
            delete(root);
            return temp;
        }
        else if(root->RightChild==NULL)
        {
            TreeNode *temp=root->LeftChild;
            delete(root);
            return temp;
        }
        else{
            TreeNode *temp=InorderSuccessor(root->RightChild);
            root->val=temp->val;
            root->RightChild=Deletion_In_BST(root->RightChild,temp->val);
        }
    }
    return root;
}

void inorderTraversal(TreeNode *root, string &s)
{
    if(root==NULL)
    {
        return;
    }
    inorderTraversal(root->LeftChild,s);
    s+=to_string(root->val)+" ";
    inorderTraversal(root->RightChild,s);
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
    cout<<"Enter The value which you want to delete: ";
    int delete_value;
    cin>>delete_value;

    cout<<"Before Deletion Inorder Traversal: ";
    string s="";
    inorderTraversal(root,s);
    cout<<s<<endl;

    root=Deletion_In_BST(root,delete_value);
    cout<<"After Deletion Inorder Traversal: ";
    s="";
    inorderTraversal(root,s);
    cout<<s<<endl;



    return 0;
}
/*
input:
10
11 5 9 43 34 1 2 7 21 10
9
output:
Before Deletion Inorder Traversal: 1 2 5 7 9 10 11 21 34 43
After Deletion Inorder Traversal: 1 2 5 7 10 11 21 34 43
*/

