class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n) {
            n &= n - 1;  //使得最低位的1被翻转
            ret++;
        }
        return ret;
    }
};

