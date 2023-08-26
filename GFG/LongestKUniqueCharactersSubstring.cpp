//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int ans = -1;
        int n = s.size();
        unordered_map<char, int> mp;
        unordered_set<char> st;
        int i = 0;
        
        for(i=0; i<n && st.size()<=k; i++){
            st.insert(s[i]);
            mp[s[i]]++;
        }
        
        if(st.size()<k)
            return -1;
        else if(st.size()==k)
            return n;
        else{
            i--;
            mp[s[i]]--;
            st.erase(st.find(s[i]));
        }
        
        ans = max(ans, i);
        int count = ans, j = 0;
        
        while(i<n && j<n){
            if(mp[s[j]] == 1){
                st.erase(st.find(s[j]));
                count--;
                while(st.size()<=k && i<n){
                    st.insert(s[i]);
                    mp[s[i]]++;
                    i++;
                    count++;
                }
                
                if(st.size()>k){
                    i--;
                    mp[s[i]]--;
                    st.erase(st.find(s[i]));
                }
                else{
                    return max(ans, count);
                }
            }
            mp[s[j]]--;
            j++;
            count--;
            ans = max(ans, count);
        }
        ans = max(ans, count);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
