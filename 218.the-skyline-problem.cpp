class Solution {
public:
    struct build
    {
        int ht, x;
        bool isStart;
        build(int h, int pt, bool st): ht(h), x(pt), isStart(st) {}
        bool operator < (const build & second)
        {
            return x == second.x ? (isStart == second.isStart ? 
                                    !(ht < second.ht == isStart )
                                   : isStart == true) : x < second.x;
        }
    };
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, int> ht_cnt;
        vector<build> eps;
        for(vector<int> b: buildings)
        {
            eps.push_back({b[2], b[0], true});
            eps.push_back({b[2], b[1], false});
        }
        vector<vector<int>> res;
        sort(eps.begin(), eps.end());
        int lastmx = 0, cur_mx;
        for(build b: eps)
        {
            if(b.isStart)
            {
                ht_cnt[b.ht]++;
            }
            else
            {
                ht_cnt[b.ht]--;
                if(ht_cnt[b.ht] == 0)
                    ht_cnt.erase(b.ht);
            }
            if(!ht_cnt.empty())
            {
                cur_mx = ht_cnt.rbegin()->first;
            }
            else
            {
                cur_mx = 0;
            }
            if(cur_mx != lastmx)
            {
                lastmx = cur_mx;
                res.push_back({b.x, lastmx});
            }
        }
        return res;
    }
};