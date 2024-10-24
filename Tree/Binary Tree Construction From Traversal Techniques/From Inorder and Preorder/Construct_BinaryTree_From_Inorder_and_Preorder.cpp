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
int Inorder[mx];
int Preorder[mx];

class TreeNode
{
public:
    int data;
    TreeNode *LeftChild;
    TreeNode *RightChild;
    TreeNode(int val)
    {
        data=val;
        LeftChild=NULL;
        RightChild=NULL;
    }
};

int search_in_Inorder(int current_value,int start, int End)
{
    for(int i=start; i<=End; i++)
    {
        if(Inorder[i]==current_value)
        {
            return i;
        }
    }
    return -1;
}

TreeNode* build_TreeFrom_InorderAnd_Preorder(int start,int End)
{
    static int id=0;
    int current_value=Preorder[id];
    id=id+1;
    TreeNode *newnode=new TreeNode(current_value);
    if(start==End)
    {
        return newnode;
    }
    int position=search_in_Inorder(current_value,start,End);
    if(position<0)
    {
        return NULL;
    }
    newnode->LeftChild=build_TreeFrom_InorderAnd_Preorder(start,position-1);
    newnode->RightChild=build_TreeFrom_InorderAnd_Preorder(position+1,End);
    return newnode;
}

void PostOrder_Traversal(TreeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->LeftChild != NULL) PostOrder_Traversal(root->LeftChild);
    if(root->RightChild != NULL) PostOrder_Traversal(root->RightChild);
    cout<<root->data<<" ";
    return;
}
int main()
{
    //optimize();
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>Inorder[i];
        //cout<<Inorder[i]<<" ";
    }

    for(int i=0; i<n; i++)
    {
        cin>>Preorder[i];
        //cout<<Preorder[i]<<" ";
    }
    TreeNode *Root=build_TreeFrom_InorderAnd_Preorder(0,n-1);
    //For checking The tree Try to travers with postorder traversal
    PostOrder_Traversal(Root);
    return 0;
}

/*
input:
9
Inorder: 3 1 4 0 7 5 8 2 6
Preorder: 0 1 3 4 2 5 7 8 6
output:
Postorder: 3 4 1 7 8 5 6 2 0
*/

