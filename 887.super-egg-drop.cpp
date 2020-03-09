Traditional- TLE:
class Solution {
public:
    int superEggDrop(int K, int N) {
        int arr[K+1][N+1];
        int i, j, k, min;
        for(j = 1; j <= N; j++)
            arr[0][j] = 0, arr[1][j] = j;
        for(i = 0; i <= K ; i++)
            arr[i][0] = 0;
        for(i = 2; i <= K; i++)
        {
            for(j = 1; j <= N; j++)
            {
                if(j < i)
                {
                    arr[i][j] = arr[i-1][j];
                    continue;
                }
                min = arr[i-1][j];
                for(k = 1; k < j; k++)
                {
                    min = std::min(min, 
                        std::max(arr[i-1][k-1], arr[i][j-k]));
                }
                arr[i][j] = min+1;
                cout << "i: " << i << ", j: " << j << "= " << arr[i][j] << endl;
            }
        }
        return arr[K][N];
    }
};

Mathematical approach-
class Solution {
public:
    int superEggDrop(int K, int N) {
        int lo = 1, hi = N, mid;
        while(lo < hi)
        {
            mid = (lo + hi) / 2;
            if(f(mid, K, N) < N)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
    int f(int x, int k, int n)
    {
        int ans = 0, r = 1; 
        //r is sum of tCi | 1<i<K 
        // t is number of tries = x 
        for(int i = 1; i <= k; i++)
        {
            r *= x-i+1;
            r /= i;
            ans += r;
            if(ans >= n ) break;
        }
        return ans;
    }
}