class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n < 64)
        {
            unsigned long long int hash = 0;
            for(int i : nums)
            {
                if(hash & (1L << i))
                    return i;
                hash = hash | (1L << i);
            }
            return 0;
        }
        else
        {
            int size =(n / 64) + 1;
            unsigned long long int hash[size] = {0};
            for(int i : nums)
            {
                int index = (i / 64);
                int inner_index = i - (int(i / 64) * 64);
                if(hash[index] & (1L << inner_index))
				{
                    return i;
				}
                hash[index] |= (1L << inner_index);
            }
        }
        return 0;
    }
};