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
    TreeNode* LeftChild;
    TreeNode* RightChild;
    TreeNode(int val)
    {
        data=val;
        LeftChild=NULL;
        RightChild=NULL;
    }
};

void printTree_levelorder_Traversal(TreeNode *root,string &s1)
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
}

int main()
{
    //optimize();
    int n;
    cin>>n;
    TreeNode *Allnodes[n];
    for(int i=0; i<n; i++)
    {
        Allnodes[i]=new TreeNode(-1);
    }
    for(int i=0; i<n; i++)
    {
        int value,left,right;
        cin>>value>>left>>right;
        if(left>n-1 || right>n-1)
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

    string LevelOrder_string;
    printTree_levelorder_Traversal(Allnodes[0],LevelOrder_string);
    cout<<"Level Order Traversal: "<<LevelOrder_string<<endl;
    return 0;
}

/*
input:
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

output:
Level order: 0 1 2 3 4 5 6 7 8

*/
