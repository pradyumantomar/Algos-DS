int diameterFast(TreeNode * root , int &res){

        if(root==NULL){
            return 0;
        }

        int left  = diameterFast(root->left,res);
        int right = diameterFast(root->right,res);
        int diameterThroughNode = left + 1 + right ;

        int temp = 1 + max(left,right);

        int ans = max(temp,diameterThroughNode);

        res = max(res,ans);

        return temp;


    }

    int main(){

    int res = INT_MIN;
    diameterFast(root,res);
    cout<<res;


    return 0;
}