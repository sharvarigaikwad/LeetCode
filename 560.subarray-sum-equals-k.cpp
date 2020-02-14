class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size(), i, j;
        if(len < 1)
        {
            return len;
        }
        int sums[len], res = 0;
        sums[0] = nums[0];
        for(i = 1; i < len; i++)
        {
            sums[i] = sums[i-1] + nums[i];
        }
        for(i = 0; i < len; i++)
        {
            for(j = i; j < len; j++)
            {
                if(sums[j] - (i > 0 ? sums[i-1] : 0) == k)
                {
                    res++;
                }
            }
        }
        return res;
    }
};