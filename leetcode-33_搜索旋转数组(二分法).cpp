class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = 0;
        int n = nums.size();     
        if ( n == 1 ) {
            if ( target == nums[0]) {
                return 0;
            }
            else {
                return -1;
            }
        } 
        int l = 0;
        int r = n - 1;
        // 等号
        while (l <= r) {
            int mid = (l + r) /2 ;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[l] <= nums[mid]) {
            // nums[0] <= target
                if (nums[l] <= target && nums[mid] > target) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && nums[r] >= target) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
