class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int dlen = D.size();
        vector<int> digits;
        int n = N;
        while(n)
        {
            digits.push_back(n%10);
            n /= 10;
        }
        int count = 0, nlen = digits.size(), i;
        int p = 1;
        vector<int> smaller(11, 0);
        i = 0;
        if(nlen == 0) return 0;
        int j = 1;
        while(i < dlen)
        {
            while(j < D[i][0]-'0') 
            {
				smaller[j] = smaller[j-1]; 
				j++;
			}
            smaller[j] = smaller[j-1]+1;
            j++, i++;
        }
        while(j < 11) {
			smaller[j] = smaller[j-1];
			j++;
		}

        for(i = 0; i < nlen-1; i++)
        {
            p *= dlen;
            count += p;
        }

        for(i = nlen-1; i >= 0 && digits[i]; i-- )
        {
            count += smaller[digits[i]-(i>0)] * pow(dlen, i);
            if(smaller[digits[i]] == smaller[digits[i]-1]) break;
        }
        return count;
    }
};