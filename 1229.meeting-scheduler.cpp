class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int len1 = slots1.size(), len2 = slots2.size();
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
		vector<vector<vector<int>>> sl(2);
		sl[0] = move(slots1);
		sl[1] = move(slots2);
		int ptr[] = {0, 0}, diff;
		int p1, p2;
        while(ptr[0] < len1 && ptr[1] < len2)
        {
			p1 = sl[0][ptr[0]][0] > sl[1][ptr[1]][0] ? 0 : 1;
			p2 = p1^1;
			if(sl[p2][ptr[p2]][1] > sl[p1][ptr[p1]][0])
			{
				if(min(sl[p1][ptr[p1]][1], sl[p2][ptr[p2]][1]) - sl[p1][ptr[p1]][0] >= duration)
				{
					return vector<int> {sl[p1][ptr[p1]][0], sl[p1][ptr[p1]][0]+duration};
				}
				if (sl[p2][ptr[p2]][1] > sl[p1][ptr[p1]][1])	ptr[p1]++;
				else	ptr[p2]++;
			}
			else
			{
				ptr[p2]++;
			}
        }
        return vector<int>{};
    }
};