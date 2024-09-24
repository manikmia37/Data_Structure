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

class Node
{
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
    if(startNode==NULL)
    {
        if(cnt==1)
        {
            cout<<"It is impossible to create cycle as there is only one element in the List"<<endl;
        }
        else if(cnt==k)
        {
           cout<<"Your given position indicate the last element "<<endl;
           cout<<"If it is connected with first element it will be circular list but not circle"<<endl;
        }
        return;
    }
    temp->Next=startNode;
}

bool detect_cycle(Node *&head)
{
    if(head==NULL)
    {
        return 0;
    }
    Node *fast=head;
    Node *slow=head;
    while(fast != NULL && fast->Next != NULL)
    {
        fast=fast->Next->Next;
        slow=slow->Next;
        if(fast==slow)
        {
            return 1;
        }
    }
    return 0;
}

void remove_cycle(Node *&head)
{
    if(head==NULL)
    {
        cout<<"The List is empty"<<endl;
        return;
    }
    bool cycle=detect_cycle(head);
    if(!cycle) cout<<"There is no cycle in List"<<endl;
    else
    {
        cout<<"Yes, There was cycle and The cycle is removed"<<endl;
        Node *fast=head;
        fast=fast->Next->Next;
        Node *slow=head;
        slow=slow->Next;
        while(fast != slow)
        {
            fast=fast->Next->Next;
            slow=slow->Next;
        }
        fast=head;
        while(fast->Next != slow->Next)
        {
            fast=fast->Next;
            slow=slow->Next;
        }
        slow->Next=NULL;
    }
}

int main()
{
    //optimize();
    Node *head=NULL;

    cout<<"Choose 1: Insertion at Tail"<<endl;
    cout<<"Choose 2: Making Cycle At K th position"<<endl;
    cout<<"Choose 3: Display The Linked List"<<endl;
    cout<<"Choose 4: Cycle Detection"<<endl;
    cout<<"Choose 5: Remove Cycle"<<endl;
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
            break;
        case 4:
            bool cycle;
            cycle=detect_cycle(head);
            if(!cycle)
            {
                cout<<"No Cycle"<<endl;
            }
            else
            {
                cout<<"Yes, Cycle"<<endl;
            }
            break;
        case 5:
            remove_cycle(head);
            break;
        default:
            break;
        }
        cout<<"Choose The Option from Option menu: ";
        cin>>choose;
    }
    return 0;
}




