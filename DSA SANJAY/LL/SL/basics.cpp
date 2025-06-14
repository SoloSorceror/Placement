#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

//insertion from the beginning
void InsertionFromBeginning(Node*&head, int value){
    Node* newNode = new Node(value);
    //Node* newNode = new Node();
    // newNode->data = value;
    newNode->next = head;
    head = newNode;
}

//Insertion at End

void InsertionAtEnd(Node* head, int value){
    Node* newNode = new Node(value);
    if(head==nullptr){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

//Insertion at specific position


void InsertionAtPos(Node*& head, int value, int pos){
    Node* newNode = new Node(value);
    if(pos ==0){
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for(int i =0; i<pos-1 && temp != nullptr; i++){
        temp = temp->next;
    }

    if(temp == nullptr){
        cout<<"Position out of bound.\n";
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;

}

void printNode(Node* head){
    while(head!= nullptr){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL\n";
}

int main(){

    Node* head = nullptr;
    InsertionAtPos(head, 10, 0); // 10
    InsertionAtPos(head, 20, 1); // 10 -> 20
    InsertionAtPos(head, 30, 2); // 10 -> 20 -> 30
    InsertionAtPos(head, 40, 3); // 10 -> 20 -> 30 -> 40
    printNode(head);
}