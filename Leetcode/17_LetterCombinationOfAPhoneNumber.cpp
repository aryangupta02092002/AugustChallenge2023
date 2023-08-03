class Solution {
public:
  vector<string> ans;
  vector<string> str ={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  
    void helper(string digits, string s, int i, int sz){
        if(i == sz){
            ans.push_back(s);
            return;
        }
        int idx = digits[i] - '2';
        
        for(int j=0; j<str[idx].size(); j++){
            helper(digits, s + str[idx][j], i+1, sz);
        }
    }
    
    vector<string> letterCombinations(string digits){
        if(digits.size() > 0){
            helper(digits, "", 0, digits.size());
        }
        return ans;
    }
};
