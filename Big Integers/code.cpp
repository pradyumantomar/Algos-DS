// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

int kthMex(int N, int K, int A[]) {
    
    unordered_set<int> arr;
    for(int i = 0 ; i < N ;i++){
        arr.insert(A[i]);
    }
    
    int count = 0 ;
    int i = 0;
    while(count <= N){
        if(arr.find(i) == arr.end()){
            count++;
        }
        
        i++;
        
        if(count == K){
            break;
        }
    }
    
    return i;
    
    
    
    /*vector<bool> arr(100000 , false);
    for(int i = 0 ; i<N ; i++ ){
        arr[A[i]] = true;
    }
    
    int count = 0;
    int ans = 0;
    while(ans < K and count < K+N){
        if(arr[count] == false){
            ans++;
        }
        count++;
    }
    
    return count-1;
    */
    
}

// { Driver Code Starts.

// Driver code
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif	
    int t;
    //cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        int ans = kthMex(n, k, arr);
        cout << ans << "\n";
    }

    return 0;
}
  // } Driver Code Ends
/*
int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif	

	int tc = 1;
	//cin >> tc;
	while(tc--){
		solve();
		cout<<endl;
	}

	return 0;
}
*/