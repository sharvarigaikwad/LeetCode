class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1)
        {
            return true;
        }
        int val[len][len], i, j, k;
        for(i = 0; i < len ; i++)
        {
            val[i][i] = nums[i];
        }
        for(k = 1; k < len ; k++)
        {
            for(i = 0; i < len - k; i++)
            {
                j = i + k;
                val[i][j] = max(val[i][i]-val[i+1][j], val[j][j]-val[i][j-1]);
            }
        }
        if(val[0][len-1] >= 0)
        {
            return true;
        }
        return false;
    }
};