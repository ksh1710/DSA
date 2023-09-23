#include <iostream>
using namespace std;

class linkedListNode
{
public:
    int data;
    linkedListNode *next;

    linkedListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~linkedListNode(){
        int val = data;
        if (this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"delete success"<<val<<endl; 
        
    }
};

void insertValueAtHead(linkedListNode *&head, int value)
{
    linkedListNode *temp = new linkedListNode(value);
    temp->next = head;
    head = temp;
}

void insertValueAtTail(linkedListNode *&tail, int value)
{
    linkedListNode *temp = new linkedListNode(value);
    tail->next = temp;
    tail = tail->next;
}

void insertAtParticularPosition(linkedListNode *&tail, linkedListNode *&head, int position, int value)
{
    linkedListNode *temp = head;
    int c = 1;

    if (position == 1)
    {
        insertValueAtHead(head, value);
        return;
    }

    while (c < position - 1)
    {
        temp = temp->next;
        c++;
    }

    if (temp->next == NULL)
    {
        insertValueAtTail(tail, value);
        return;
    }

    linkedListNode *nodeToInsert = new linkedListNode(value);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNOde(int position, linkedListNode *&head)
{
    if (position == 1){
        linkedListNode* temp = head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        linkedListNode* curent =head;
        linkedListNode* previous = NULL;
        int c=1;
        while (c<position)
        {
            previous=curent;
            curent=curent->next;
            c++;
        }
        previous->next=curent->next;
        curent->next=NULL;
        delete curent;
        
    }
}
void printList(linkedListNode *&head)
{
    linkedListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "enter number";
    cin >> n;
    linkedListNode *node1 = new linkedListNode(n);
    linkedListNode *head = node1;
    linkedListNode *tail = node1;
    printList(head);
    insertValueAtTail(tail, 420);
    insertValueAtTail(tail, 12);
    insertValueAtHead(head, 12345);
    insertAtParticularPosition(tail, head, 3, 777);
    printList(head);
    deleteNOde(3,head);
    printList(head);
    return 0;
}