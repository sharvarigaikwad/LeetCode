class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int i, sum, max_sum=0, max_sum_start=-1, j;
        if(len==0) return "";
        else if(len ==1 ) return s;

        for(i = 1; i < len; i++)
        {
            if (s[i] == s[i-1])
            {
                sum=2;
                j=1;
                while( (i-1-j) >= 0 && (i+j) < len && s[i-1-j] == s[i+j])
                {
                    j++; sum+=2;
                }
                if(sum > max_sum){
                    max_sum = sum;
                    max_sum_start = (i-j);
                }
            }
            sum = 1;
            j=1;
            while ( (i-j) >= 0 && (i+j) < len && s[i-j] == s[i+j])
            {
                j++; sum+=2;
            }
            if(sum > max_sum)
            {
                max_sum = sum;
                max_sum_start = i-j+1;
            }
        }
        return s.substr(max_sum_start,max_sum);
    }
};