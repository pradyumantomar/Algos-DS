BinaryTreeNode<int>* bstDelete(BinaryTreeNode<int>* root, int key) {

    // if root is null    
    if(root == NULL){
        return NULL;
    }
    
    //if root->data is larger then move left
    if(root->data > key){
        root->left = bstDelete(root->left , key);
    }
    // if root->data is lower than move to right
    else if(root->data < key){
        root->right = bstDelete(root->right , key);
    }

    // if root->data is equal to key 
    else{
        // if it has no child
        if(root->left == NULL and root->right == NULL){
            delete root;
            return NULL;
        }
        // if it has only one child which is left
        if(root->left != NULL and root->right == NULL){
            BinaryTreeNode<int>* temp = root->left;
            delete root;
            return temp;
        }

        // if it has only one child whic is right
        if(root->left == NULL and root->right != NULL){
            BinaryTreeNode<int>* temp = root->right;
            delete root;
            return temp;
        }

        // if it has both child then you have 2 choice to made
        // choice 1  - maximum value of left sub tree
        // choice 2  - minimum value of right sub tree
        if(root->left != NULL and root->right != NULL){
            BinaryTreeNode<int>* temp = root->right;
            int mini;
            while(temp!=nullptr){
                mini = temp->data;
                temp = temp->left;
            }
            root->data = mini;
            root->right = bstDelete(root->right , mini);
            return root;
        }
        
    }
    return root;
}