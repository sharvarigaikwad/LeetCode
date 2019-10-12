class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> min_heap;
        min_heap.push(1);
        min_heap.push(2);
        min_heap.push(3);
        min_heap.push(5);
        long long int popped = 0, prev = 0;
        while(n > 0)
        {
            popped = min_heap.top();
            min_heap.pop();
            if(popped == prev)
            {
                n++;
            }
            else
            {
                prev = popped;
                min_heap.push(popped*2);
                min_heap.push(popped*3);
                min_heap.push(popped*5);
            }
            n--;
        }
        return popped;
    }
};