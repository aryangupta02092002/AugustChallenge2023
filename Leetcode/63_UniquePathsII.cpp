class Solution {
public:
    int count = 0;
    int helper(int i, int j, vector<vector<int>> &g, vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=g.size() || j>=g[0].size() || g[i][j] == 1){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i==g.size()-1 && j==g[0].size()-1){
            return 1;
        }
        return dp[i][j] = helper(i+1, j, g, dp) + helper(i, j+1, g, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return helper(0, 0, obstacleGrid, dp);
    }
};
