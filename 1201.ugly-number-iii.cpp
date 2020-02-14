class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        if(n == 0)
        {
            return 0;
        }
        priority_queue<int> max_heap;
        int small, mid, large, multiple;
        int small_mid = 0, small_large = 0, mid_large = 0, all_3 = 0;
        int count_to_remove, min_inserted, i, last_val, cur_val;
        if(a <= b && a <=c)
        {
            small = a;
            mid = b < c ? b : c;
            large = b < c ? c : b;
        }
        else if(b <=a && b <=c)
        {
            small = b;
            mid = a < c ? a : c;
            large = a < c ? c : a;
        }
        else if(c <=a && c <=a)
        {
            small = c;
            mid = a < b ? a : b;
            large = a < b ? b : a;
        }
        if(large % small == 0)
        {
            large = 0;
        }
        if(mid % small == 0)
        {
            mid = 0;
        }
        if(mid && large && large % mid == 0)
        {
            large = 0;
        }
        double upper_bound = small * n;
        int count_mid = 0, count_large = 0;
        if(mid && mid < upper_bound)
        {
            multiple = lcm(small, mid);
            small_mid = upper_bound/multiple;
            count_mid = upper_bound/mid;
        }
        if(large && large < upper_bound)
        {
            multiple = lcm(small, large);
            small_large = upper_bound/multiple;
            count_large = upper_bound/large;
            if(mid && count_large * gcd(mid, large) >= mid)
            {
                multiple = lcm(mid, large);
                mid_large = upper_bound/multiple;
                if(mid_large >= small)
                {
                    multiple = lcm(multiple,small);
                    all_3 = upper_bound / multiple;
                }
            }
        }
        count_to_remove = count_mid + count_large - (small_mid + small_large + mid_large - all_3);
        if(count_to_remove == 0)
        {
            return upper_bound;
        }
        for(i = 0; i <= count_to_remove; i++)
        {
            max_heap.push(int(upper_bound));
            upper_bound -= small;
        }
        min_inserted = upper_bound;
        upper_bound = mid * count_mid;
        while(upper_bound > min_inserted)
        {
            max_heap.push(int(upper_bound));
            upper_bound -= mid;
        }
        max_heap.push(int(upper_bound));
        min_inserted = upper_bound;
        upper_bound = large * count_large;
        while(upper_bound > min_inserted)
        {
            max_heap.push(int(upper_bound));
            upper_bound -= large;
        }
        max_heap.push(int(upper_bound));
        i = 0;
        last_val = max_heap.top() + 1;
        while(i <= count_to_remove)
        {
            cur_val = max_heap.top();
            max_heap.pop();
            if(cur_val != last_val)
            {
                i++;
                last_val = cur_val;
            }
        }
        return cur_val;
    }
};