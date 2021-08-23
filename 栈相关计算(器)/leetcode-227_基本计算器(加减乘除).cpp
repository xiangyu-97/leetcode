class Solution {
public:
    int calculate(string s) {
        if(s.empty())   return 0;
        vector<int> tmp;
        int num = 0, sum = 0;
        char sign = '+';
        s.push_back('+');       //补上一个+号让最后的数字加入到tmp中
        for(char ch : s)
        {
            if(ch == ' ')   continue;       //1.处理空格
            else if(ch >= '0' && ch <= '9')  num = num * 10 + (ch - '0');  //2.处理当前数字
            else    //3.处理符号
            {
                if(sign == '+')         tmp.push_back(num);   //sign是上一个运算符，先完成上一次运算
                else if(sign == '-')    tmp.push_back(-num);
                else if(sign == '*')    tmp.back() *= num;
                else if(sign == '/')    tmp.back() /= num;
                sign = ch;  //更新记录新的运算符
                num = 0;
            }
        }
        for(int n : tmp)    sum += n;
        return sum;
    }
};
