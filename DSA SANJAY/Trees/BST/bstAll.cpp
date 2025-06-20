#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;

    Node(int value){
        data = value;
        left = right = nullptr;
    }
};

Node *insert(Node *root, int target){

    if(!root){
        Node *temp = new Node(target);
        return temp;
    }

    if(target<root->data){
        root->left = insert(root->left, target);
    }else{
        root->right = insert(root->right, target);
    }
    return root;
}

void inorder(Node *root){

    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node *root){

    if(!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void preorder(Node *root){

    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void levelOrder(Node* root){
    if(!root)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

bool searching(Node *root, int target){

    if(!root)
    return false;

    if(root->data == target)
    return true;

    if(root->data > target)
    return searching(root->left, target);
    else
    return searching(root->right, target);
}

Node* deleteNode(Node* root, int target){
    if(!root){
        return NULL;
    }
    if(root->data > target){
        root->left = deleteNode(root->left, target);
        return root;
    }else if(root->data < target){
        root->right = deleteNode(root->right, target);
        return root;
    }
    else{
        if(!root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if(!root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;
        while(temp && temp->left){
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
        return root;
    }

}


int main(){

}