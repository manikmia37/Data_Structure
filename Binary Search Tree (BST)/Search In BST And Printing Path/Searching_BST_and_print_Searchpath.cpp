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

bool ans=false;
void Search_In_BST(TreeNode *root, int value,vector<int>&v)
{
   if(root != NULL) v.push_back(root->val);
   if(root->val==value)
   {
      ans=true;
      return;
   }
   if(value<root->val)
   {
       if(root->LeftChild != NULL)
       {
           Search_In_BST(root->LeftChild,value,v);
       }
   }
   if(value>root->val)
   {
       if(root->RightChild != NULL)
       {
           Search_In_BST(root->RightChild,value,v);
       }
   }
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

    cout<<"Enter The value which You want to search: ";
    int value;
    cin>>value;
    vector<int>v;
    Search_In_BST(root,value,v);
    if(ans)
    {
      cout<<"The Searching Value is found and Searching Path is: ";
      int Size=v.size();
      for(int i=0; i<Size; i++)
      {
          cout<<v[i];
          if(i != Size-1)
          {
              cout<<"->";
          }
      }
    }
    else{
        cout<<"The searching Value is not found"<<endl;
    }
    return 0;
}
/*
input:
9
11 5 9 43 34 1 2 7 21
7
output: The Searching Value is found and Searching Path is: 11->5->9->7
*/

