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
    Node *Prev;
    Node(int val)
    {
        value=val;
        Next=NULL;
        Prev=NULL;
    }
};

struct Test
{
    int position[1000];
};

void display(Node *&head)
{
    Node *temp=head;
    if(temp==NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    while(temp != NULL)
    {
        cout<<temp->value;
        if(temp->Next != NULL)
        {
            cout<<"->";
        }
        temp=temp->Next;
    }
}

void insertAtHead(Node *&head, int val)
{
    Node *newnode=new Node(val);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    Node *temp=head;
    newnode->Next=temp;
    temp->Prev=newnode;
    head=newnode;
}

void insertAtTail(Node *&head, int val)
{
    Node *newnode = new Node(val);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    Node *temp=head;
    while(temp->Next != NULL)
    {
        temp=temp->Next;
    }
    temp->Next=newnode;
    newnode->Prev=temp;
}


int count_length(Node *&head)
{
    Node *temp=head;
    int cnt=0;
    while(temp != NULL)
    {
        cnt++;
        temp=temp->Next;
    }
    return cnt;
}

void insertAtspecificPosition(Node *&head, int pos, int val)
{
    if(head==NULL)
    {
        cout<<"The List is Empty"<<endl;
    }
    else
    {
        if(pos>=1 && pos<=count_length(head)+1)
        {
            if(pos==1)
            {
                insertAtHead(head,val);
                return;
            }
            if(pos==count_length(head)+1)
            {
                insertAtTail(head,val);
                return;
            }
            Node *newnode=new Node(val);
            Node *temp=head;
            int cnt=1;
            while(cnt != pos-1)
            {
                temp=temp->Next;
                cnt++;
            }
            newnode->Next=temp->Next;
            temp->Next->Prev=newnode;
            temp->Next=newnode;
            newnode->Prev=temp;
        }
        else
        {
            cout<<"Enter The Valid Position"<<endl;
        }
    }
}

int search_Value_in_uniqueList(Node *&head, int val)
{
    if(head==NULL)
    {
        //cout<<"The List is Empty"<<endl;
        return 0;
    }
    bool flag=true;
    int pos=1;
    Node *temp=head;
    while(temp->value != val)
    {
        if(temp->Next==NULL)
        {
            flag=false;
            break;
        }
        temp=temp->Next;
        pos++;
    }
    if(!flag) return 0;
    else
    {
        return pos;
    }

}


Test search_Value_in_DuplicateList(Node *&head, int val)
{
    Test S;
    int k=1,pos=1;
    Node *temp=head;
    while(temp != NULL)
    {
        if(temp->value==val)
        {
            S.position[k]=pos;
            k++;
        }
        temp=temp->Next;
        pos++;
    }
    S.position[0]=k-1;
    return S;
}

void insertAt_After_specific_Value(Node *&head, int prefered_value, int value)
{
    int position=search_Value_in_uniqueList(head,prefered_value);
    if(position==0)
    {
        if(head==NULL)
        {
            cout<<"The List is Empty"<<endl;
        }
        else
        {
            cout<<"Preferred Value does not exist in the List"<<endl;
        }
    }
    else
    {
        insertAtspecificPosition(head,position+1,value);
    }
}

void insertAt_After_specific_Value_in_DuplicateList(Node *&head, int prefered_value, int val)
{
    Test S;
    S=search_Value_in_DuplicateList(head,prefered_value);
    if(S.position[0]==0)
    {
        if(head==NULL)
        {
            cout<<"The List is Empty"<<endl;
        }
        else
        {
            cout<<"Your preferred value does not exist in the list"<<endl;
        }
    }
    else
    {
        for(int i=1; i<=S.position[0]; i++)
        {
            insertAtspecificPosition(head,S.position[i]+i,val);
        }
    }
}

void deleteAtHead(Node *&head)
{
    if(head==NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    Node *temp=head;
    if(count_length(head)==1)
    {
        head=NULL;
        delete temp;
        return;
    }
    head=temp->Next;
    head->Prev=NULL;
    delete temp;
}

void deleteAtTail(Node *&head)
{
    if(head==NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    Node *temp=head;
    if(count_length(head)==1)
    {
        head=NULL;
        delete temp;
        return;
    }
    while(temp->Next != NULL)
    {
        temp=temp->Next;
    }
    temp->Prev->Next=NULL;
    delete temp;
}

void deleteAtspecificPosition(Node *&head, int position)
{
    if(position>=1 && position<=count_length(head))
    {
        if(position==1)
        {
            deleteAtHead(head);
            return;
        }
        if(position==count_length(head))
        {
            deleteAtTail(head);
            return;
        }
        int cnt=1;
        Node *temp=head;
        while(cnt != position)
        {
            temp=temp->Next;
            cnt++;
        }
        temp->Next->Prev=temp->Prev;
        temp->Prev->Next=temp->Next;
        delete temp;
    }
    else
    {
        if(head==NULL)
        {
            cout<<"The List is Empty"<<endl;
        }
        else
        {
            cout<<"Please Enter The valid Position"<<endl;
        }
    }
}

void delete_By_value_inUniqueList(Node *&head, int val)
{
    int position=search_Value_in_uniqueList(head,val);
    if(position==0)
    {
        if(head==NULL)
        {
            cout<<"The List is Empty"<<endl;
        }
        else
        {
            cout<<"Your Preferred Value does not exist in List"<<endl;
        }
    }
    else
    {
       deleteAtspecificPosition(head,position);
    }
}

void delete_By_value_inDuplicateList(Node *&head,int val)
{
    Test S=search_Value_in_DuplicateList(head,val);
    int Size=S.position[0];
    if(!Size)
    {
        if(head==NULL)
        {
            cout<<"The List is Empty"<<endl;
        }
        else{
            cout<<"Your preferred does not exist in List"<<endl;
        }
    }
    else{
        int cnt=0;
        for(int i=1; i<=Size; i++)
        {
            deleteAtspecificPosition(head,S.position[i]-cnt);
            cnt++;
        }
    }
}

void display_inReverse_order(Node *&head)
{
   Node *temp=head;
   while(temp->Next != NULL)
   {
       temp=temp->Next;
   }
   while(temp != NULL)
   {
       cout<<temp->value;
       if(temp->Prev != NULL)
       {
           cout<<"->";
       }
       temp=temp->Prev;
   }
}

int main()
{
    //optimize();
    Node *head=NULL;
    cout<<"Choose 1: Insertion At Head"<<endl;
    cout<<"Choose 2: Insertion At Tail"<<endl;
    cout<<"Choose 3: Insertion At Specific Position"<<endl;
    cout<<"Choose 4: Display The Doubly Linked List"<<endl;
    cout<<"Choose 5: Count length of Doubly Linked List"<<endl;
    cout<<"Choose 6: Searching A value (in Unique Doubly List)"<<endl;
    cout<<"Choose 7: Searching A value (in Duplicate Doubly List"<<endl;
    cout<<"Choose 8: Insertion after a specific value (Unique List)"<<endl;
    cout<<"Choose 9: Insertion after a specific value (Duplication enabled List)"<<endl;
    cout<<"Choose 10: Deletion at Head"<<endl;
    cout<<"Choose 11: Deletion at Tail"<<endl;
    cout<<"Choose 12: Deletion at a Specific Position"<<endl;
    cout<<"Choose 13: Deletion by Value (Unique List)"<<endl;
    cout<<"Choose 14: Deletion by Value(Duplication enabled List)"<<endl;
    cout<<"Choose 15: Display The Doubly Linked List in Reverse Order"<<endl;
    cout<<"Choose 0: To exist"<<endl;
    cout<<"Choose The Option: ";
    int choose;
    cin>>choose;
    int value;
    while(choose)
    {
        switch(choose)
        {
        case 1:
            cout<<"Enter The value: ";
            cin>>value;
            insertAtHead(head,value);
            break;
        case 2:
            cout<<"Enter The Value: ";
            cin>>value;
            insertAtTail(head,value);
            break;
        case 3:
            cout<<"Enter The Value: ";
            cin>>value;
            cout<<"Enter The Position in which position you want to insert: ";
            int position;
            cin>>position;
            insertAtspecificPosition(head,position,value);
            break;
        case 4:
            display(head);
            break;
        case 5:
            int len;
            len=count_length(head);
            cout<<"The length is: "<<len<<endl;
            break;
        case 6:
            cout<<"Enter the value which you want to search: ";
            cin>>value;
            position=search_Value_in_uniqueList(head,value);
            if(position==0)
            {
                if(head==NULL)
                {
                    cout<<"The List is Empty"<<endl;
                }
                else
                {
                    cout<<"Searching Value does not exist in the List"<<endl;
                }
            }
            else
            {
                cout<<"Searching Value is found at position: "<<position<<endl;
            }
            break;
        case 7:
            cout<<"Enter the value which you want to search: ";
            cin>>value;
            Test S;
            S=search_Value_in_DuplicateList(head,value);
            int Size;
            Size=S.position[0];
            if(Size==0)
            {
                if(head==NULL)
                {
                    cout<<"The List is Empty"<<endl;
                }
                else
                {
                    cout<<"The searching does not exist in the List"<<endl;
                }
            }
            else
            {
                cout<<"Your searching value is found at: ";
                for(int i=1; i<=Size; i++)
                {
                    cout<<S.position[i];
                    if(i<Size) cout<<",";
                }
            }
        case 8:
            int prefered_value;
            cout<<"Enter The value which you want to insert: ";
            cin>>value;
            cout<<"Enter The value in which after you want to insert: ";
            cin>>prefered_value;
            insertAt_After_specific_Value(head,prefered_value,value);
            break;
        case 9:
            cout<<"Enter The value which you want to insert: ";
            cin>>value;
            cout<<"Enter The value in which after you want to insert: ";
            cin>>prefered_value;
            insertAt_After_specific_Value_in_DuplicateList(head,prefered_value,value);
            break;
        case 10:
            deleteAtHead(head);
            break;
        case 11:
            deleteAtTail(head);
            break;
        case 12:
            cout<<"Enter The Position which you want to delete: ";
            cin>>position;
            deleteAtspecificPosition(head,position);
            break;
        case 13:
            cout<<"Enter The value which you want to delete: ";
            cin>>value;
            delete_By_value_inUniqueList(head,value);
            break;
        case 14:
            cout<<"Enter The value which you want to delete: ";
            cin>>value;
            delete_By_value_inDuplicateList(head,value);
            break;
        case 15:
            display_inReverse_order(head);
            break;
        default:
            break;
        }
        cout<<endl;
        cout<<"Choose The Option: ";
        cin>>choose;
    }
    return 0;
}


