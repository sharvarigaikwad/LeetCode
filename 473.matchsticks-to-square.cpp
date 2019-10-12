class Solution {
public:
    bool checkIfPossible(vector<int> nums, int side, int start, int sums[4], vector<int> sel[4])
    {
        if(start == nums.size())
        {
            if(sums[0] == side && sums[1] == side && sums[2] == side && sums[3] == side)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int i;
        for(i = 0; i < 4; i++)
        {
            if(nums[start] + sums[i] <= side)
            {
                sel[i].push_back(nums[start]);
                sums[i] += nums[start];
                if(checkIfPossible(nums, side, start+1, sums, sel))
                    return true;
                sel[i].pop_back();
                sums[i] -= nums[start];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        int len = nums.size();
        if(len < 4)
        {
            return false;
        }
        int sum = 0, i, j = 0, side;
        for(int i : nums)
        {
            sum += i;
        }
        if(sum % 4 != 0)
        {
            return false;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        side = sum / 4;
        if(nums[len - 1] > side)
        {
            return false;
        }
        
        int arr[4] = {};
        vector<int> selection[4];
        return checkIfPossible(nums, side, 0, arr, selection);
    }
};