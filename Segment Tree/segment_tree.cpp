#include<bits/stdc++.h>
using namespace std;

struct segment_tree{
    int n;
    vector<int> st;

    void init(int _n){
        this->n = _n;
        st.resize(4*n,0);
    }

    void build_helper(int start, int end,int node, vector<int> &arr){

        // base case
        if(start == end){
            st[node] = arr[start];
            return;
        }

        int mid = (start + end)/2;

        // left subtree
        build_helper(start, mid, 2 * node + 1, arr);

        // right subtree
        build_helper(mid + 1 , end , 2 * node + 2, arr);

        st[node] = st[2 * node  + 1] + st[2 * node + 2 ];
        
    }

    void build(vector<int> &arr){
        build_helper(0,n-1,0,arr);
    }

    int query(int l , int r){
        return query_helper(0,n-1,l,r,0);
    }

    int query_helper(int start, int end, int l, int r, int node){
        // no overlapping
        if(start > r or end < l){
            return 0;
        }

        // complete overlap
        if(start >= l && end <= r){
            return st[node];
        }

        // partial overlap

        int mid = (start + end)/2;
        int q1 = query_helper(start,mid,l,r,2 * node + 1);
        int q2 = query_helper(mid + 1 , end,l,r,2 * node + 2);

        return (q1 +q2);
    }

    void update(int index, int value ){
        update_helper(0,n-1,0,index,value);
    }

    void update_helper(int start, int end, int node, int index,int value){
        // base case
        if(start == end){
            st[node] = value;
            return;
        }

        int mid = (start + end)/2;
        
        if(index <=  mid){
            update_helper(start,mid,2 * node  + 1,index,value);
        }
        else{
            update_helper(mid + 1,end,2 * node + 2 ,index,value);
        }

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    } 


};

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    int n = arr.size();

    segment_tree tree;
    tree.init(n);
    tree.build(arr);

    cout<<tree.query(0, 1)<<endl;
    cout<<tree.query(0, 2)<<endl;
    cout<<tree.query(0, 3)<<endl;
    cout<<tree.query(0, 4)<<endl;
    cout<<tree.query(0, 5)<<endl;
    cout<<tree.query(0, 6)<<endl;
    cout<<tree.query(0, 7)<<endl;
    cout<<tree.query(1, 1)<<endl;
    cout<<tree.query(2, 4)<<endl;
    cout<<tree.query(5, 7)<<endl;

    for(auto it : tree.st)cout<<it<<" ";
    cout<<endl;

    tree.update(1,5);

    // cout<<tree.query(0, 1)<<endl;
    // cout<<tree.query(0, 2)<<endl;
    // cout<<tree.query(0, 3)<<endl;
    // cout<<tree.query(0, 4)<<endl;
    // cout<<tree.query(0, 5)<<endl;
    // cout<<tree.query(0, 6)<<endl;
    // cout<<tree.query(0, 7)<<endl;
    // cout<<tree.query(1, 1)<<endl;
    // cout<<tree.query(2, 4)<<endl;
    // cout<<tree.query(5, 7)<<endl;

    for(auto it : tree.st)cout<<it<<" ";
    cout<<endl;


   
   



}