#include <bits/stdc++.h>
using namespace std;

//circular linked list node
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
    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void printnode(Node *head){
    Node *temp = head;
    while(temp->next != head){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

bool checkcircular(Node* head){
    map<Node*, bool> mp;
    Node* temp = head->next;
    mp[head] = true;
    while(temp != NULL){
        if(mp[temp] != true){
            mp[temp] = true;
            temp = temp->next;
        }
        else{
            return true;
        }
    }
    return false;
}

int length(Node* head){
    int i = 1;
    Node* curr = head->next;
    while(curr != head){
        i++;
        curr = curr->next;
    }
    return i;
}

Node* splitll(Node* head){
    float len = length(head);
    int i = 1;
    Node* curr = head;
    while(i < ceil(len/2)){
        curr = curr->next;
        i++;
    }
    Node* head2 = curr->next;
    curr->next = head;
    Node* curr2 = head2;
    i++;
    while(i<len){
        curr2 = curr2->next;
        i++;
    }
    curr2->next = head2;
    return head2;
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);

    Node* head2 = splitll(head);
    printnode(head);
    printnode(head2);
    return 0;
}