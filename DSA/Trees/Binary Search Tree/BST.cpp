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

node* createBST(node * &root , int data){
    
    if(root == NULL){
         root = new node(data);
        return root ;
    }

    if(data > root->data){
        root->right = createBST(root->right, data);
    }
    else{
        root->left = createBST(root->left, data);
    }

    return root;
}

void takeInput(node * &root){
    int data;
    cin>>data;
    
    while(data != -1){
        root = createBST(root,data);
        cin>>data;
    }
}

void preorder(node* root){
    if(!root){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    node* root = NULL;

    cout<<"Enter data";
    takeInput(root);

    cout<<endl;
    preorder(root);
    cout<<endl;

    return 0;
}
