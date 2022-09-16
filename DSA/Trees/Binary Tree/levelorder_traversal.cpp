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

void levelOrder(TreeNode* root){
    if(root==NULL){
        return ;
    }

    queue<TreeNode *> qt;
    qt.push(root);

    while(!qt.empty()){
        TreeNode * temp = qt.front();
        qt.pop();
        cout<<temp->data<<" ";

        if(temp->left){
            qt.push(temp->left);
        }

        if(temp->right){
            qt.push(temp->right);
        }
    }
}

void levelOrder_with_space(TreeNode * root){
    if(root==NULL){
        return ;
    }

    queue<TreeNode *> qt;
    qt.push(root);
    qt.push(NULL); //  enter null for level order

    while(!qt.empty()){
        TreeNode * temp = qt.front();
        qt.pop();

        if(temp!=NULL){        // if no null encounter -> do regular level order
            cout<<temp->data<<" ";
             if(temp->left){
                qt.push(temp->left);
             }
             if(temp->right){
                qt.push(temp->right);
             }
        }
        else{       // if encounter output new line
            cout<<endl;
            if(!qt.empty()){  // check not empty 
                qt.push(NULL);
            }
        }
    }

}


int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(11);
    root->right->right = new TreeNode(17);

    levelOrder(root);
    cout<<endl;
    levelOrder_with_space(root);

    return 0;
}