
#include<bits/stdc++.h>
using namespace std;


class Solution
{
  public:
    string reverseWords (string s)
    {
       string ans = "";
       stack<char> st;
       int len = s.length();
       for (size_t i = len-1; i >= 0; i--)
       {
        st.push(s[i]);
       }

       while (!st.empty())
       {
        ans.push_back(st.top());
        st.pop();
       }

       return ans;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}
