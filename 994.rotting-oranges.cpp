class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0)
        {
            return 0;
        }
        int cols = grid[0].size();
        if(cols == 0)
        {
            return 0;
        }
        int max_time = 0, time = 0;
        vector<int> time_lapse(cols*rows, -1);
        int fresh_ones = 0;
        queue<int> rotten;
        int i, j, place, new_place;
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    fresh_ones++;
                }
                else if(grid[i][j] == 2)
                {
                    time_lapse[i*cols + j] = 0;
                    rotten.push(i*cols+j);
                }
            }
        }
        vector<vector<int>> dirs{{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!rotten.empty() && fresh_ones > 0)
        {
            place = rotten.front();
            rotten.pop();
            i = place / cols;
            j = place % cols;
            time = time_lapse[place] + 1;
            for(auto ch: dirs)
            {
                int new_i = i+ch[0], new_j = j+ch[1];
                new_place = (i+ch[0])*cols + j+ch[1];
                if(new_i >= 0 && new_i < rows && new_j >= 0 && new_j < cols && grid[new_i][new_j] == 1 && time_lapse[new_place] == -1)
                {
                    time_lapse[new_place] = time;
                    max_time = max(max_time, time);
                    fresh_ones--;
                    rotten.push(new_place);
                }
            }
        }
        if(fresh_ones > 0)
        {
            return -1;
        }
        return max_time;
    }
};