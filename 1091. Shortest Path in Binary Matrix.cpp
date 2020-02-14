class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
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
        if(grid[0][0] != 0 || grid[rows-1][cols-1] != 0)
        {
            return -1;
        }
        if(rows == 1 && cols == 1)
        {
            return 1;
        }
        pair<int, int> point;
        queue<pair<int, int>> path;
        path.push(make_pair(0,0));
        grid[0][0] = 1;
        vector<vector<int>> dirs{{-1,0}, {0, -1}, {1, 0}, {0, 1},
                                 {-1,-1}, {-1, 1}, {1,-1}, {1,1}};
        while(!path.empty())
        {
            point = path.front();
            path.pop();
            for(vector<int> dir : dirs)
            {
                int new_x = point.first + dir[0];
                int new_y = point.second + dir[1];
                if(new_x == rows-1 && new_y == cols-1)
                {
                    return  grid[point.first][point.second] + 1;
                }
                if(new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols && grid[new_x][new_y] == 0)
                {
                    path.push(make_pair(new_x, new_y));
                    grid[new_x][new_y] = grid[point.first][point.second] + 1;
                }
            }
        }
        return -1;
    }
};