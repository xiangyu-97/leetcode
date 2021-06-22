class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0];
        vector<int> maxSum(n,0);
        int ans = nums[0];
        maxSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxSum[i] = nums[i] + max(maxSum[i - 1], 0);
            ans = max(ans, maxSum[i]);
        }
        return ans;
    }
    
    /*存在缺陷，前缀和最大值小于0？*/
    int maxSubArray2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0];
        vector<int> preixSum(n+1);
        preixSum[0] = 0;
        for (int i = 1; i <= n; i++) {
            preixSum[i] = preixSum[i - 1] + nums[i - 1];
        }
        sort(preixSum.begin(),preixSum.end());
        return preixSum[n] - preixSum[0];
    }
};
