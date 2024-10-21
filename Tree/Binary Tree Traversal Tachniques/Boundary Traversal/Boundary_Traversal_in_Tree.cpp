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


void Print_LeftBoundary_NonLeaves(TreeNode *root)
{
  if(root==NULL)
  {
      return;
  }
  if(root->LeftChild != NULL)
  {
      cout<<root->data<<" ";
      Print_LeftBoundary_NonLeaves(root->LeftChild);
  }
  else if(root->RightChild != NULL)
  {
      cout<<root->data<<" ";
      Print_LeftBoundary_NonLeaves(root->RightChild);
  }
  return;
}

void Print_leaves(TreeNode *root)
{
   if(root==NULL)
   {
       return;
   }
   if(root->LeftChild==NULL && root->RightChild==NULL)
   {
       cout<<root->data<<" ";
       return;
   }
   Print_leaves(root->LeftChild);
   Print_leaves(root->RightChild);
   return;
}

void Print_RightBoundary_NonLeaves(TreeNode *root)
{
  if(root==NULL)
  {
      return;
  }
  if(root->RightChild==NULL && root->LeftChild==NULL)
  {
      return;
  }
  Print_RightBoundary_NonLeaves(root->RightChild);
  cout<<root->data<<" ";
  return;
}

void Boundary_Traversal(TreeNode *root)
{
   if(root==NULL) return;
   cout<<root->data<<" ";
   Print_LeftBoundary_NonLeaves(root->LeftChild);
   Print_leaves(root->LeftChild);
   Print_leaves(root->RightChild);
   Print_RightBoundary_NonLeaves(root->RightChild);
   return;
}

/*void printTree_levelorder_Traversal(TreeNode *root,string &s1)
{
    if(root==NULL)
    {
        return;
    }
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
         TreeNode *checkNode=q.front();
         q.pop();
         if(checkNode != NULL)
         {
             s1+=to_string(checkNode->data)+" ";
             if(checkNode->LeftChild != NULL)
             {
                 q.push(checkNode->LeftChild);
             }
             if(checkNode->RightChild != NULL)
             {
                 q.push(checkNode->RightChild);
             }
         }
         else{
            if(!q.empty())
            {
                q.push(NULL);
            }
         }
    }
}*/

int main()
{
    //optimize();
    int n;
    cin>>n;
    TreeNode *Allnodes[n+1];
    for(int i=1; i<=n; i++)
    {
        Allnodes[i]=new TreeNode(-1);
    }
    for(int i=1; i<=n; i++)
    {
        int value,left,right;
        cin>>value>>left>>right;
        if(left>n || right>n)
        {
            cout<<"Invalid Index"<<endl;
            break;
        }
        Allnodes[i]->data=value;
        if(left != -1)
        {
            Allnodes[i]->LeftChild=Allnodes[left];
        }
        if(right != -1)
        {
            Allnodes[i]->RightChild=Allnodes[right];
        }
    }
    Boundary_Traversal(Allnodes[1]);
    /*cout<<endl;
    string LevelOrder_string;
    printTree_levelorder_Traversal(Allnodes[1],LevelOrder_string);
    cout<<"Level Order Traversal: "<<LevelOrder_string<<endl;*/

    return 0;
}

/*
input-1: // Edit this code before using this input-1
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1
output-1:
Boundary Traversal: 0 1 3 4 7 8 6 2

input-2:
10
1 2 3
2 4 5
3 6 7
4 -1 -1
5 8 9
6 10 -1
7 -1 -1
8 -1 -1
9 -1 -1
10 -1 -1
output-2:
Boundary Traversal: 1 2 4 8 9 10 7 3

input-3:
13
1 2 3
2 4 5
3 -1 6
4 7 -1
5 8 9
6 -1 10
7 -1 11
8 -1 -1
9 -1 -1
10 12 -1
11 -1 13
12 -1 -1
13 -1 -1
output-3: 1 2 4 7 11 13 8 9 12 10 6 3

*/
