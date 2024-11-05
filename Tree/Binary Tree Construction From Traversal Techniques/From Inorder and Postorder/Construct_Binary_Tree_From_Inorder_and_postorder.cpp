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
int Postorder[mx];

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


int search_in_Inorder(int current_value,int Start,int End )
{
    for(int i=Start; i<=End; i++)
    {
        if(Inorder[i]==current_value)
        {
            return i;
        }
    }
    return -1;
}

TreeNode* build_TreeFrom_InorderAnd_Postorder(int start,int End, int index)
{
    //static int id=End;
    if(start>End)
    {
        return NULL;
    }
    int current_value=Postorder[index];
    TreeNode *newnode=new TreeNode(current_value);
    /*if(start==End)
    {
        return newnode;
    }*/
    int position=search_in_Inorder(current_value,start,End);

    newnode->RightChild=build_TreeFrom_InorderAnd_Postorder(position+1,End,index-1);
    newnode->LeftChild=build_TreeFrom_InorderAnd_Postorder(start,position-1,index-(End-position)-1);
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
    }
    for(int i=0; i<n; i++)
    {
        cin>>Postorder[i];
    }
    TreeNode *Root=build_TreeFrom_InorderAnd_Postorder(0,n-1,n-1);
    //For checking The tree Try to travers with postorder traversal
    PostOrder_Traversal(Root);
    return 0;
}

/*
input:
8
Inorder: 4 8 2 5 1 6 3 7
Postorder: 8 4 5 2 6 7 3 1

output: 8 4 5 2 6 7 3 1
*/

