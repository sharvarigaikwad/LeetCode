class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string S) {
        map<char, int> pos;
        int len = S.length();
        int K = 2;
        if(len <= K)
            return len;
        int i = 0;
        int min = len;
        char c;
        int prev = 0, max = 0, cur = 0;
        while(i < len)
        {
            pos[S[i]] = i;
            if(pos.size() > K)
            {
                cur = i - prev ;
                if(max < cur)   max = cur;
                min = len;
                for(auto itr = pos.begin(); itr != pos.end(); itr++)
                {
                    if (itr->second < min)  
                    {
                        min = itr->second;
                        c = itr->first;
                    }
                }
                prev = min+1;
                pos.erase(c);
            }
            i++;
        }
        cur = i - prev ;
        if(max < cur)   max = cur;
        return max;
    
    }
};