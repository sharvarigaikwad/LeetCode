class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int len = nums.size();
        if(len == 0 || nums[len-1] > upper)
        {
            if(lower == upper)
            {
                res.push_back(to_string(lower));
            }
            else
            {
                res.push_back(to_string(lower)+"->"+to_string(upper));
            }
            return res;
        }
        if(lower < nums[0])
        {
            if(lower == nums[0]-1)
            {
                res.push_back(to_string(lower));
            }
            else 
            {
                res.push_back(to_string(lower)+"->"+to_string(nums[0]-1));
            }
        }
        int i = 0;
        while(i < len && nums[i] < lower)
        {
            i++;
        }
        int prev = nums[i];
        for(; i < len; i++)
        {
            if(nums[i] > upper)
            {
                break;
            }
            if(nums[i] == prev)
                continue;
            if(nums[i] != prev+1)
            {
                if(nums[i] == prev+2)
                {
                    res.push_back(to_string(prev+1));
                }
                else
                {
                    res.push_back(to_string(prev+1)+"->"+to_string(nums[i]-1));
                }
            }
            prev = nums[i];
        }
        if(nums[i-1] != upper)
        {
            if(nums[i-1]+1 == upper)
            {
                res.push_back(to_string(upper));
            }
            else
            {
                res.push_back(to_string(nums[i-1]+1)+"->"+to_string(upper));
            }
        }
        return res;
    }
};