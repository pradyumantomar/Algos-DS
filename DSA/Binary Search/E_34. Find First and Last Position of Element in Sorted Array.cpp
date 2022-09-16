//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair


class Solution {
public:
    int first(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        while(high>=low){
            int mid = low + (high - low )/2;
            if(nums[mid]==target){
                ans = mid;
                high = mid -1;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }

    int last(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        while(high>=low){
            int mid = low + (high - low )/2;
            if(nums[mid]==target){
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }



    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int low = first(nums,target);
        int high = last(nums,target);

        ans.push_back(low);
        ans.push_back(high);

        return ans;
        
        
    }
};


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	/* int T = 1;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
        ll a[N]={5,7,7,8,8,10};
    
		FOR(i, N)
		cin >> a[i];
        
        Solution obj;
        cout<<obj.searchRange(a,N);
	}*/


	return 0;
}
