class Solution {
public:
    string combination;
    vector<string> combinations;
    vector<string> permutation(string s) {
        sort(s.begin(),s.end()); //相同字母序号相邻
        vector<bool> visited(s.size(),false);
        dfs(s,0,visited);
        return combinations;
    }

    void dfs(string s, int index, vector<bool>& visited) {
        if (index == s.size()) {
            combinations.push_back(combination);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            // 判断上一个相同字母是否使用（未使用则证明已经回溯过）
            if (visited[i] || (i > 0 && !visited[i-1] && s[i] == s[i-1])) {
                continue;
            }
            visited[i] = true;
            combination.push_back(s[i]);
            dfs(s,index+1,visited);
            combination.pop_back();
            visited[i] = false;
        }
        return; 
    }
};
