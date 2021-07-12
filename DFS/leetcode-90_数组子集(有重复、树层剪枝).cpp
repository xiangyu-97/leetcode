class Solution {
public:
    vector<vector<int>> res;
    vector<int> subres;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        sort(nums.begin(),nums.end());
        backtrace(false, nums, 0, n);
        return res;
    }

    void backtrace(bool choosePre, vector<int>& nums, int index, int n) {
        if (index == n) {
            res.push_back(subres);
            return;
        }
        backtrace(false,nums,index+1,n);      
        if (!choosePre && index > 0 && nums[index] == nums[index-1]) {
            return;
        }
        subres.push_back(nums[index]);
        backtrace(true,nums,index+1,n);
        subres.pop_back();    
        return;
    }
};
