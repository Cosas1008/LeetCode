/*
Every worker can be assigned at most one job, but one job can be completed multiple times.
Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
*/
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // greedily chose job from list
        int res = 0, money = 0, idx = 0, n = difficulty.size();
        vector<pair<int,int>> jobs;
        for(int i = 0; i < n; ++i)
            jobs.emplace_back(difficulty[i], profit[i]);
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        for(auto work : worker){
            while(idx < n && jobs[idx].first <= work)
                money = max(money, jobs[idx++].second);
            res += money;
        }
        return res;
    }
};