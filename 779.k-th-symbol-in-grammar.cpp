class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1 || N == 0)    return 0;
        if(N == 2)  return K-1;
        if(K <= pow(2, N-2))
        {
            return kthGrammar(N-1, K);
        }
        return !kthGrammar(N-1, K-pow(2, N-2));
    }
};