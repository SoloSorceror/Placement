#include<iostream>
using namespace std;


//  Node classs with data left and right Node pointer and a constructor Node to initialise the value to the data field

class Node {
    public:
    int data;
    Node *left, *right;

    Node (int value){

        left = right = NULL;
        data = value;
    }
};



Node* BinaryTree(){

    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp = new Node(x);
    // Left side create
    cout<<"Enter the left child of: "<<x<<" ";
    temp->left = BinaryTree();

    // right side create
    cout<<"Enter the right child of: "<<x<<" ";
    temp->right = BinaryTree();
    return temp;

}

void preorder(Node *root){

    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void inorder(Node *root){

    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
void postorder(Node *root){

    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

void leftprint(Node *root){

    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    leftprint(root->left);

}


int main(){
    

    cout<<"Enter the root Node ";
    Node *root;
    root = BinaryTree();

    //Preorder print

    cout<<"Pre order: "<<endl;
    preorder(root);

    //Inorder print
    cout<<"\nInorder print: "<<endl;
    inorder(root);

    //postorder print
    cout<<"\nPost order print: "<<endl;
    postorder(root);

    
    return 0;
}