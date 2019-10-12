class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        int sum = m + n, i, gcd;
        int denom = 1, nom = 1;
        if(n > m)
        {
            int temp = m;
            m = n;
            n = temp;
        }
        int smaller_end = sum - n + 1;
        for(i = 2; i <= n; i++)
        {
            denom *= i;
        }
        for(i = sum; i >= smaller_end && denom > 1; i--)
        {
            gcd = __gcd(i, denom);
            denom /= gcd;
            nom *= (i / gcd);
        }
        for(; i >= smaller_end; i--)
        {
            nom *= i;
        }
        return nom;
    }
};