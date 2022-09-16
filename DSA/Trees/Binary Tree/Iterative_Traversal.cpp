#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define vi vector<int>
#define reverse(x) reverse(x.begin(),x.end())


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

void preorder(node * root){
    if(root==NULL){
        return ;
    }

    stack<node*> st;
    st.push(root);

    while(!st.empty()){
        node * temp = st.top();
        st.pop();
        cout<<temp->data<<" ";

        if(temp->right){
            st.push(temp->right);
        }
        if(temp->left){
            st.push(temp->left);
        }
    }

}


void inorder(node * root){
    if(root==NULL){
        return ;
    }

    stack<node*> st;
    
    node * temp = root;

    while(true)
    {
        if(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()){
                break;
            }
            temp = st.top();
            st.pop();
            cout<<temp->data<<" ";
            temp=temp->right;
        }
    }
    

}

void postorder(node * root){
    if (root ==NULL){
        return;
    }

    stack<node*> s1,s2;
    s1.push(root);
    node * temp ;
    while(!s1.empty()){
        temp = s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

void postorder2(node * root){
    if (root ==NULL){
        return;
    }

    stack<node*> s1;
    s1.push(root);
    node * temp ;
    vi ans;
    while(!s1.empty()){
        temp = s1.top();
        s1.pop();
        ans.pb(temp->data);

        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
    }

    reverse(ans);

    for(auto i :ans){
        cout<<i<<" ";
    }
}




int main(){

    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->left->right = new node(7);
    root->right->left->right->right = new node(8);


    cout<<"Iteractive Preorder\n";
    preorder(root);
    cout<<endl;

    cout<<"Iteractive Inorder\n";
    inorder(root);
    cout<<endl;
    
    cout<<"Iteractive Postorder using 2 stacks\n";
    postorder(root);
    cout<<endl;

    

    cout<<"Iteractive Postorder using 1 stacks\n";
    postorder2(root);
    cout<<endl;



    return 0;
}
