class Solution {
public:
    int minArray(vector<int>& numbers) {
        //二分搜索
        int n = numbers.size();
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = (l + r)>>1;
            if (numbers[mid] < numbers[r]) {
                r = mid - 1;
            }
            else if (numbers[mid] > numbers[r]) {
                l = mid + 1;
            }
            else {
                r -= 1;
            }
        }
        return numbers[l];
    }
};
