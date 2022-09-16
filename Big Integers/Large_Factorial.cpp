#include<bits/stdc++.h>
using namespace std;

void multiply(vector<int> &arr, int no , int &size){

	int carry = 0;
	for(int i = 0 ; i < size ; i++ ){
		int product = carry + arr[i] * no;

		arr[i] = product%10;
		carry = product/10;
	}

	while(carry != 0  ){
		arr[size] = carry%10;
		carry = carry/10;
		size++; 
	}

}


void factorial(int n){

	vector<int> arr(1000 , 0);
	arr[0] = 1 ;
	int size = 1;

	for (int i = 2; i <= n; ++i)
	{
		multiply(arr , i , size);
	}

	for (int i = size - 1 ; i>=0 ;i--)
	{
		cout<<arr[i];
	}

}


void solve(){
	int n;
	cin>>n;

	factorial(n);
	
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif	

	int tc = 1;
	cin >> tc;
	while(tc--){
		solve();
		cout<<endl;
	}

	return 0;
}