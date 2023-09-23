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
};

void insertValueAtHead(linkedListNode *&head, int value)
{
    linkedListNode *temp = new linkedListNode(value);
    temp->next = head;
    head = temp;
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
    linkedListNode *node1 = new linkedListNode(69);
    linkedListNode *head = node1;
    printList(head);
    insertValueAtHead(head, 420);
    printList(head);
    return 0;
}