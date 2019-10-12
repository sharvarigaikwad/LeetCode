class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        struct job{
            int difficulty, profit;
            job (int d, int p) : difficulty(d), profit(p) {}
        };
        vector<job> jobs;
        int i, j = 0, total_work = 0, prev_max = 0, prev_top = 0, least_diff = 0;
        vector<int>::iterator itr;
        for(i = 0; i < profit.size(); i++)
        {
            jobs.push_back({difficulty[i], profit[i]});
        }
        auto comp = [] (job a, job b) {if(a.difficulty == b.difficulty) return a.profit < b.profit; return a.difficulty < b.difficulty;};
        sort(jobs.begin(), jobs.end(), comp);
        
        for(i = 1; i < jobs.size(); i++)
        {
            if(jobs[i].profit < jobs[i - 1].profit)
                jobs[i].profit = jobs[i - 1].profit;
        }
        sort(worker.begin(), worker.end());
        j = 0;
        for(i = 0; i < worker.size(); i++)
        {
            while(j < jobs.size() && jobs[j].difficulty <= worker[i])
            {
                j++;
            }
            if(j > 0)
            {
                total_work += jobs[j - 1].profit;
            }
        }
        return total_work;
    }
};