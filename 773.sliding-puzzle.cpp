class Solution {
public:
    struct Node
    {
        int x, y, dist, pos;
        Node(int x0, int y0, int d, int p) : x(x0), y(y0), dist(d), pos(p){}
    };
    int slidingPuzzle(vector<vector<int>>& board) {
        int end = 123450;
        int st = 0;
        int i, j, cur, dist, x0 = -1, y0 = -1;
        set<int> visited;
        queue<Node> q;
        for(i = 0; i < 2; i++)
        {
            for(j = 0; j < 3; j++)
            {
                st = st*10 + board[i][j];
                if(board[i][j] == 0)
                {
                    x0 = i, y0 = j;
                }
            }
        }
        Node n(x0, y0, 0, st);
        q.push(n);
        visited.insert(st);
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        while(!q.empty())
        {
            Node t = q.front();
            q.pop();
            dist = t.dist;
            cur = t.pos;
            if(cur == end) return dist;
            for(i = 0; i < 4; i++)
            {
                int nx = t.x+dx[i], ny = t.y+dy[i];
                if(nx >= 0 && nx < 2 && ny >= 0 && ny < 3)
                {
                    int npos = cur;
                    int c0 = 5 - (t.x*3) - t.y, n0 = 5 - (nx*3) - ny;
                    int digit_to_flip = int(cur / pow(10, n0)) % 10;
                    npos -= pow(10, n0) * digit_to_flip;
                    npos += digit_to_flip * pow(10, c0);
                    if(!visited.count(npos))
                    {
                        visited.insert(npos); 
                        q.push({nx, ny, dist+1, npos});
                    }
                }
            }
        }
        return -1;
    }
};