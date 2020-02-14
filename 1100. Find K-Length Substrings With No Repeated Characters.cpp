class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        map<char, int> pos;
        int len = S.length();
        if(len < K)
            return 0;
        int i = 0;
        int min = len;
        char c;
        int prev = 0, max = 0, cur = 0;
        while(i < len)
        {
            pos[S[i]]++;
            if(i+1 >= K)
            {
                if(pos.size() == K)
                    max++;
                
                if(pos[S[i+1-K]] == 1)
                {
                    pos.erase(S[i+1-K]);
                }
                else 
                {
                    pos[S[i+1-K]]--;
                }
            }
            i++;
        }
        if(pos.size() == K)
            max++;
        return max;
    }
};