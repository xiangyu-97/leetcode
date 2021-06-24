class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        intervals.resize(intervals.size() + 1);
        int index = intervals.size() - 1;
        int hasInsert = 0;
        for (int i = intervals.size() -2 ; i >= 0; i--) {
            if (newInterval[0] < intervals[i][0]) {
                intervals[index--] = intervals[i];
            }
            else {
                if (hasInsert == 0) {
                    intervals[index--] = newInterval;
                    hasInsert = 1;
                }
                continue;
            }
            if ( i== 0 && hasInsert == 0) {
                intervals[i] = newInterval;
                break;
            }
        }
        return mergeIntervls(intervals);
    }

    vector<vector<int>> mergeIntervls(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;
        int head = intervals[0][0];
        int tail = intervals[0][1];
        vector<vector<int>> mergedIntervls;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > tail) {
                mergedIntervls.push_back({head,tail});         
                head = intervals[i][0];
                tail = intervals[i][1];
            }
            else {
                tail = max(tail, intervals[i][1]);
            }
        }
        mergedIntervls.push_back({head,tail});
        return mergedIntervls;
    }
};
