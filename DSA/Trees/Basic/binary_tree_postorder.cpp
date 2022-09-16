#include<bits/stdc++.h> 
using namespace std;

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

Node * buildTree(){
    int d;
    cin>>d;

    if(d==-1)return NULL;// check null
    
    Node * n = new Node(d);// new node
    n->left=buildTree();//left sub tree
    n->right=buildTree();// right sub tree
    return n;


}

void Print_preorder(Node * root){

    if(root ==NULL)return;//null check
    
    cout<<root->data<<" ";//root
    Print_preorder(root->left);//left subtree
    Print_preorder(root->right);//right subtree
}

void print_inorder(Node *root){
    
    if(root == NULL)return ;// null check
    
    print_inorder(root->left);//left subtree
    cout<<root->data<<" ";//root
    print_inorder(root->right);//right subtree
}

void print_postorder(Node * root){
    if (root==NULL)return;

    print_postorder(root->left);
    print_postorder(root->right);
    cout<<root->data<<" ";
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

 Node * root = buildTree();
 cout<<"Preorder Traversal ->"<<"\n";
 Print_preorder(root);
 cout<<"\ninorder Traversal ->"<<"\n";
 print_inorder(root);
 cout<<"\npreorder Traversal ->"<<"\n";
 print_postorder(root);
return 0;
}