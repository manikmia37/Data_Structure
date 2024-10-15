#include<bits/stdc++.h>
#include "MyQueue_HeaderFile_with_pairDataType.h";
using namespace std;
typedef long long ll;
typedef double dl;

typedef pair<int,int> mytype;


int main()
{
    //optimize();
    Queue <mytype> custom_queue;
    cout<<"*************Option Menu************"<<endl;
    cout<<"Choose 1: To insert element in Queue"<<endl;
    cout<<"Choose 2: To pop element from Queue"<<endl;
    cout<<"Choose 3: To See Front element of Queue"<<endl;
    cout<<"Choose 4: To see Back element of Queue"<<endl;
    cout<<"Choose 5: To Display The elements of Queue"<<endl;
    cout<<"Choose 0: To Exit"<<endl;
    cout<<"Select Option : ";
    int choose;
    cin>>choose;
    while(choose)
    {
        switch(choose)
        {
        case 1:
            cout<<"How many elements do you want to insert in Queue: ";
            int n;
            cin>>n;
            cout<<"Insert Elements: ";
            for(int i=1; i<=n; i++)
            {
                int val1,val2;
                cin>>val1>>val2;
                custom_queue.enqueue(make_pair(val1,val2));
            }
            break;
        case 2:
            custom_queue.pop();
            break;
        case 3:
            custom_queue.peek();
            break;
        case 4:
            custom_queue.Back();
            break;
        case 5:
            custom_queue.display();
            break;
        default:
            break;
        }
        cout<<"Select Option: ";
        cin>>choose;
    }
    return 0;
}



