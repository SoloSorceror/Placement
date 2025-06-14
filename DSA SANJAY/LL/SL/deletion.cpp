#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }  
};

void DeleteFromBeginning(Node*& head){
    if(head==nullptr){
        cout<<"List is empty";
    }
    Node* temp = head;
    head=head->next;
    delete temp;

}

void DeleteFromEnd(Node*& head){

    if(head->next = nullptr){
        delete head;
        head = NULL;
    }else{
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

void DeleteFromPos(Node*& head, int pos){
    if(pos == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
    } else{
        Node *temp = head;
        for(int i =0; i<pos-1 && temp!= NULL; i++){
            temp = temp->next;
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

}