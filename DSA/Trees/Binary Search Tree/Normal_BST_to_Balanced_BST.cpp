void inorder(Node* root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
    
}

Node* balancedBST(int start , int end , vector<int> &ans){
    
    //check outbound
    if(start>end){
        return NULL;
    }
    
    //find mid
    int mid = (start+end)/2;
    
    //create a node
    Node * currNode = new Node(ans[mid]);
    
    //create left subtree and right subtree
    currNode->left = balancedBST(start , mid-1 , ans);
    currNode->right = balancedBST(mid+1, end , ans);
    
    //return root
    return currNode;
    
}


Node* buildBalancedTree(Node* root)
{
	vector<int> ans;
	inorder(root,ans);

    int start =  0 ;
    int end = ans.size() - 1;
	Node * temp = balancedBST(start,end,ans);
	return temp;
}