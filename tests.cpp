#include <bits/stdc++.h>
using namespace std;

//linked list node
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete this->next;
            this->next = NULL;
        }
        cout << "freed memory with value " << value << endl;
    }
};

//insert at head
void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

//insert at tail
void insertAtTail(Node *&head, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(data);
    temp->next = newNode;
}

//length of linked list
int length(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

//insert at middle
void insertAtMiddle(Node *&head, int data, int pos)
{
    if (head == NULL || pos == 0)
    {
        insertAtHead(head, data);
        return;
    }
    else if (pos > length(head))
    {
        insertAtTail(head, data);
        return;
    }
    else
    {
        int jump = 1;
        Node *temp = head;
        while (jump <= pos - 1)
        {
            temp = temp->next;
            jump++;
        }
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//delete node by position
void deleteNode(Node *&head, int pos)
{
    if (head == NULL)
    {
        return;
    }
    else if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    else
    {
        int jump = 1;
        Node *temp = head;
        while (jump <= pos - 1)
        {
            temp = temp->next;
            jump++;
        }
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        return;
    }
}

//print linked list
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//sort linked list
void sorting(Node *&head)
{
    int len = length(head);
    while(len){
        Node* temp = head;
        int i = 1;
        while (i<len && temp != NULL)
        {
            if(temp->data > temp->next->data){
                swap(temp->data, temp->next->data);
            }
            temp = temp->next;
            i++;
        }
        len--;
    }
}

void removeduplicates(Node* head){
    if(head->next == NULL){
        return;
    }
    //sort the linked list
    sorting(head);
    cout << endl;
    Node* curr = head;
    while(curr->next != NULL){
        if(curr->data == curr->next->data){
            Node* todel = curr->next;
            curr->next = curr->next->next;
            todel->next = NULL;
            delete todel;
        }
        else{
            curr = curr->next;
        }
    }
}


int main(){
    Node *head = NULL;
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 7);
    insertAtHead(head, 8);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 9);

    removeduplicates(head);

    print(head);
    return 0;
}