https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// recursion
int solve(vector<int> &num, int x){
    if(x == 0)return 0;
    else if(x < 0)return INT_MAX;

    int mn = INT_MAX;
    for(auto it : num){
        int ans = solve(num, x - it);

        if(ans != INT_MAX)
        mn = min(mn , 1 + ans );
    }

    return mn;
}

int minimumElements(vector<int> &num, int x)
{
    int ans = solve(num,x);
    if(ans == INT_MAX)ans =-1;
    return ans;
    // Write your code here.
}


// memoziation
int solve(vector<int> &num, int x , vector<int> &dp){
    if(x == 0)return 0;
    else if(x < 0)return INT_MAX;

    if (dp[x] != -1)return dp[x];
    else {
        int mn = INT_MAX;

        for(auto it : num){
            int ans = solve(num, x - it, dp);

            if(ans != INT_MAX){
                mn = min(mn , 1 + ans);
            }
        }
        dp[x] = mn;
        return dp[x];
    }

}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<int> dp(x+1 , -1);
    int ans = solve(num,x,dp);
    if(ans == INT_MAX)ans =-1;
    return ans;
    // Write your code here.
}

// Bottom UP

int solve(vector<int> &num, int x ){
    vector<int> dp(x+1 , INT_MAX);

    dp[0] = 0;

    for(int i = 1 ; i<=x ; i++){
      for(auto it : num){
        if(i - it >= 0 and dp[i - it] != INT_MAX)
        dp[i] = min(dp[i] , 1 + dp[i - it]);
      }
    }

    if(dp[x] == INT_MAX)dp[x] = -1;
    return dp[x];

}

int minimumElements(vector<int> &num, int x)
{
    int ans = solve(num, x);
    return ans;
    // Write your code here.
}
