class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int len = A.size();
        if(len <= 1)
        {
            return len;
        }
        int mx = 0, cur = 0;
        int left = 0, right = 1;
        int sign = -1, new_sign = -1;
        while(sign == -1 && right < len)
        {
            if(A[left] > A[right])    sign = 0;
            else if(A[right] > A[left]) sign = 1;
            else sign = -1, left++, right++;
        }
        new_sign = sign;
        right++;
        while(right < len)
        {
            sign = new_sign;
            if(A[right-1] == A[right])
            {
                cur = right - left;
                mx = max(mx, cur);
                left = right;
                right++;
                continue;
            }
            if(A[right-1] > A[right]) new_sign = 0;
            else    new_sign = 1;
            if(sign == new_sign)
            {
                cur = right - left;
                mx = max(cur, mx);
                left = right-1;
            }

            right++;
        }
        if(sign != new_sign)
        {
            cur = right - left;
            mx = max(cur, mx);
        }
        return mx > 0 ? mx : 1;
    }
};