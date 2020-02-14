class Solution {
public:
    void mark_island(vector<vector<int>>& A, int i, int j, int mark, set<int> &s)
    {
        int rows = A.size(), cols = A[0].size();
        int nr, nc;
        vector<vector<int>> dirs{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int cnt = 0;
        for(vector<int> k : dirs)
        {
            nr = i + k[0];
            nc = j + k[1];
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols)
            {
                if(A[nr][nc] == 1)
                {
                    s.insert(100*nr + nc);
                    A[nr][nc] = mark;
                    mark_island(A, nr, nc, mark, s);
                    cnt++;
                }
                else if(A[nr][nc] == -1)
                    cnt++;
            }
        }
        if(cnt == 4)
        {
            A[i][j] = -1;
            s.erase(s.find((100*i) + j));
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        set<int> set_a, set_b;
        int rows = A.size();
        if(!rows)
        {
            return 0;
        }
        int cols = A[0].size(), i, j;
        for(i = 0; i < rows; i++)
        {
            for(j = 0 ; j < cols; j++)
            {
                if(A[i][j] == 1)
                {
                    
                    if(set_a.empty())
                    {
                        
                        set_a.insert(100*i + j);
                        A[i][j] = 'a';
                        mark_island(A, i, j, 10, set_a);
                    }
                    else
                    {
                        
                        set_b.insert(100*i + j);
                        A[i][j] = 'b';
                        mark_island(A, i, j, 20, set_b);
                    }
                }
            }
        }
        int ra, ca, min = INT_MAX, dist;
        set<int>::iterator ia, ib;
        for(ia = set_a.begin(); ia!= set_a.end(); ia++)
        {
            ra = (*ia) / 100;
            ca = (*ia) % 100;
            for(ib = set_b.begin(); ib != set_b.end(); ib++)
            {
                dist = abs(ra - ((*ib) / 100)) + abs(ca - ((*ib) % 100));
                if(dist < min)
                {
                    min = dist;
                }
            }
        }
        return min-1;
    }
};