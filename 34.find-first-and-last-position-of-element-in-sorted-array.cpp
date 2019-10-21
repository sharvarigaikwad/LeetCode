class Solution {
public:
    int findExtreme(vector<int>& nums, int target, int index, int direction)
    {
        int i = index;
        while( i >= 0 && i < nums.size() && nums[i] == target)
        {
            i += direction;
        }
        return i-= direction;
    }
    vector<int> findStartEnd(vector<int>& nums, int target, int start, int end)
    {
        int mid;
        if(start <= end)
        {
            mid = start + (end - start) / 2;
            if(nums[mid] > target)
            {
                return findStartEnd(nums, target, start, mid - 1);
            }
            else if(nums[mid] < target)
            {
                return findStartEnd(nums, target, mid + 1, end);
            }
            else
            {
                return vector({findExtreme(nums, target, mid, -1), findExtreme(nums, target, mid, 1)});
            }
        }
        return vector({-1, -1});
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return findStartEnd(nums, target, 0, nums.size() - 1);
    }
};