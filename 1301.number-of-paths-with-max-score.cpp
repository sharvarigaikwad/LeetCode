class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = 1000000007;
        int rows = board.size();
        vector<vector<pair<long long, long long>>> sum_n_cnt(rows, vector<pair<long long, long long>>(rows, {-1, 1}));
        int i, j;
        long long left, up, up_left, lc, uc, ulc;
        sum_n_cnt[0][0].first = 0;
        for(i = 0; i < rows; i++)
        {
            for(j = (i==0); j < rows; j++)
            {
                if(board[i][j] != 'X')
                {
                    left = -1, up = -1, up_left = -1;
					lc = 0, uc = 0, ulc = 0;
                    if(i > 0)   up = sum_n_cnt[i-1][j].first, uc = sum_n_cnt[i-1][j].second;
                    if(j > 0)   left = sum_n_cnt[i][j-1].first, lc = sum_n_cnt[i][j-1].second;
                    if(i> 0 && j > 0) up_left = sum_n_cnt[i-1][j-1].first, ulc = sum_n_cnt[i-1][j-1].second;
                    if(left == up && left == up_left && left != -1)
                        sum_n_cnt[i][j] = make_pair(left+(board[i][j]-'0'), (lc + uc + ulc)%m);
                    else if(left >= up && left >= up_left && left != -1)
                        sum_n_cnt[i][j] = make_pair(left+(board[i][j]-'0'), (lc+(left == up_left ? ulc : 0) + (left == up ? uc : 0))%m);
                    else if(up >= left && up >= up_left && up != -1)
                        sum_n_cnt[i][j] = make_pair(up+(board[i][j]-'0'), (uc+(up == up_left ? ulc : 0) + (left == up ? lc : 0))%m);
					else if(up_left >= left && up_left >= up && up_left != -1)
						sum_n_cnt[i][j] = make_pair(up_left+(board[i][j]-'0'), (ulc+(up == up_left ? uc : 0) + (left == up_left ? lc : 0))%m);
                }
            }
        }
        if(sum_n_cnt[rows-1][rows-1].first == -1)
        {
            return vector<int>{0, 0};
        }
        return vector<int>{sum_n_cnt[rows-1][rows-1].first-('S'-'0'), sum_n_cnt[rows-1][rows-1].second%m};
    }
};