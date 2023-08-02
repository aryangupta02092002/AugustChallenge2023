class Solution {
public:
    void helper(vector<int> &tmp, vector<int> &nums, vector<vector<int>> &ans, int freq[]){
        if(tmp.size() == nums.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!freq[i]){
                tmp.push_back(nums[i]);
                freq[i] = 1;
                helper(tmp, nums, ans, freq);
                freq[i] = 0;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int freq[nums.size()];
        for(int i=0; i<nums.size(); i++){
            freq[i] = 0;
        }
        helper(tmp, nums, ans, freq);
        return ans;
    }
};
