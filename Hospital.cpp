#include <bits/stdc++.h>

using namespace std ;

//defines a node
struct Node
{
  int data;
  Node *next;
};

//defines a class
class QUEUE
{
    private:
        Node *front;
        int count; // size of the queue
    public:
        QUEUE(); // constructor
        void addnode(int value); // prototype function
        void removeFront(); // prototype function
        void displayQueue(); // prototype function
        int getCount(); // prototype function
        ~QUEUE(); // destructor
};

//constructor
QUEUE::QUEUE()
{
    front=NULL;
    count=0;
}

//add an element to the queue
void QUEUE::addnode(int value)
{
    //create a node
    Node *temp;
    temp = new Node;
    temp->data=value;
    temp->next= NULL;
    if(front==NULL) //if the queue is empty
        front=temp;
    else
    {
        Node *current = front ;
        while ( current -> next != NULL )
            current = current -> next ;
        current -> next = temp ;
    }
    count++;
}

//displays the elements of queue
void QUEUE::displayQueue()
{
    if(front == NULL || count == 0)
    {
        cout<<"Queue is empty\n";
        return;
    }
    Node *tempNode;
    tempNode=front;
    while(tempNode !=NULL)
    {
        cout <<tempNode->data << " ";
        tempNode=tempNode->next;
    }
    cout << endl;
}

//removes the element from the queue
void QUEUE::removeFront()
{
    if(front == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }
    Node *tempNode;
    tempNode = front;
    cout<<"Deleted item :"<<front->data << endl;
    if(count >0)
    {
        front = tempNode->next;
        count--;
        delete tempNode; // deletes the node
    }
}

//returns the number of elements in the queue
int QUEUE::getCount()
{
    return count;
}

//destructor
QUEUE::~QUEUE()
{
    if(front == NULL)
    {
        cout<<"No memory is used\n";
        return;
    }
    Node *tempNode;
    tempNode= front;
    while ( count )
    {
        front = tempNode->next;
        count--;
        delete tempNode;
    }
}

int main()
{
    QUEUE Queue;
    cout<<"===============================\n";
    cout<<"\tMENU\n";
    cout<<"===============================\n";
    cout<<"1. Display\n";
    cout<<"2. Add\n";
    cout<<"3. Serve\n";
    cout<<"4. Number of Elements\n";
    cout<<"5. Remove all\n";
    cout<<"6. Exit\n";
    cout<<"================================\n";
    while(true)
    {
        int option;
        int n;
        cout<<"Choose your option :";
        cin>>option;
        if ( option == 1 )
            Queue.displayQueue();
        else if ( option == 2 )
        {
            cout<<"Enter data to add :";
            cin>>n;
            Queue.addnode(n);
            cout<<"\nAdded successfully\n";
        }
        else if ( option == 3 )
            Queue.removeFront();
        else if ( option == 4 )
            cout<<"\nNumber of element(s) :"<<Queue.getCount() << endl;
        else if ( option == 5 )
            Queue.~QUEUE();
        else if ( option == 6 )
            return 0;
        else
            cout<<"please select valid option.\n";
    }
}
