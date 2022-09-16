#include<bits/stdc++.h>
using namespace std;

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

int height(TreeNode * root){
        if(!root){
            return 0;
        }
        
        int l = height(root->left);
        int r = height(root->right);
        
        return  1 + max(l,r); 
        
        
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int l = diameter(root->left);
        int r = diameter(root->right);

        int diameterThroughNode = 1 + height(root->left) 
                                    + height(root->right);
        
        return max(max(l,r),diameterThroughNode);
     
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

    //cout<<diameter(root);
    int res = INT_MIN;
    diameterFast(root,res);
    cout<<res;


    return 0;
}