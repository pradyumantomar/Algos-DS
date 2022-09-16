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

void levelorder(TreeNode * root){
    if(root == NULL){
        return;
    }

    queue<TreeNode*> qt;
    qt.push(root);
    qt.push(NULL);

    while(!qt.empty()){
        TreeNode * temp = qt.front();
        qt.pop();

        if(temp == NULL){
            cout<<endl;
            if(!qt.empty()){
                qt.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                qt.push(temp->left);
            }
            if(temp->right){
                qt.push(temp->right);
            }
        }
    }
}

void traverseLeft(TreeNode *root, vector<int> &ans){

    if(root == NULL){
        return;
    }

    //leaf node check
    if(root->left == NULL && root->right == NULL ){
        return ;
    }

    //store data
    ans.pb(root->data);

    if(root->left){
        traverseLeft(root->left, ans);
    }
    else{
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(TreeNode * root, vector<int> &ans){

    if(root == NULL){
        return ;
    }

    if(root->left == NULL and root->right == NULL){
        ans.pb(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

}

void traverseRight(TreeNode * root, vector<int> &ans){

    if(root == NULL){
        return ;
    }

    if(root->left == NULL and root->right == NULL){
        return;
    }

    if(root->right){
        traverseRight(root->right, ans);
    }
    else{
        traverseRight(root->left, ans);
    }

    ans.pb(root->data);

      

}

void boundary(TreeNode* root){

    vector<int> ans;
    if(root == NULL){
        return ;
    }

    ans.pb(root->data);

    //left part store
    traverseLeft(root->left,ans);


    // leaf store left part and right part
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);

    // traverse right sub tree

    traverseRight(root->right, ans);

    for(auto i : ans){
        cout<<i<<" ";
    }

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
    
    cout<<"level order"<<endl;
    levelorder(root);

    cout<<"\n"<<"Boundray Order\n";
    boundary(root);

    return 0;
}