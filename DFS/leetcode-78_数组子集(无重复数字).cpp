class Solution {
public:
    vector<int> subres;
    vector<vector<int>> res;

    void dfs(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            res.push_back(subres);
            return;
        }
        subres.push_back(nums[cur]);
        dfs(cur + 1, nums);
        subres.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};
