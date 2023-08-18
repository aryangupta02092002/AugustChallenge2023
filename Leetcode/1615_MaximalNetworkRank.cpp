class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        set<pair<int, int>> s;

        for(auto &road : roads){
            deg[road[0]]++;
            deg[road[1]]++;
            s.insert({road[0], road[1]});
            s.insert({road[1], road[0]});
        }

        int mx = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int rank = deg[i] + deg[j];
                if(s.find({i, j}) != s.end()){
                    rank--;
                }
                mx = max(mx, rank);
            }
        }
        return mx;
    }
};
