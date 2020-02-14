class Solution {
public:
    int longestValidParentheses(string s) {
        int lastInv = -1, res = 0, stk = 0, cur;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')
            {
                stk++;
            }
            else if(s[i] == ')')
            {
                stk--;
            }
            if(stk == 0)
            {
                cur = i - lastInv;
                res = max(res, cur);
            }
            else if(stk < 0)
            {
                stk = 0;
                lastInv = i;
            }
        }
        stk = 0;
        lastInv = len;
        for(int i = len-1 ; i >= 0; i--)
        {
            if(s[i] == ')')
            {
                stk++;
            }
            else if(s[i] == '(')
            {
                stk--;
            }
            if(stk == 0)
            {
                cur = lastInv - i;
                res = max(res, cur);
            }
            else if(stk < 0)
            {
                stk = 0;
                lastInv = i;
            }
        }
        return res;
    }
};