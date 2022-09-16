#include<bits/stdc++.h> 
using namespace std;

//input-> 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
//output-> 1 2 4 5 7 3 6

class Node{
public:
    int data;
    Node * left;
    Node * right;

    Node(int d){
        data=d;
        left=right=NULL;
    }
};
// build tree 
Node* buildTree(){
    int d;
    cin>>d;

    if(d==-1)return NULL;
    
    Node * n = new Node(d);
    n->left=buildTree();
    n->right=buildTree();
    return n;


}
//preorder print
void Print_preorder(Node * root){
    if(root ==NULL)return;
    cout<<root->data<<" ";
    Print_preorder(root->left);
    Print_preorder(root->right);
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif    
 Node * root = buildTree();
 Print_preorder(root);
 

    return 0;
}