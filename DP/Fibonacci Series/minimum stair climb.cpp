https://leetcode.com/problems/min-cost-climbing-stairs/

// basic recursion code
class Solution {
public:
    // f(n) = min(f(n-1) + fn(n-2)) + cost[n]

    int solve(vector<int>& cost , int n){
        if(n == 0)return cost[0];
        if(n == 1)return cost[1];

        return cost[n] + min(solve(cost , n-1), solve(cost , n-2));

    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = min(solve(cost,n-1), solve(cost,n-2));      // not adding cost as we dont climb up
        return ans;
    }
};


// top down or memo

class Solution {
public:

    int solve(vector<int> &cost , vector<int> &dp , int n){
      if(n == 0)return cost[0];
      else if(n == 1)return cost[1];

      if(dp[n] != -1)return dp[n];
      else {
        dp[n] = cost[n] + min(solve(cost,dp,n-1), solve(cost,dp,n-2));
        return dp[n];
      }

    }

    int minCostClimbingStairs(vector<int>& cost) {
          int n = cost.size();
          vector<int> dp(n+1,-1);

          int ans = min(solve(cost,dp,n-1) , solve(cost,dp,n-2));
          return ans;
    }
};

// tabulation or bottom up
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
      vector<int> dp(n);
      dp[0] = cost[0];
      dp[1] = cost[1];
       for(int i = 2 ;i<n ;i++){
         dp[i] = cost[i] + min(dp[i-1] ,dp[i-2]);
       }
       return min(dp[n-2],dp[n-1]);
    }
};


// space optimization
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();
      int prev = cost[0];
      int last = cost[1];
       for(int i = 2 ;i<n ;i++){
         int curr = cost[i] + min(prev,last);
         prev = last;
         last = curr;
       }

       return min(prev,last);

    }
};
