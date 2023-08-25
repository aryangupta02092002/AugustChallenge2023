class Solution {
public:
    bool foo(string s1, string s2, string s3, int n1, int n2, int n3, vector<vector<int>> &dp){
        if(n1<0 && n2<0 && n3<0){
            return true;
        }
        if(n1>=0 && n2>=0 && dp[n1][n2] != -1){
            return dp[n1][n2];
        }
        if(n1>=0 && s1[n1] == s3[n3] && n2>=0 && s2[n2] == s3[n3]){
            return dp[n1][n2] = (foo(s1, s2, s3, n1-1, n2, n3-1, dp) || foo(s1, s2, s3, n1, n2-1, n3-1, dp));
            
        }
        else if(n1>=0 && s1[n1] == s3[n3]){
            return foo(s1, s2, s3, n1-1, n2, n3-1, dp);
        } 
        else if(n2>=0 && s2[n2] == s3[n3]){
            return foo(s1, s2, s3, n1, n2-1, n3-1, dp);
        }
        else{
            return false;
        }
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() < s1.size() + s2.size()){
            return false;
        }
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return foo(s1, s2, s3, s1.size()-1, s2.size()-1, s3.size()-1, dp);
    }
};
