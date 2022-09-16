#include<bits/stdc++.h>
using namespace std;

#define pb push_back

class TreeNode{
    
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data=data;
        left = NULL;
        right = NULL;
    }

};

void inorder(TreeNode * root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void morris(TreeNode * root){

    if (root == NULL)
        return;

    
    TreeNode * curr;
    curr = root;

    vector<int> mor;

    while(curr != NULL){
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            mor.push_back(curr->data);
            curr = curr->right;
        }
        else{
            TreeNode * prev ;
            prev=  curr->left;
            
            while((prev->right != NULL)  &&  ( prev->right != curr)){
                prev = prev->right;
            }

            if(prev->right ==NULL){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                cout<<curr->data<<" ";
                mor.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    cout<<endl;
    
    // //for extra print
    // for(int i : mor){
    //     cout<<i<<" ";
    // }
    cout<<endl;
}


int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(11);
    root->right->right = new TreeNode(17);
    root->left->left->left = new TreeNode(70);
    root->left->left->right = new TreeNode(170);
    root->left->right->left = new TreeNode(110);
    root->left->right->right = new TreeNode(110);
    root->right->right->right = new TreeNode(107);
    root->right->right->right->right = new TreeNode(107);
    

    //
    cout<<"Morris Traversal"<<endl;
    morris(root);



    cout<<endl;

    
    cout<<"Inorder order"<<endl;
    inorder(root);
    return 0;
}