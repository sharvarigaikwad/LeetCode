class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> max_av;
        int cur_pos = 0, add = 0, last_pos = 0, this_max = -1;
        int len = stations.size(), i=0;
        int added = 0;
        stations.push_back({target, 0});
        for(i = 0; i <= len; i++)
        {
            while(!max_av.empty() && startFuel < stations[i][0])
            {
                startFuel += max_av.top();
                max_av.pop();
                added++;
            }
            if(startFuel < stations[i][0]) return -1;
            max_av.push(stations[i][1]);
        }
        return added;
    }
};