https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// recursion
int solve(vector<int> &nums, int n){
    if(n < 0)return 0;
    if(n == 0)return nums[0];

    int include = solve(nums , n-2) + nums[n];
    int exclude = solve(nums, n-1) + 0;

    return max(include,exclude);


}


int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int ans = solve(nums,n-1);
    return ans;
}

// top down or memo
int solve(vector<int> &nums, vector<int> &dp , int n){
    if(n < 0)return 0;
    else if(n == 0)return nums[0];

    if(dp[n] != -1)return dp[n];
    else{
        int include = solve(nums,dp,n-2) + nums[n];
        int exclude = solve(nums,dp,n-1) + 0;

        dp[n] = max(include,exclude);
        return dp[n];
    }

}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1 , -1);
    int ans = solve(nums,dp,n-1);
    return ans;
}

// tabulation

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1);
    dp[0] = nums[0];
    for(int i = 1 ; i<n;i++){
        int include = nums[i] + (i >1 ? dp[i-2]:0);
        int exclude = 0 + dp[i-1];
        dp[i] = max(include,exclude);
    }

    return dp[n-1];
}

// space optimizatiom
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev = 0;
    int last = nums[0];
    for(int i = 1 ; i<n;i++){
        int include = nums[i] + prev;
        int exclude = 0 + last;
        int ans = max(include,exclude);
        prev = last;
        last = ans;
    }

    return last;
}
