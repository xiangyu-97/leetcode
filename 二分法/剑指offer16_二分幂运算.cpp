class Solution {
public:
    double myPow(double x, long n) {
        double ans = 1;
        bool negative = n < 0; //记录是否为负
        if (negative) {
            n = -n;
        }
        while( n > 0)
        {
            if( n % 2 == 1) {
                ans *= x;
            }
            x *= x;
            n /= 2;
        }
        if (negative) {
            ans= 1 / ans;
        }
        return ans;
    }
};
