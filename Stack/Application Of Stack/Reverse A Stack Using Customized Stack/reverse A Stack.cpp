#include<bits/stdc++.h>
#include "myStack_using_Doubly_List.h"
using namespace std;

Stack<int>ST;

void insertAtbotom(Stack<int>&sk, int element)
{
    if(sk.isEmpty())
    {
       sk.push(element);
       return;
    }
    int top_element=sk.Peek_element();
    sk.pop();
    insertAtbotom(sk,element);
    sk.push(top_element);
    return;
}

void reverseStack(Stack<int> &chk)
{
    if(chk.isEmpty())
    {
        return;
    }
    int top_element=chk.Peek_element();
    chk.pop();
    reverseStack(chk);
    insertAtbotom(chk,top_element);
    return;
}
int main()
{
    //optimize();
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int element;
        cin>>element;
        ST.push(element);
    }
    reverseStack(ST);
    while(!ST.isEmpty())
    {
        cout<<ST.Peek_element()<<" ";
        ST.pop();
    }
    return 0;
}


