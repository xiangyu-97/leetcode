# include <stdio.h>
# include <stdlib.h>
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size(), n = num2.size();
        vector<int> ansArr = vector<int>(m + n);
        for (int i = m - 1; i >= 0; i--) {
            int x = num1[i] - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2[j] - '0';
                ansArr[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i > 0; i--) {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        int index = ansArr[0] == 0 ? 1 : 0;
        string ans;
        while (index < m + n) {
            ans.push_back(ansArr[index]);
            index++;
        }
        for (auto &c: ans) {
            c += '0';
        }
        return ans;
    }

    /* long long范围太小，需要用字符串模拟*/
    string multiply2(string num1, string num2) {
        if ( num1[0] < '0' || num1[0] > '9' || num2[0] < '0' || num2[0] > '9') return num1;
        if ( num1[0] == '0') return num1;
        if ( num2[0] == '0') return num2;
        int n1 = num1.size();
        int n2 = num2.size();
        long long ans = 0;
        long long carry = 0;
        long long cur = 0;
        long long high = 1;
        for ( int i = n2 - 1; i >= 0; i-- ) {
            long long mul = pow (10, n2 - i - 1);
            for ( int j = n1 - 1; j >= 0; j-- ) {
                int number1 = num1[j] - '0';
                int number2 = num2[i] - '0';
                cur = ( number1 * number2 ) % 10;
                ans += ( cur + carry ) * mul;
                mul *= 10;
                carry = ( number1 * number2 ) / 10;
            }
            high = mul;
            if ( carry != 0 ) {
                ans += carry * high;
                carry = 0; 
            }
        }
        return to_string(ans);
    }
};
