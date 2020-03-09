class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        vector<set<int>> all(len);
        all[1] = set<int>{1};
        if(len == 0 || stones[1] != 1)
            return false;
        for(int i = 1; i < len; i++)
        {
            set<int> cur = all[i];
            if(cur.size())
            {
                int last = *cur.rbegin();
                for(int j = i+1; j < len && stones[j] < stones[i]+last+2 ; j++)
                {
                    int diff = stones[j] - stones[i];
                    if(cur.count(diff) || cur.count(diff+1) || cur.count(diff-1))
                    {
                        all[j].insert(diff);
                    }
                }
                }
        }
        return all[len-1].size() > 0;
    }
};