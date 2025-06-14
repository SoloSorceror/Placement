#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = nullptr;       
    }

};

void Insertion(Node*& head, int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void InsertionAtEnd(Node*& head, int value){

    Node* newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next!= nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}


void InsertionAtPosition(Node*& head, int value, int position){
    Node* newNode = new Node(value);
    if(position == 0){
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for(int i = 0; i<position-1 && temp != nullptr; i++){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout<<"Position out of bound.\n";
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void print(Node* head){
    while(head != nullptr){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL\n";
}

void DeletionStart(Node*& head){
    if(head==nullptr){
        cout<<"List is empty nothing to delete";
    }
}

int main(){
    Node* head = nullptr;
    InsertionAtPosition(head, 10, 0); // 10
    InsertionAtPosition(head, 20, 1); // 10 -> 20
    InsertionAtPosition(head, 30, 2); // 10 -> 20
    InsertionAtPosition(head, 40, 3); // 10 -> 20
    Insertion(head, 0);
    InsertionAtEnd(head, 50);
    InsertionAtEnd(head, 60);
    print(head);
    
}