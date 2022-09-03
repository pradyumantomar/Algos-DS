https://leetcode.com/problems/climbing-stairs/

//Recursion Solution.. (This will give TLE)

int solve(int n){
        if(n < 0) return 0;
        if(n == 0) return 1;

        int ans = 0;

        ans += solve(n-1)+solve(n-2);
        return ans;
    }

//Recursion + Memoisation Solution (100% Faster)

int solve(int n, vector<int>& dp){
        if(n < 0) return 0;
        if(n == 0) return 1;

        if(dp[n] != -1) return dp[n];

        int ans = 0;

        ans += solve(n-1,dp)+solve(n-2,dp);
        return dp[n] = ans;

    }
//Bottom-up Approach (Tabulation)
int solve1(int n){
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        if(n >= 2) dp[2] = 2;

        for(int i=3;i<=n;i++){
            int ans;
            ans = dp[i-1]+dp[i-2];
            dp[i] = ans;
        }
        return dp[n];

    }
//Space Optimization
//-> This solution only depends on previous 2 values so we can take 3 variables and solve it so time complexity is O(n) and Space is O(1)

int solve2(int n){
    int first = 1;
    int second = 2;
    int current;
    if(n <= 2) return n;
    for(int i=3;i<=n;i++){
        current = second + first;
        first = second;
        second = current;
    }
    return second;
	}
