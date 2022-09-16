class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>> &ans, int index , vector<int> output){

      int len = nums.size();

      if(index >= len){
        ans.push_back(output);
        return;
      }

      // exclude
      solve(nums, ans, index+1, output);

      // include
      int ele = nums[index];
      output.push_back(ele);
      solve(nums, ans, index+1 , output);


    }


    vector<vector<int>> subsets(vector<int>& nums) {

      vector<vector<int>> ans;

      int len = nums.size();
      if(len == 0 ){
        return ans;
      }

      int index = 0;
      vector<int> output;
      solve(nums, ans, index , output);

      return ans;

    }
};
