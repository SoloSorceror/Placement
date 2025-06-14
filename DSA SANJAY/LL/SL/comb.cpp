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
    Node* temp = head;
    head = head->next;
    delete temp;

}

void DeleteFromEnd(Node*& head){
    if(head->next == nullptr){
        delete head;
        head = nullptr;
    }else{
        Node* temp =head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

}

void DeleteFromPos(Node*& head, int position){
    if(position == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
    }else{
        Node* temp = head;
        for(int i = 0; i<position-1 &&temp!= nullptr; i++){
            temp=temp->next;
        }
       if(temp!= NULL && temp->next != NULL){
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }else{
            cout<<"Position out of bound.";
        }
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

    DeleteFromEnd(head);
    DeletionStart(head);
    DeleteFromPos(head,2);
    print(head);
    
}