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

const int mx=101;
int Stack[mx];
int top = -1;


void push(int value, int n)
{
    if(top < n-1)
    {
        top++;
        Stack[top]=value;
    }
    else
    {
        cout<<"Stack Overflow"<<endl;
    }
}

void pop()
{
    if(top <= -1)
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        cout<<"The popped element is: "<<Stack[top]<<endl;
        top--;
    }
}

void display()
{
    if(top>=0)
    {
        cout<<"The stack elements are: ";
        for(int i=top; i>=0; i--)
        {
            cout<<Stack[i];
            if(i>0)
            {
                cout<<" ";
            }
        }
    }
    else
    {
        cout<<"The stack is empty";
    }
    cout<<endl;
}

void top_element()
{
    if(top <= -1)
    {
        cout<<"The Stack is Empty"<<endl;
        return;
    }
    cout<<"The top element is: "<<Stack[top]<<endl;
}

int find_size()
{
    int point=top;
    if(point <= -1)
    {
        return 0;
    }
    int cnt=0;
    while(point != -1)
    {
        cnt++;
        point--;
    }
    return cnt;
}

bool isFull(int n)
{
   if(top==n-1)
   {
       return true;
   }
   else return false;
}


bool isEmpty()
{
    if(top <= -1)
    {
        return true;
    }
    else return false;
}

int main()
{
    //optimize();

    cout<<"Enter The Capacity of The using Array: ";
    int n;
    cin>>n;

    cout<<"Choose 1: Push into Stack"<<endl;
    cout<<"Choose 2: Pop from Stack"<<endl;
    cout<<"Choose 3: Display stack elements"<<endl;
    cout<<"Choose 4: Display top or peek element"<<endl;
    cout<<"Choose 5: Size of Stack in a Certain time"<<endl;
    cout<<"Choose 6: Check The stack is either full or not"<<endl;
    cout<<"Choose 7: Check The stack is either Empty or not"<<endl;
    cout<<"Choose 0: To Exit"<<endl;

    cout<<"Choose the option from The option menu: ";
    int choose;
    cin>>choose;
    int value;
    while(choose)
    {
        switch(choose)
        {
        case 1:
            cout<<"Enter The value which you want to push in stack: ";
            cin>>value;
            push(value,n);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            top_element();
            break;
        case 5:
            int Size;
            Size=find_size();
            if(!Size) cout<<"The Stack is empty"<<endl;
            else cout<<"The size of stack is: "<<Size<<endl;
            break;
        case 6:
            bool full;
            full=isFull(n);
            if(full) cout<<"The stack is full"<<endl;
            else cout<<"The stack is not full"<<endl;
            break;
        case 7:
            bool Empty;
            Empty=isEmpty();
            if(Empty) cout<<"The stack is empty"<<endl;
            else cout<<"The stack is not empty"<<endl;
            break;
        default:
            break;
        }
        cout<<"Choose the option from The option menu: ";
        cin>>choose;
    }

    return 0;
}



