//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void helper(int i, vector<string> &ans, string s){
        if(i==0){
            ans.push_back(s);
        }
        for(int idx=i; idx>=0; idx--){
            swap(s[i], s[idx]);
            helper(i-1, ans, s);
            swap(s[i], s[idx]);
        }
    
    }
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        helper(S.size()-1, ans, S);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends
