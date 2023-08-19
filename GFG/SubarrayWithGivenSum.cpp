//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        int start = 0, end = 0;
        long long sum = 0;
        int left = 0, right = 0;
        vector<int> ans;
        
        while(end < n){
            sum += arr[end];
            
            while(sum > s && start < end){
                sum -= arr[start];
                start++;
            }
            
            if(sum == s){
                left = start+1;
                right = end+1;
                break;
            }
            end++;
        }
        if(left == 0 && right == 0){
            ans.push_back(-1);
        }
        else{
            ans.push_back(left);
            ans.push_back(right);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
