class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length(), plen = p.length();
        if(plen == 0)
        {
            if(slen == 0)
                return true;
            return false;
        }
        if(slen == 0 && p!="*")
        {
            return false;
        }
        bool dp[slen+1][plen+1];
        int i, j;
        dp[0][0] = true;
        for(i = 1; i <= slen; i++)
            dp[i][0] = false;
        for(j = 1; j <= plen; j++)
            dp[0][j] = false;
        int jstart = 1;
        while(p[jstart-1] == '*')
        {
            for(i = 0; i <= slen; i++)
                dp[i][jstart] = true;
            jstart++;
        }
        for(i = 1 ; i <= slen; i++)
        {
            for(j = jstart; j <= plen; j++)
            {
                if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1];
                }
                else if(s[i-1] == p[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '?')
                {
                    dp[i][j] =  dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
        return dp[slen][plen];
    }
};