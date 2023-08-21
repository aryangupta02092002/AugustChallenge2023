class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int sz = s.size();
        for(int i=1; i<=sz/2; i++){
            if(sz % i == 0){
                string substr = s.substr(0, i);
                string rep = "";
                for(int j=0; j<sz/i; j++){
                    rep += substr;
                }
                if(rep == s){
                    return true;
                }
            }
        }
        return false;
    }
};
