class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //sort(nums.begin(), nums.end(), hgreater);
        sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            long long sx = 10 , sy = 10;
            while (sx <= x) {
                sx *= 10;
            }
            while (sy <= y) {
                sy *= 10;
            }
            return x*sy + y > y*sx + x;
        });
        if (nums[0] == 0) {
            return "0";
        }
        string res;
        for(int &x: nums) {
            res += to_string(x); 
        }
        return res;
    }

    static bool hgreater(const int &x, const int &y) {
        long long sx = 10, sy = 10;
        long long rx = x, ry = y;
        while (sx <= x) {
            sx *= 10;
            rx /= 10;
        }
        while (sy <= y) {
            sy *= 10;
            ry /= 10;
        }
        if (rx != ry){
            return rx > ry;
        }
        else if ( sx == 10 || sy == 10 ) {
            return (sx == 10)?hgreater(x, y%10):hgreater(x%10, y);
        }
        else if (sy < sx) {
            return hgreater(x%10, y%10);
        }
        return true;
    }
};
