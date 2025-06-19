#include <iostream>
#define MAX 100

using namespace std;

int stack[MAX];
int top = -1;

void push(int value){
    if(top >=MAX-1){
        cout<<"Stack overflow \n";
        return;
    }
    stack[++top] = value;
    cout<<value<<"Pushed to Stack \n";

}

// POP

void pop(){
    if(top<0){
        cout<<"Stack Underflow";
        return;
    }
    cout<<stack[top--]<<"popped from stack\n";
}

void peek() {
    if (top < 0) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << stack[top] << endl;
}

void display() {
    if (top < 0) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    return 0;
}