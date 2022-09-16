void solve(string s, vector<string> &ans , int index , string output){
  int len = s.length();
  if(index >=  len){

      // if null set  we wont include it
      if(output.size() == 0) return;

      ans.push_back(output);
      return;
  }

    // exclude
  solve(s, ans, index + 1 , output);

   // include
  char c = s[index];
  output.push_back(c);
  solve(s, ans, index + 1 , output);

}

vector<string> subsequences(string str){

  vector<string> ans;
  int len = str.length();
  if(len == 0){
    return ans;
  }

  int index = 0;
  string output = "";
  solve(str, ans , index , output);

  return ans;
    // Write your code here

}
