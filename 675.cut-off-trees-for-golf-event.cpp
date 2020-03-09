class Solution {
    private: int m, n;
public:
    struct node{
        int hdist, dist, x, y;
        node(int h, int d, int x0, int y0) : hdist(h), dist(d), x(x0), y(y0){}
        bool operator<(const node &b) const
        {
            return hdist == b.hdist? dist > b.dist : hdist > b.hdist;
        }
    };
    int dist(vector<vector<int>>& forest, int &sx, int &sy, int ex, int ey, int ht)
    {
        priority_queue<node> min_heap;
        min_heap.push(node(abs(sx-ex)+abs(sy-ey), 0, sx, sy));
        set<int> visited;
        visited.insert(sx*100+sy);
        vector<int> dx = {0, 0, 1, -1};//, 1, 1, -1, -1};
        vector<int> dy = {1, -1, 0, 0};//, 1, -1, 1, -1};
        while(!min_heap.empty())
        {
            node cur_n = min_heap.top();
            min_heap.pop();
            int d = cur_n.dist + 1;
            
            if(cur_n.x == ex && cur_n.y == ey)
            {
                return d - 1;
            }
            for(int i = 0; i < dx.size(); i++)
            {
                int nx = cur_n.x+dx[i], ny = cur_n.y+dy[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && forest[nx][ny] != 0  && visited.count(nx*100+ny) == 0)
                {
                    visited.insert(nx*100+ny);
                    min_heap.push(node(abs(nx-ex)+abs(ny-ey)+d, d, nx, ny));
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        map<int, int> treepos;
        m = forest.size();
        if(!m) return 0;
        n = forest[0].size();
        int i, j;
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                if(forest[i][j] != 0) {
                    treepos[forest[i][j]] = i*100+j; 
                }  
        int cur_x = 0, cur_y = 0;
        int next_x = 0, next_y = 0;
        int count = 0;
        for(auto ent: treepos)
        {
            next_x = ent.second/100;
            next_y = ent.second%100;
            int res = dist(forest, cur_x, cur_y, next_x, next_y, ent.first);
            if(res == -1) return res;
            count += res;
            cur_x = next_x, cur_y = next_y;
        }
        return count;
    }
};