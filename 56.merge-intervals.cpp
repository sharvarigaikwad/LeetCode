class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int len = intervals.size(), i;
        if(len == 0) return res;
        int st = intervals[0][0], end = intervals[0][1];
        for(i = 0; i < len; i++)
        {
            if(intervals[i][0] > end)
            {
                res.push_back({st, end});
                st = intervals[i][0];
            }
            end = max(end, intervals[i][1]);
        }
        res.push_back({st, end});
        return res;
    }
};