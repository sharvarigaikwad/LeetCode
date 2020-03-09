class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> open_box;
        set<int> needKey;
        for(int b: initialBoxes)
        {   if(status[b])         open_box.push(b);
            else    needKey.insert(b);
        }
        int cand = 0;
        set<int> haveKey, processed;
        while(!open_box.empty())
        {
            int box = open_box.front();
            open_box.pop();
            cand += candies[box];
            processed.insert(box);
            for(int key: keys[box])
            {
                if(needKey.count(key))
                {
                    needKey.erase(key);
                    open_box.push(key);
                }
                else if(status[key] == 0)
                    haveKey.insert(key);
            }
            for(int child: containedBoxes[box])
            {
                if(!processed.count(child))
                {
                    if(status[child] == 1 || haveKey.count(child))
                    {open_box.push(child); haveKey.erase(child);}
                    else
                    {
                        needKey.insert(child);
                    }
                }
            }
        }
        return cand;
    }
};