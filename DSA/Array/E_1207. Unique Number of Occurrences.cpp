//https://leetcode.com/problems/unique-number-of-occurrences/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int , int> umap;
        
        int n = arr.size();
        
        for(int i = 0 ;i<n;i++){
            umap[arr[i]]++;
        }
       
        set<int> s;
        for(auto x : umap){
            s.insert(x.second);
        }
        
        if(s.size()!=umap.size()){
            return false;
        }
        else{
            return true;
        }
            
            
    }
};