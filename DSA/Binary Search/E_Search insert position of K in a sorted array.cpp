// https://practice.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1/

class Solution{
    public:
    int bs(vector<int> &Arr, int N , int k){
        int low = 0;
        int high = N-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(Arr[mid]==k){
                return mid; 
            }
            else if(Arr[mid]>k){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return high+1;
    }


    int searchInsertK(vector<int>Arr, int N, int k)
    {
        int ans = bs(Arr,N,k);
        return ans;
    }
        
};