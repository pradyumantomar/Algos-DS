https://leetcode.com/problems/subsets/

class Solution {
public:

void solve(vector<int> &nums, vector<vector<int>>&ans , int index , vector<int> output ){
        int n = nums.size();
        // base case;
        if(index >= n){
            ans.push_back(output);
            return;
        }

    // exclude
    solve(nums,ans,index + 1,output);

    // include
     int element = nums[index];
     output.push_back(element);
     solve(nums,ans,index + 1,output);




    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n == 0)return ans;

        int index = 0;
        vector<int> output;
        solve(nums,ans,index,output);
        return ans;


    }
};
