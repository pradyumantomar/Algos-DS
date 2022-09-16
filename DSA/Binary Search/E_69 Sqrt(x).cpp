// https://leetcode.com/problems/sqrtx/

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
    int mySqrt(int x) {
        
        if(x==0){
            return 0;
        }
        
        
        int low = 1;
        int high = x;
        int ans = 1;

        while(low <= high ){
            int mid = low + (high -low)/2;
            if(mid == x/mid){            // to prevent overflow of int  .. can be => mid*mid = x
                ans = mid;
                return ans;
            }
            else if(mid < x/mid){           // same overflow
                ans = mid;
                low = mid+1; 
            }
            else{
                high = mid-1;
            }
        }
        return ans;
        
    }
};



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	//cin >> T;
	while (T--) {
		int N;
		cin >> N;
		/*
        ll a[N];
		FOR(i, N)
		cin >> a[i];
        */
        Solution obj;
        cout<<obj.mySqrt(N);
	}


	return 0;
}



