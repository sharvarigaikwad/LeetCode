class Solution {
public:
    int len;
    void get(vector<vector<int>>books, int sw, int w, int i, vector<vector<int>> &dp)
    {
        if(dp[w][i] != 1000000000)  return;
        int ht = books[i][1], cur_w = w, i2 = i;
        while(i2 < len && books[i2][1] <= ht && cur_w + books[i2][0] <= sw)
        {
            cur_w += books[i2][0];
            i2++;
        }
        if(i2 == len)
        {
            dp[w][i] = ht;
            return;
        }
        if(sw - cur_w >= books[i2][0])
            get(books, sw, cur_w, i2, dp);
        get(books, sw, 0, i2, dp);
        dp[w][i] = min(dp[cur_w][i2], dp[0][i2]+ht);
        
    }
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        len = books.size();
        vector<vector<int>> dp(shelf_width+1, vector<int>(len, 1000000000));
        if(len == 0) return len;
        int ht = books[0][1], cur_w = 0;
        get(books, shelf_width, 0, 0, dp);
        return dp[0][0];
    }
};