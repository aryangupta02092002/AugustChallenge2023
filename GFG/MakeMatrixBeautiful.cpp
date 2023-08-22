//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > mat, int n)
    {
        // code here 
        int ans = 0;
        int mx = 0;
        vector<int> row(n, 0);
        vector<int> col(n, 0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }
        
        for(int i=0; i<n; i++){
            mx = max(max(row[i], col[i]), mx);
        }
        for(int i=0; i<n; i++){
            ans += mx - row[i];
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
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends
