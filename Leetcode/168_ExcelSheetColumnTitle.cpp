class Solution {
public:
    string convertToTitle(int colNum) {
        if(colNum < 27){
            return string(1, 'A' + (colNum-1) % 26);
        }
        string ans = "";
        while(colNum > 0){
            if(colNum % 26 == 0){
                ans += 'A' + 25;
                colNum -= 1;
            }
            else{
                ans += 'A' + (colNum % 26) - 1;
            }
            colNum /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
