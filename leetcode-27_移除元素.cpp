class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if ( n == 0 ) return 0;
        int preIndex = 0;
        int curIndex = 0;
        while ( preIndex < n ) {
            if (nums[preIndex] != val) {
                nums[curIndex] = nums[preIndex];
                curIndex++;
            }
            preIndex++;            
        }
        nums.resize(curIndex);
        return curIndex;
    }
};
