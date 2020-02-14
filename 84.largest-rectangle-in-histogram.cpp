class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        int i = 0, top = -1, max = 0, cur = -1;
        stack<int> smaller;
        for(i = 0; i < len; i++)
        {
            if(smaller.empty() || heights[smaller.top()] <= heights[i])
            {
                smaller.push(i);
                continue;
            }
            while(!smaller.empty() && heights[smaller.top()] > heights[i])
            {
                top = smaller.top();
                smaller.pop();
                if(smaller.empty())
                {
                    cur = heights[top] * i;
                }
                else
                {
                    cur = heights[top] * (i - smaller.top() - 1);
                }
                if(cur > max)
                {
                    max = cur;
                }
            }
            smaller.push(i);
        }
        while(!smaller.empty())
        {
            top = smaller.top();
            smaller.pop();
            if(smaller.empty())
            {
                cur = heights[top] * i;
            }
            else
            {
                cur = heights[top]* (i - smaller.top() - 1);
            }
            if(cur > max)
            {
                max = cur;
            }
        }
        return max;
    }
};