/*
Input: jobs = [3,2,3], k = 3
Output: 3
Explanation: By assigning each person one job, the maximum time is 3.
*/
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int K) {
        k = K;
        if(k == jobs.size())
            return *max_element(begin(jobs), end(jobs));
        res = accumulate(begin(jobs), end(jobs), 0);
        return dfs(jobs, 0, 0);
    }
private:
    int dfs(vector<int>& jobs, int i, int cur){
        if(cur >= res)
            return res;
        if(i == jobs.size())
            return res = cur;

        unordered_set<int> used;

        for(int w = 0; w < k; w++){

            if(!used.insert(worker[w]).second)
                continue;

            worker[w] += jobs[i];
            dfs(jobs, i+1, max(worker[w], cur));
            worker[w] -= jobs[i];
        }
        return res;
    }
    int res, k;
    int worker[12] = {};
};