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

const int mx=101;
int arr[mx];

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

TreeNode* Make_Height_Balanced_BST(int arr[], int left, int right)
{
    if(left>right)
    {
        return NULL;
    }
    int mid=left+(right-left)/2;
    TreeNode *newnode=new TreeNode(arr[mid]);
    newnode->LeftChild=Make_Height_Balanced_BST(arr,left,mid-1);
    newnode->RightChild=Make_Height_Balanced_BST(arr,mid+1,right);
    return newnode;
}


void InOrder_Traversal(TreeNode *root)
{
   if(root==NULL)
   {
       return;
   }
   InOrder_Traversal(root->LeftChild);
   cout<<root->val<<" ";
   InOrder_Traversal(root->RightChild);
   return;
}

int main()
{
    //optimize();
    TreeNode *root=NULL;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    root=Make_Height_Balanced_BST(arr,0,n-1);

    InOrder_Traversal(root);
    return 0;
}

/*
input
7
1 2 3 4 5 6 7
output: 1 2 3 4 5 6 7
*/

