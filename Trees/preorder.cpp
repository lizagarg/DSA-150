#include<iostream>
using namespace std;
class Node {
        
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

void inOrder(Node* root) {
    if(!root) return;
    inOrder(root->left);
    cout<<root->data;
    inOrder(root->right);
}

int main() {
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->right= new Node(4);

    inOrder(root);
}