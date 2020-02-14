class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.length(), left = 0, right = 0;
        int cur_cost = 0, mxlen = 0;
        while(right < len)
        {
            cur_cost += abs(s[right] - t[right]);
            if(cur_cost > maxCost)
            {
                mxlen = max(mxlen, right - left);
                cur_cost -= abs(s[left]-t[left]);
                left++;
            }
            right++;
        }
        if(cur_cost <= maxCost)
        {
            mxlen = max(mxlen, right - left);
        }
        return mxlen;
    }
};