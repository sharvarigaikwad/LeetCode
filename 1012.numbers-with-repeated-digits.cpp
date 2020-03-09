class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        vector<int> digits;
        int n = N, doubles = 0;
        map<int, int> dig_cnt;
        while(n)
        {
            digits.push_back(n%10);
            dig_cnt[n%10]++;
            if(dig_cnt[n%10] == 2)doubles++;
            n /= 10;
        }
        int len = digits.size()-1;
        int total = 0;
        
        int i, j, inter = 9;
        if(!doubles) total++;
		if(len) 	total += inter;
        for(i = 2; i <= len; i++)
        {
            inter *= 9-i+2;
            total += inter;
        }
        for(i = 0; i <= len; i++)
        {
            int cur = digits[i];
            digits[i] = 0;
            dig_cnt[cur]--;
            if(dig_cnt[cur] == 0) dig_cnt.erase(cur);
            for(auto d: dig_cnt) {if(d.second == 0)  dig_cnt.erase(d.first);} //unfortunate!
            if(doubles > 0)
            {
                if(dig_cnt[cur] == 1)   doubles--;
                if(doubles>0)continue;
            }
            if(cur == 0) continue;
            int ban = 0;
            for(j = i+1; j <= len; j++)
                if(digits[j] < cur) ban++;
            inter = cur - ban ;
            if(i == len) inter--;
            for(j = 1; j <= i; j++)
                inter *= 10  - dig_cnt.size() - j;
            total += inter;
        }
        return N-total;
    }
};