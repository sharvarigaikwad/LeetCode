class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int i, j, k, num_i = 0, num_j, num_k, sum, len = nums.size();
        for(i = 0; i < len-1; i++)
        {
            if(i >= 1 && nums[i] == num_i)
            {
                continue;
            }
            num_i = nums[i];
            j = i + 1;
            k = len - 1;
            num_j = nums[j];
            num_k = nums[k];
            while(j < k)
            {
                sum = num_i + num_j + num_k;
                if(sum == 0)
                {
                    result.push_back({{num_i, num_j, num_k}});
                    j++;
                    while(j < len && nums[j] == num_j)
                    {
                        j++;
                    }
                    k--;
                    while(k > i && nums[k] == num_k)
                    {
                        k--;
                    }
                    if(j < len)
                    {num_j = nums[j];}
                    num_k = nums[k];
                }
                else if(sum > 0)
                {
                    k--;
                    while(k > i && nums[k] == num_k)
                    {
                        k--;
                    }
                    num_k = nums[k];
                }
                else
                {
                    j++;
                    while(j < len && nums[j] == num_j)
                    {
                        j++;
                    }
                    if(j < len)
                    {num_j = nums[j];}
                }
            }
        }
        return result;
    }
};