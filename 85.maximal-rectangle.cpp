class Solution {
public:
    int getMaxRectangle(vector<int> &row)
    {
        int max = 0, area, topidx, i;
        stack<int> least_indices;
        least_indices.push(0);
        if(row.size() == 1)
        {
            return row[0];
        }
        for(i = 1; i < row.size(); i++)
        {
            if(least_indices.empty() || row[i] >= row[least_indices.top()])
            {
                least_indices.push(i);
            }
            else
            {
                while(!least_indices.empty() && row[least_indices.top()] > row[i])
                {
                    topidx = least_indices.top();
                    least_indices.pop();
                    if(!least_indices.empty())
                    {
                        area = (i - least_indices.top() - 1) * row[topidx];
                    }
                    else
                    {
                        area = (i) * row[topidx];
                    }
                    if(area > max)
                    {
                        max = area;
                    }
                }
                least_indices.push(i);
            }
        }
        while(!least_indices.empty())
        {
            topidx = least_indices.top();
            least_indices.pop();
            if(!least_indices.empty())
            {
                area = (i - least_indices.top() - 1) * row[topidx];
            }
            else
            {
                area = (i) * row[topidx];
            }
            if(area > max)
            {
                max = area;
            }
        }
        return max;
    }
    int getMaxRectangleHelper(vector<int> row)
    {
        vector<int> positives;
        int max = 0, ret;
        for(int i: row)
        {
            if(i != 0)
            {
                positives.push_back(i);
            }
            else
            {
                if(!positives.empty())
                {
                    ret = getMaxRectangle(positives);
                    if(ret > max)
                    {
                        max= ret;
                    }
                    positives.clear();
                }
            }
        }
        return max;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)
        {
            return 0;
        }
        int cols = matrix[0].size();
        if(cols == 0)
        {
            return 0;
        }
        vector<int> cur_row(cols, 0);
        int max_rect = 0, cur_max = 0;
        for(auto next_row: matrix)
        {
            for(int i = 0; i < cols; i++)
            {
                if(next_row[i] == '1')
                {
                    cur_row[i] = cur_row[i] + 1;
                }
                else
                {
                    cur_row[i] = 0;
                }
            }
            cur_max = getMaxRectangle(cur_row);
            if(cur_max > max_rect)
            {
                max_rect = cur_max;
            }
        }
        return max_rect;
    }
};