class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max;
        int len = height.size();
        int max_till = 0;
        for(int i: height)
        {
            if(i > max_till)
            {
                max_till = i;
            }
            left_max.push_back(max_till);
        }
        max_till = 0;
        int i;
        for(i = len - 1; i >= 0 ; i--)
        {
            if(height[i] > max_till)
            {
                max_till = height[i];
            }
            if(left_max[i] > max_till)
            {
                left_max[i] = max_till;
            }
        }
        max_till = 0;
        for(i = 0; i < len; i++)
        {
            max_till += left_max[i] - height[i];
        }
        return max_till;
    }
};