class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1)
            return 0;
        vector<int> min_till(len, len+1);
        int i, j;
        i = 0;
        int cnt = 0;
        while(i < len)
        {
            if(i + nums[i] >= len -1)
            {
                cnt++;
                break;
            }
            int mx = 0, mxi = -1;
            for(j = i+1; j < len && j <= i+ nums[i]; j++)
            {
                if(j + nums[j] >= mx)
                {
                    mx = j+nums[j];
                    mxi = j;
                }
            }
            i = mxi;
            cnt++;
        }
        return cnt;
    }
};