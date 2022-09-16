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

void preorder(TreeNode * root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void morris(TreeNode * root){

    if (root == NULL)
        return;

    
    TreeNode * curr;
    curr = root;

    vector<int> mor;

    while(curr != NULL){

        // if left is null print & move to right
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            mor.push_back(curr->data);
            curr = curr->right;
        } 
        // else move to left
        else{
            TreeNode * prev ;
            prev=  curr->left;
            
            // find rightmost of left of current root
            while((prev->right != NULL)  &&  ( prev->right != curr)){
                prev = prev->right;
            }
            
            //if rightmost right is equal to current root
            //break thread and move to right
            if(prev->right == curr){
                prev->right = NULL;
                curr = curr->right;
            }
            // else make thread move to left and print
            else{
                cout<<curr->data<<" ";
                mor.push_back(curr->data);
                prev->right = curr;
                curr = curr->left;
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

    
    cout<<"Preorder order"<<endl;
    preorder(root);
    return 0;
}