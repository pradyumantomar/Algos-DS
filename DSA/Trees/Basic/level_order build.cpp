#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * Left;
    Node * Right;

    Node(int d){
        data=d;
        Left=Right=NULL;
    }

};

Node * build(){
    int x;
    cin>>x;

    Node * root = new Node(x);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node * curr_ptr = q.front();
        q.pop();
        int l , r;
        cin>>l>>r;
        if(l!=-1){
            curr_ptr->Left = new Node(l);
            q.push(curr_ptr->Left);
        }
        if(r!=-1){
            curr_ptr->Right= new Node(r);
            q.push(curr_ptr->Right);
        }
    }
    
 return root;   

}



void print_inorder(Node * root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node * curr_ptr = q.front();
        if(curr_ptr==NULL){
            cout<<"\n";
            q.pop();
            if(!q.empty())q.push(NULL);
        }
        else{
            cout<<curr_ptr->data<<" ";
        
            if(curr_ptr->Left){
                q.push(curr_ptr->Left);
            }
            if(curr_ptr->Right){
                q.push(curr_ptr->Right);
            }
            q.pop();
            }
    }

}

int main(){


    Node * root = build();
    print_inorder(root);
    return 0;
}