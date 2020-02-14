class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size(), prev_st = -1;
        if(len <= 1)    return len;
        int pos[256], cur, mx = 0, sm = 0;
        for(int i = 0; i < 256; i++)
            pos[i] = -1;
        for(int i = 0; i < len; i++)
        {
            cur = s[i]-'\0';
            if (pos[cur] != -1 && pos[cur] >= prev_st)
            {
                sm = i - prev_st;
                if(prev_st == -1)
                {
                    sm--;
                }
                prev_st = pos[cur] + 1;
                mx = max(mx, sm);
            }
            pos[cur] = i;
        }
        if(prev_st < len - 1)
        {
            sm = len - prev_st;
            if(prev_st == -1)
            {
                sm--;
            }
            mx = max(mx, sm);
        }
        return mx;
    }
};