#include<iostream>
#include<algorithm>
using namespace std;


string add(string s1 , string s2){
	if(s1.length() > s2.length()){
		swap(s1,s2);
	}

	string ans = "";
	int carry = 0;
	for(int i = 0 ; i < s1.length() ; i++){
		int d1 = s1[i] - '0';
		int d2 = s2[i] - '0';
		int sum = d1 + d2 + carry ;
		int lastDigit = sum%10;
		carry = sum/10;
		char input = lastDigit + '0';
		ans.push_back(input);
	}

	for(int i = s1.length(); i < s2.length() ; i++){
		int d1 = s2[i] -'0';
		int sum = carry + d1;
		int lastDigit = sum%10;
		carry = sum/10;
		ans.push_back(lastDigit + '0');
	}

	if(carry != 0){
		ans.push_back(carry + '0');
	}
	return ans;
}


void solve(){
	string s1,s2;
	cin>>s1>>s2;

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	string ans = add(s1,s2);

	reverse(ans.begin() , ans.end());
	
	cout<<ans;

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
}