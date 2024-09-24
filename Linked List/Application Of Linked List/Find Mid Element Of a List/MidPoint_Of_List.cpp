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

int Find_Mid_Element(Node *&head)
{
   if(head==NULL)
   {
       return -1;
   }
   Node *fast=head;
   Node *slow=head;
   while(fast != NULL && fast->Next!= NULL)
   {
       fast=fast->Next->Next;
       slow=slow->Next;
   }
   return slow->value;
}

int main()
{
    //optimize();
    Node *head=NULL;

    cout<<"Choose 1: Insertion at Tail"<<endl;
    cout<<"Choose 2: Find out the mid element of the List"<<endl;
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
            int mid_element;
            mid_element=Find_Mid_Element(head);
            if(mid_element== -1) cout<<"The list is empty"<<endl;
            else cout<<"The mid element is: "<<mid_element<<endl;
            break;
        default:
            break;
        }
        cout<<"Choose The Option from Option menu: ";
        cin>>choose;
    }

    return 0;
}


