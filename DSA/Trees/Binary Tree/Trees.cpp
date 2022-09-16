#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define vi vector<int>



class node{
    public:
        int data;
        node * left;
        node * right;

        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

};


// node * buildtree(){

// }

void preorder(node * root){

    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node * root){

    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

void inorder(node * root){

    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void levelorder(node * root){

//O(N) -Tc & O(N) -SC
    if(root==NULL){
        return;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node * temp = q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left!=NULL){
            q.push(temp->left);
        }

        if(temp->right!=NULL){
            q.push(temp->right);
        }

    }
}


int main(){

    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<"Preorder\n";
    preorder(root);
    cout<<endl;
    
    cout<<"Postorder\n";
    postorder(root);
    cout<<endl;

    cout<<"Inorder\n";
    inorder(root);
    cout<<endl;

    cout<<"Level order \n";
    levelorder(root);
    cout<<endl;


    return 0;
}
