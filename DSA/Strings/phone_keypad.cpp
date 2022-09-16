void solve(string s, vector<string> &ans, int index, string output , vector<string> &mapping){

  // fill on overflow
  int len = s.length();
  if(index >= len){
    ans.push_back(output);
  }

  //  find which index word needed
  int number = s[index] - '0';
  string word = mapping[number];
  for(int i = 0 ; i< mapping[number].length();i++ ){


      output.push_back(word[i]);
      solve(s, ans, index + 1, output, mapping);

      // backtracking
      output.pop_back();
  }

}


vector<string> combinations(string s){

	vector<string> ans;
  int len = s.length();
  if(len == 0){
    return ans;
  }

  string output;
  int index = 0;

  // create map for words
  vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs" , "tuv", "wxyz"};
  solve(s, ans , index, output , mapping);
  return ans;
}
