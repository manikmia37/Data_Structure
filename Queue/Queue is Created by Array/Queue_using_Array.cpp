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
int Queue[mx];

int Front= -1;
int Rear= -1;


void enqueue(int val, int n)
{
  if(Front == -1)
  {
      Front++;
      Rear++;
      Queue[Front]=val;
      return;
  }
  if(Rear<n-1)
  {
      Rear++;
      Queue[Rear]=val;
  }
  else{
    cout<<"Queue Overflow"<<endl;
  }

}

bool isEmpty()
{
   if(Front== -1 && Rear== -1)
   {
       return true;
   }
   else{
       return false;
   }
}

void Dequeue()
{
    if(isEmpty())
    {
       cout<<"Queue Underflow"<<endl;
       return;
    }
    cout<<"The Popped element is: "<<Queue[Front]<<endl;
    Front++;
    if(Front>Rear)
    {
        Front= -1;
        Rear= -1;
    }
}

void Front_element()
{
   if(isEmpty())
   {
       cout<<"Queue Underflow"<<endl;
   }
   else{
    cout<<"The Front or Peek element is: "<<Queue[Front]<<endl;
   }
}

void Back_element()
{
   if(isEmpty())
   {
       cout<<"Queue Underflow"<<endl;
   }
   else{
    cout<<"The Rear or Back element is: "<<Queue[Rear]<<endl;
   }
}


void display()
{
   if(isEmpty())
   {
       cout<<"Queue underflow"<<endl;
       return;
   }
   int temp=Front;
   while(temp<=Rear)
   {
       cout<<Queue[temp];
       if(temp<Rear)
       {
           cout<<"<-";
       }
       temp++;
   }
   cout<<endl;
}


int find_size()
{
   int cnt=0;
   if(isEmpty())
   {
       return cnt;
   }
   int temp=Front;
   while(temp<=Rear)
   {
       cnt++;
       temp++;
   }
   return cnt;
}

int main()
{
    //optimize();
    cout<<"Enter maximum number of elements which you want to insert in Queue: ";
    int n;
    cin>>n;
    cout<<"*********Selection Menu**********"<<endl;
    cout<<"Choose 1: Enqueue into Queue"<<endl;
    cout<<"Choose 2: Dequeue from Queue"<<endl;
    cout<<"Choose 3: To See Front element of Queue"<<endl;
    cout<<"Choose 4: To see Back element of Queue"<<endl;
    cout<<"Choose 5: To Display The elements of Queue"<<endl;
    cout<<"Choose 6: Size of Queue in a Certain time"<<endl;
    cout<<"Choose 7: Check whether the queue is empty or not"<<endl;
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
            cout<<"Enter The value which you want to Enque in queue: ";
            cin>>value;
            enqueue(value,n);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Front_element();
            break;
        case 4:
            Back_element();
            break;
        case 5:
            display();
            break;
        case 6:
            int Size;
            Size=find_size();
            if(!Size) cout<<"The Queue is empty"<<endl;
            else cout<<"The size of Queue is: "<<Size<<endl;
            break;
        case 7:
            bool Empty;
            Empty=isEmpty();
            if(Empty) cout<<"The Queue is empty"<<endl;
            else cout<<"The Queue is not empty"<<endl;
            break;
        default:
            break;
        }
        cout<<"Choose the option from The option menu: ";
        cin>>choose;
    }
    return 0;
}


