int solve(BinaryTreeNode<int>* root , int k , int &count){
    
    if(root == NULL){
        return -1;
    }

    // left part rec
    int left = solve(root->left, k , count);
    
    if(left != -1){
        return left;
    }
    
    // root 
    count++;
    if(count==k){
        return root->data;
    }
    
    // right part rec
    return solve(root->right, k, count);
    
}


int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int count = 0;
    int ans = solve(root,k,count);
    return ans;
}