class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1 = getVerNumber(version1);
        vector<int> vec2 = getVerNumber(version2);
        int index = 0;
        while (index < vec1.size() && index < vec2.size()) {
            if(vec1[index] > vec2[index]) {
                return 1;
            }
            if (vec1[index] < vec2[index]) {
                return -1;
            }
            index++;
        }
        int maxn = max(vec1.size(),vec2.size());
        if (maxn = vec1.size()) {
            for(int i = index; i < maxn; i++) {
                if(vec1[i] != 0) {
                    return 1;
                }
            }
        }
        if (maxn = vec2.size()) {
            for(int i = index; i < maxn; i++) {
                if(vec2[i] != 0) {
                    return -1;
                }
            }
        }
        return 0;
    }

    vector<int> getVerNumber(string s) {
        vector<int> res;
        int number = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                res.push_back(number);
                number = 0;
                continue;
            }
            else {
                number = number * 10 + s[i] - '0';
            }
            if (i == s.size() - 1) {
                res.push_back(number);
            }
        }
        return res;
    }

    //优化：遍历分割的同时，比较
};
