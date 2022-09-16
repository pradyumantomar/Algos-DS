#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
    bool isPossible(int arr[], int n, int m, int min)
{
    int students = 1;
    int sum = 0;
 
    for (int i = 0; i < n; i++) {
        if (arr[i] > min)
            return false;
 
        
        if (sum + arr[i] > min) {
            students++;
 
            sum = arr[i];
 
            if (students > m)
                return false;
        }
 
        else
            sum += arr[i];
    }
    return true;
}

    int findPages(int arr[], int n, int m)
{
    int sum = 0;
 
    if (n < m)
        return -1;
 
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    
    int start = 0, end = sum;
    int result = INT_MAX;
 
    while (start <= end) {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid)) {
            result = mid;
 
            end = mid - 1;
        }
 
        else
            start = mid + 1;
    }
 
    return result;
}
 
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
 