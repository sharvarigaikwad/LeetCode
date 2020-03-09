class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int st = toBeRemoved[0], end = toBeRemoved[1];
        bool started = false, ended = false;
        vector<vector<int>> res;
        for(auto in: intervals)
        {
            if(ended)
            {
                res.push_back(in);
            }
            else if(!started)
            {
                if(in[1] >= st)
                {
                    started = true;
                    if(in[1] >= end)
                    {
                        ended = true;
                    }
                    if(in[0] < st)
                    {
                        res.push_back({in[0], st});
                    }
                    if(ended && in[1] != end)
                        res.push_back({end > in[0]?end:in[0], in[1]});
                    
                }
                else
                {
                    res.push_back(in);
                }
            }
            else
            {
                if(in[1] >= end)
                {
                    ended = true;
                    res.push_back({end>in[0]?end:in[0], in[1]});
                }
            }
        }
        return res;
    }
};