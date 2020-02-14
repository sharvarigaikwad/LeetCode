class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int len = arr.size();
        map<int, vector<int>> possible_jumps;
        vector<bool> visited(len, false);
        queue<int> pos;
        unordered_set<int> zeros;
        if(len < 1)
            return false;
        if(len == 1 && start == 0 && arr[0] == 0)
        {
            return true;
        }
        int i, val;
        for(i = 0; i < len; i++)
        {
            val = arr[i];
            if(val == 0)
            {
                if(start == i)
                    return true;
                pos.push(i);
                visited[i] = true;
                //cout << "pushed " << i << "to q\n";
                continue;
            }
            if(i-val >= 0)
            {
                possible_jumps[i-val].push_back(i);
            }
            if(i+val < len)
            {
                possible_jumps[i+val].push_back(i);
            }
        }
        vector<int> jumps;
        while(!pos.empty())
        {
            
            val = pos.front();
            pos.pop();
            jumps = possible_jumps[val];
            for(i = 0 ; i < jumps.size(); i++)
            {
                if(jumps[i] == start)
                {
                    return true;
                }
                if(!visited[jumps[i]])
                {
                    //cout << jumps[i] << "adding to q\n";
                    visited[jumps[i]] = true;
                    pos.push(jumps[i]);
                }
            }
        }
        return false;
    }
};