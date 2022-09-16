//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long > ans;
        stack<long long> s;
        
        
        
        for(long long i = n-1 ; i >= 0 ;i--){
            // if empty push -1
            if(s.empty()){
                ans.push_back(-1);
            }
            // if greater at top push top 
            else if(!s.empty() and s.top() > arr[i]){
                ans.push_back(s.top());
            }
            // if smaller at the top 
            else if(!s.empty() and s.top() <= arr[i]){
                
                //  pop untill greater comes or stack become empty
                while(!s.empty() and s.top()<= arr[i]){
                    s.pop();
                }
                

                // if stack is not empty push the top
                if(!s.empty()){
                    ans.push_back(s.top());
                }

                // if stack is empty no greater ele so push -1
                else{
                    ans.push_back(-1);
                }
                
            }
            s.push(arr[i]);
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends