class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> num_sums;
        int sum = 0, len = nums.size(), minimum_len = len, prev_len = 0, val_to_find, i;
        for (i: nums)
        {
            sum+=i;
            num_sums.push_back(sum);
        }
        for (i = 0; i < len-1; i++)
        {
            if(nums[i] >= s) 
			{
				return 1;
			}
            val_to_find = num_sums[i] + s - nums[i];
            if(num_sums[len - 1] < val_to_find) 
			{
				continue;
			}
            if(num_sums[prev_len] <= val_to_find)
            {
                while (num_sums[prev_len] < val_to_find) 
				{
					prev_len++;
				}
            }
            else if(num_sums[prev_len] > val_to_find)
            {
                while(num_sums[prev_len] > val_to_find) 
				{
					prev_len--;
				}
            }
            if(minimum_len > prev_len - i + 1)
			{
                minimum_len = prev_len - i + 1;
			}
        }
        if (len && nums[len - 1] >= s) 
		{
			return 1;
		}
        if (len && minimum_len == len && num_sums[len - 1] < s) 
		{
			return 0;
		}
        return minimum_len;
    }
};