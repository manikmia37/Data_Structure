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

/*void Inorder_Traversal(TreeNode *root,string &s)
{
   if(root==NULL)
   {
       return;
   }
   Inorder_Traversal(root->LeftChild,s);
   s+=to_string(root->val)+" ";
   Inorder_Traversal(root->RightChild,s);
}*/

void vertical_order_Traversal(TreeNode *root,int level,map<int,vector<int>>&m)
{
    if(root==NULL)
    {
        return;
    }
    m[level].push_back(root->val);
    vertical_order_Traversal(root->LeftChild,level-1,m);
    vertical_order_Traversal(root->RightChild,level+1,m);
    return;
}

int main()
{
    //optimize();
    TreeNode *root=NULL;
    int a;
    cin>>a;
    root=new TreeNode(a);
    queue<TreeNode*>q;
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
      if(x != -1)
      {
          q.push(n1);
      }
      if(y != -1)
      {
          q.push(n2);
      }
    }
    /*string s;
    Inorder_Traversal(root,s);
    cout<<"Inorder Traversal: "<<s<<endl;*/
    map<int,vector<int>>m;
    vertical_order_Traversal(root,0,m);
    for(auto u:m)
    {
        for(auto v:u.second)
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
input is given in level order traversal
input:
1
2 3
4 5 6 7
-1 -1 -1 -1 -1 8 -1 9
-1 -1 -1 -1
output:
Vertical Order Traversal:
4
2
1 5 6
3 8
7 9
*/
