class Solution {
private:
    int res;
public:
    int Solve(Node* root) {
        if (root == NULL)
            return 0;

        int l = Solve(root->left);
        if(l<0){
            l=0;
        }
        int r = Solve(root->right);
        if(r<0){
            r=0;
        }

        int temp = max(root->data + max(l, r), root->data);
        int ans = max(temp, l + r + root->data);
        res = max(res, ans);

        return temp;
    }
    int findMaxSum(Node* root) {
        res = INT_MIN;
        Solve(root);
        return res;
    }
};