#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = right = NULL;
    }

};

node* buildtree(){
        int d;
        cin>>d;
        if(d == -1){
            return NULL;
        }

        node* root = new node(d);
        root->left = buildtree();
        root->right = buildtree();

        return root; 
    }

void print(node * root){
    if(root == nullptr)return;

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);   
}

void inorderTraversal(node * root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* tmp = q.front();
        cout<<tmp->data<<" ";
        q.pop();

        if(tmp->left)q.push(tmp->left);
        if(tmp->right)q.push(tmp->right);
    }
} 

void inorderWithSpace(node * root){
    queue<node *> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        node * tmp = q.front();
        if(tmp == nullptr){
            cout<<endl;
            q.pop();
            if(!q.empty()) q.push(nullptr);
            }
        else{
            cout<<tmp->data<<" ";
            q.pop();

            if(tmp->left)q.push(tmp->left);
            if(tmp->right)q.push(tmp->right);
    }
}
}


int main(){
    node * root = buildtree();
    print(root);
    cout<<endl;
    inorderTraversal(root);
    cout<<endl;
    inorderWithSpace(root);

}