class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> highs, lows;
        int len = prices.size(), i, j;
        if(len == 0)
            return 0;
        int dir = -1;
        for(i = 1; i < len; i++)
        {
            if(prices[i] > prices[i-1] && dir == -1)
            {lows.push_back(prices[i-1]), dir = 1;}
            else if(prices[i] < prices[i-1] && dir == 1)
            {highs.push_back(prices[i-1]), dir = -1;}
        }
        if(lows.size() > highs.size())
            highs.push_back(prices[len-1]);
        int max_till = prices[len-1], max_prof = 0;
        len = lows.size();
        if(len == 0)
            return 0;
        vector<int> maxes(len, 0), profits(len, 0);
        maxes[len-1] = highs[len-1];
        for(i = len-2; i>= 0; i--)
        {
            maxes[i] = max(maxes[i+1], highs[i]);
        }
        for(i = len-1; i >=0; i--)
        {
            profits[i] = maxes[i] - lows[i];
            max_prof = max(max_prof, profits[i]);
            int local_max  = highs[i];
            for(j = i+1; j < len; j++)
            {
                local_max = max(local_max, highs[j-1]);
                max_prof = max(max_prof, local_max - lows[i] + profits[j]);
            }
        }
        return max_prof;
    }
};