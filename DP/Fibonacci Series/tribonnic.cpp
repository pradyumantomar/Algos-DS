// recursion
class Solution {
public:
    int tribonacci(int n) {

        if(n == 0)return 0;
        else if( n == 1)return 1;
        else if (n == 2)return 1;

        else return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);

    }
};


// memoziation or Top down

class Solution {
public:

    int fn(int n , int dp[]){
        if(n == 0)return 0;
        else if(n == 1)return 1;
        else if(n == 2)return 1;

        if(dp[n] != -1)return dp[n];
        else{
            return dp[n] = fn(n-1,dp) + fn(n-2,dp) + fn(n-3,dp);
        }
    }

    int tribonacci(int n) {

        int dp[n+1];
        for(int i= 0 ; i<=n ; i++)dp[i] = -1;

        return fn(n,dp);

    }
};


// bottom up or Tabulation

class Solution {
public:
    int tribonacci(int n) {

      if(n == 0)return 0;
      else if(n == 1)return 1;
      else if(n == 2)return 1;

      int dp[n+1];
      for(int i = 0 ; i<=n ;i++)dp[i] = -1;

      dp[0] = 0;
      dp[1] = 1;
      dp[2] = 1;

      for(int i = 3 ; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2] +  dp[i-3];
      }

      return dp[n];

    }
};


// space optimization

class Solution {
public:
    int tribonacci(int n) {

      if(n == 0)return 0;
      else if(n == 1)return 1;
      else if(n == 2)return 1;

      int prev = 0;
      int mid = 1;
      int last = 1;

      for(int i = 3 ; i<=n; i++){
        int curr = prev + mid + last;
        prev = mid;
        mid = last;
        last = curr;
      }

      return last;



    }
};
