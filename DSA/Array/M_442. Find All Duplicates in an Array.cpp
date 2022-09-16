// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        map<int,int> mapp;
        for(int i= 0;i<n;i++){
            mapp[nums[i]]++;
        }
        for(auto z : mapp){
            if(z.second >1){
                ans.push_back(z.first);
            }
        }
        return ans;
    }
};