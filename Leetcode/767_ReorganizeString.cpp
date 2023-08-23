class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> u;
        for(char c : s){
            u[c]++;
        }

        priority_queue<pair<int, char>> mxHeap;
        for(auto &[ch, freq] : u){
            mxHeap.push({freq, ch});
        }

        string ans;
        while(mxHeap.size() >= 2){
            auto [f1, c1] = mxHeap.top();
            mxHeap.pop();

            auto [f2, c2] = mxHeap.top();
            mxHeap.pop();

            ans += c1;
            ans += c2;

            if(--f1 > 0){
                mxHeap.push({f1, c1});
            }
            if(--f2 > 0){
                mxHeap.push({f2, c2});
            }
        }

        if(!mxHeap.empty()){
            auto [freq, ch] = mxHeap.top();
            if(freq > 1){
                return "";
            }
            ans += ch;
        }
        return ans;
    }
};
