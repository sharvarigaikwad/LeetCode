class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long long> a(2), e(2), i(2), o(2), u(2);
        a[0] = 1, e[0] = 1, i[0] = 1, o[0] = 1, u[0] = 1;
        int m = 1000000007;
        int itr = 1, old_itr = 0;
        for(int it = 2; it <= n; it++)
        {
            a[itr] = e[old_itr] % m;
            e[itr] = (a[old_itr] + i[old_itr]) % m;
            i[itr] = (a[old_itr] + e[old_itr] + o[old_itr] + u[old_itr]) % m;
            o[itr] = (i[old_itr] + u[old_itr]) % m;
            u[itr] = a[old_itr] % m;
            itr ^= 1;
            old_itr ^= 1;
        }
        return (a[old_itr]+e[old_itr]+o[old_itr]+i[old_itr]+u[old_itr])%m;
    }
};