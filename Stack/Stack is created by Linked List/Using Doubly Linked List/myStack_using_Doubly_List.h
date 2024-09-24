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
    T value;
    Node *Next;
    Node *Prev;
    Node(T val)
    {
        value=val;
        Next=NULL;
        Prev=NULL;
    }
};


template<typename S> class Stack
{
    Node <S> *head;
    Node <S> *top;
    int cnt=0;
public:
    Stack()
    {
        head=NULL;
        top=NULL;
    }

    void push(S val)
    {
        Node <S> *newnode=new Node <S> (val);
        if(head==NULL)
        {
            head=newnode;
            top=newnode;
            cnt++;
            return;
        }
        top->Next=newnode;
        newnode->Prev=top;
        top=newnode;
        cnt++;
    }

    void pop()
    {
        S pop_value;
        if(head==NULL)
        {
            cout<<"The stack is underflow"<<endl;
            return;
        }
        Node <S> *delnode=top;
        pop_value=delnode->value;
        if(head==top)
        {
            head=top=NULL;
            cnt--;
            cout<<"The pop value is: "<<pop_value<<endl;
            return;
        }
        top=delnode->Prev;
        top->Next=NULL;
        delete delnode;
        cnt--;
        cout<<"The pop value is: "<<pop_value<<endl;
    }


    bool isEmpty()
    {
        if(head==NULL) return true;
        else return false;
    }

    void Peek_element()
    {
        bool Empty=isEmpty();
        if(Empty) cout<<"The stack is empty"<<endl;
        else
        {
            cout<<"The top element is: "<<top->value<<endl;
        }
    }

    int Size()
    {
        return cnt;
    }

    void display()
    {
        if(head==NULL)
        {
            cout<<"The stack is empty"<<endl;
            return;
        }
        Node <S> *temp=head;
        cout<<"The stack elements are: ";
        while(temp != NULL)
        {
            cout<<temp->value;
            if(temp->Next!=NULL)
            {
                cout<<" ";
            }
            temp=temp->Next;
        }
    }

    bool isFull(int n)
    {
        if(Size()==n)
        {
            return true;
        }
        else{
            return false;
        }
    }

};

