class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len == 0) return 0;
        auto comp = [] (vector<int> a, vector<int> b)
        {
            return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        
        int cnt = 1, mx = intervals[0][1];
        for(int i = 1; i < len;i++)
        {
            if(intervals[i][1] > mx)
            {
                mx = intervals[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};