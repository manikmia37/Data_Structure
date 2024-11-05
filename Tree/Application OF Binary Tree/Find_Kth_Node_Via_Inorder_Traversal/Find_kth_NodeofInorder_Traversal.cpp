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

int cnt=1;

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

int Find_kth_node_OF_inorder_Traversal(TreeNode *root, int k)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->LeftChild != NULL) Find_kth_node_OF_inorder_Traversal(root->LeftChild,k);
    if(k==cnt)
    {
        cout<<root->data;
        return 0;
    }

    if(root->RightChild != NULL) Find_kth_node_OF_inorder_Traversal(root->RightChild,k);
    cnt++;
    return 0;
}


int main()
{
    //optimize();
    int n,k;
    cin>>n>>k;
    TreeNode *Allnodes[n+1];
    for(int i=1; i<=n; i++)
    {
        Allnodes[i]=new TreeNode(-1);
    }
    for(int i=1; i<=n; i++)
    {
        int node,left,right;
        cin>>node>>left>>right;
        Allnodes[i]->data=node;
        if(left != -1)Allnodes[i]->LeftChild=Allnodes[left];
        if(right != -1) Allnodes[i]->RightChild=Allnodes[right];
    }
    Find_kth_node_OF_inorder_Traversal(Allnodes[1],k);
    return 0;
}

/*
input:
5 4
1 2 3
2 4 5
3 -1 -1
4 -1 -1
5 -1 -1
*/
