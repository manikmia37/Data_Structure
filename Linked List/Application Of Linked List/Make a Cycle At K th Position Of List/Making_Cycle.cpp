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

class Node{
public:
    int value;
    Node *Next;
    Node(int val)
    {
        value=val;
        Next=NULL;
    }
};


void insertAtTail(Node *&Head, int val)
{
    Node *newnode= new Node(val);
    if(Head==NULL)
    {
        Head=newnode;
        return;
    }
    Node *temp=Head;
    while(temp->Next != NULL)
    {
        temp=temp->Next;
    }
    temp->Next=newnode;
    return;
}


void display(Node* &n)
{
    if(n==NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    Node *temp=n;
    while(temp != NULL)
    {
        cout<<temp->value;
        if(temp->Next != NULL) cout<<"->";
        temp=temp->Next;
    }
    cout<<endl;
}

void  make_cycle(Node *&head, int k)
{
   if(head==NULL)
   {
       cout<<"The List is Empty"<<endl;
       return;
   }
   Node *temp=head;
   Node *startNode=NULL;
   int cnt=1;
   while(temp->Next != NULL)
   {
       if(cnt == k)
       {
           startNode=temp;
       }
       temp=temp->Next;
       cnt++;
   }
   if(startNode==NULL || startNode==temp)
   {
       cout<<"It is impossible to create cycle in the List"<<endl;
       return;
   }
   temp->Next=startNode;
}

int main()
{
    //optimize();
    Node *head=NULL;

    cout<<"Choose 1: Insertion at Tail"<<endl;
    cout<<"Choose 2: Making Cycle At K th position"<<endl;
    cout<<"Choose 3: Display The Linked List"<<endl;
    cout<<"Choose 0: to Exit"<<endl;
    cout<<"Choose The Option from Option menu: ";
    int choose;
    cin>>choose;
    int value;
    while(choose)
    {
        switch(choose)
        {
        case 1:
            cout<<"Enter The Value: ";
            cin>>value;
            insertAtTail(head,value);
            break;
        case 2:
            int k;
            cout<<"Enter The Position where You want to make cycle: ";
            cin>>k;
            make_cycle(head,k);
            break;
        case 3:
            display(head);
        default:
            break;
        }
        cout<<"Choose The Option from Option menu: ";
        cin>>choose;
    }
    return 0;
}



