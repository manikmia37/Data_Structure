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
    TreeNode(int value)
    {
        val=value;
        LeftChild=NULL;
        RightChild=NULL;
    }
};


void print_in_Inorder_Taversal(TreeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    print_in_Inorder_Taversal(root->LeftChild);
    cout<<root->val<<" ";
    print_in_Inorder_Taversal(root->RightChild);
    return;
}

int main()
{
    //optimize();
    int a;
    cin>>a;
    TreeNode *root=new TreeNode(a);
    queue<TreeNode *>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode *presentNode=q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        TreeNode *n1=NULL;
        TreeNode *n2=NULL;
        if(x != -1)
        {
            n1=new TreeNode(x);
        }
        if(y != -1)
        {
            n2=new TreeNode(y);
        }
        presentNode->LeftChild=n1;
        presentNode->RightChild=n2;
        if(x != -1) q.push(n1);
        if(y != -1) q.push(n2);
    }
    print_in_Inorder_Taversal(root);
    return 0;
}
/* Input is given in Level order Traversal
input:
0
1 2
3 4 5 6
-1 -1 -1 -1 7 8 -1 -1
-1 -1 -1 -1

output:
Inorder Traversal: 3 1 4 0 7 5 8 2 6
*/

