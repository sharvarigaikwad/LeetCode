class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int len = customers.size();
        if(len < 1)
            return len;
        int already_sat = 0, mx = 0;
        int cur_wd = 0, left = 0, right = 0;

        while(right < len)
        {
            if(right >= X)
            {
                if(grumpy[left])
                {
                    cur_wd -= customers[left];
                }
                left++;
            }
            if(grumpy[right])
            {
                cur_wd += customers[right];
            }
            else
            {
                already_sat += customers[right];
            }
            right++;
            mx = max(mx, cur_wd);
        }
        return mx+already_sat;
    }
};