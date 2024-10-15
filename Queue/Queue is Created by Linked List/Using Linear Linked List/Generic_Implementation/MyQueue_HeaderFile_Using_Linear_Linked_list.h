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

template<typename T> class Node
{
public:
    T val;
    Node *Next;
    Node(T val)
    {
        this->val=val;
        Next=NULL;
    }
};

template<typename S> class Queue
{
public:
    Node <S> *Front;
    Node <S> *Rear;
    Queue()
    {
        Front=NULL;
        Rear=NULL;
    }
    void enqueue(S val)
    {
        Node <S> *newnode=new Node <S> (val);
        if(Front==NULL)
        {
            Front=newnode;
            Rear=newnode;
            return;
        }
        Rear->Next=newnode;
        Rear=Rear->Next;
    }
    void pop()
    {
        S chk;
        if(Rear==NULL)
        {
            cout<<"Queue Underflow || The Queue is Empty"<<endl;
            return;
        }
        Node <S> *delnode=Front;
        Front=Front->Next;
        if(Front==NULL)
        {
            Rear=NULL;
        }
        chk=delnode->val;
        delete delnode;
        cout<<"The popped element is: "<<chk<<endl;
        return;
    }

    bool IsEmpty()
    {
        if(Front==NULL && Rear==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void peek() //peek or front value same
    {
        if(IsEmpty())
        {
            cout<<"Queue Underflow"<<endl;
            return;
        }
        cout<<"The Peek Element is: "<<Front->val<<endl;
    }

    void Back() //Rear and back same
    {
        if(IsEmpty())
        {
            cout<<"Queue Underflow"<<endl;
            return;
        }
        cout<<"The Back element is: "<<Rear->val<<endl;
    }

    void display()
    {
        if(Front==NULL)
        {
            cout<<"Queue Underflow || The Queue is empty"<<endl;
            return;
        }
        cout<<"The elements are: ";
        Node <S> *temp=Front;
        while(temp != Rear)
        {
            cout<<temp->val;
            temp=temp->Next;
            if(temp != NULL)
            {
                cout<<"<-";
            }
        }
        cout<<temp->val<<endl;
    }
};

