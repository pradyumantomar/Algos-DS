bool solve(BinaryTreeNode<int>* root , int mx ,int mn){
    if(root == NULL){
        return true;
    }
    if(root->data >= mn and root->data <= mx){
        bool left = solve(root->left ,root->data, mn );
        bool right = solve(root->right, mx , root->data );
        return (left and right);
    }
    else{
         return false;   
    } 
}
bool validateBST(BinaryTreeNode<int> *root) {
   int mx = INT_MAX;
    int mn = INT_MIN;
    return solve(root, mx, mn);
}