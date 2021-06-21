class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if ( n < 3 ) return -1;
        if ( n == 3 ) return nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        int best = 1e7;
        for(int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = n - 1;
            while ( j < k && j < n && k > i ) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                }
                else if (sum > target) {
                    best = update(sum, best, target);
                    k--;
                }
                else {
                    best = update(sum, best, target);
                    j++;
                }
            }
        }
        return best;
    }

    int update(int cur, int best, int target) {
        if (abs(target - best) > abs(target - cur)) {
            return cur;
        }
        return best;
        }
};
