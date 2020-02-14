/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    struct point
    {
        int time;
        bool isStart;
        point(int t, bool st) : time(t), isStart(st){}
        bool operator < (const point&rhs)
        {
            return time < rhs.time;
        }
    };
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        vector<point> times;
        int len = schedule.size();
        if(len <= 1)
        {
            return res;
        }
        int i, last_st = INT_MAX, cnt = 0;
        for(i = 0; i < len; i++)
        {
            for(auto sch: schedule[i])
            {
                times.push_back(point(sch.start, true));
                times.push_back(point(sch.end, false));
            }
        }
        sort(times.begin(), times.end());
        len = times.size();
        for(i = 0; i < len; i++)
        {
            if(cnt == 0 && last_st != INT_MAX)
            {
                if(last_st != times[i].time)
                    res.push_back(Interval(last_st, times[i].time));
                last_st = INT_MAX;
            }
            if(times[i].isStart == true)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            if(cnt == 0)
            {
                last_st = times[i].time;
            }
        }
        return res;
    }
};
};