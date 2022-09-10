#include <bits/stdc++.h>
using namespace std;

//doubly linked list node
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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
    if(head != NULL){
        head->prev = newNode;
    }
    head = newNode;
}

//delete by position
void deleteByPosition(Node *&head, int pos)
{
    if (head == NULL)
    {
        return;
    }
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }
    Node *temp = head;
    int jump = 1;
    while (temp != NULL && jump <= pos - 1)
    {
        temp = temp->next;
        jump++;
    }
    if (temp == NULL)
    {
        return;
    }
    temp->prev->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    delete temp;
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

//reverse doubly list
void reversedll(Node* &head){
    while(head != NULL){
        Node* temp = head->prev;
        head->prev = head->next;
        head->next = temp;
        if(head->prev == NULL){
            break;
        }
        head = head->prev;
    }
}

int main(){
    Node* head = NULL;
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    reversedll(head);
    print(head);   
    return 0; 
}