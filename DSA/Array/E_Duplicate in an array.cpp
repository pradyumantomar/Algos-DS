// https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397

int findDuplicate(vector<int> &arr) 
{
    int n = arr.size();
    int ans =  0 ;

    for(int i = 0 ; i<n;i++){
        ans=ans^arr[i];
    }

    for (int i = 1; i <= n-1; i++)
    {
        ans = ans^i;
    }
    
    return ans;
	
}
