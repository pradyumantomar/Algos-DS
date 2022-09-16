https://leetcode.com/problems/house-robber/


// Recursion
class Solution {
public:
    int solve(vector<int> &nums, int n){
        if(n<0)return 0;
        if(n == 0)return nums[0];
        
        // include
        int include = solve(nums,n-2) + nums[n];
        
        // exclude
        int exclude = solve(nums,n-1);
        
        return max(include,exclude);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = solve(nums,n-1);
        return ans;
    }
};

//Memo
class Solution {
public:
    int solve(vector<int> &nums, vector<int> &dp , int n){
        if(n < 0)return 0;
        else if(n == 0)return nums[0];
        
        if(dp[n] != -1)return dp[n];
        
        int include = solve(nums,dp,n-2) + nums[n];
        int exclude = solve(nums,dp,n-1);
        
        return dp[n] = max(include,exclude);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+1,-1);
        int ans = solve(nums,dp,n-1);
        
        return ans;
        
        
    }
};

//Tabulation
class Solution {
public:
    int solve(vector<int> &nums, int n){
        vector<int> dp(n , 0);
        dp[0] = nums[0];
        for(int i = 1 ; i<n ;i++){
            int include = nums[i] + (n>1?dp[n-2] : 0);
            int exclude = dp[n-1];
            dp[i] = max(include , exclude);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return 0;
        int ans = solve(nums,n);
        return ans;
    }
};