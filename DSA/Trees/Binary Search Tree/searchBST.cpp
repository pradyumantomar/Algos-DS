bool searchInBST(BinaryTreeNode<int> *root, int x) {
    int ans = false;
    
    while(root!=nullptr){
        if(root->data == x){
            ans = true;
            break;
        }
        else if(x > root->data){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    
    return ans;
    
}

// or both are same
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root == NULL){
        return false;
    }

    if(root->data == x){
       return true;
    }

     if(x > root->data){
        return searchInBST(root->right, x);
        }
    else{
        return searchInBST(root->left, x);
    }
}
