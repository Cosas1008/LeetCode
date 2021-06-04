/*
Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
Explanation: The events go as follows: 
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.
*/
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<T, vector<T>, greater<>> pq;
        vector<int> enqueue_order;
        int n = tasks.size();
        long time = 0;
        for(int i = 0; i < n; i++){
            tasks[i].push_back(i); // push index
        }
        sort(tasks.begin(), tasks.end(), [](const vector<int> & a, const vector<int> & b){ return a[0] < b[0];});
        int i = 0;
        while(i < n || !pq.empty()){
            if(pq.empty()){
                time = max(time, (long)tasks[i][0]);
            }
            while(i < n && time >= tasks[i][0]){
                pq.emplace(tasks[i][1], tasks[i][2]);
                i++;
            }
            auto [pro, idx] = pq.top();
            pq.pop();
            time += pro;
            enqueue_order.push_back(idx);
        }
        return enqueue_order;
    }
private:
    typedef pair<int, int> T; // processing time, index
};


// Op2
vector<int> getOrder(vector<vector<int>>& tasks) {
    vector<int> res, idx(tasks.size());
    priority_queue<pair<int, int>> pq;
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int i, int j) { return tasks[i][0] < tasks[j][0]; });
    for (long i = 0, time = 1; i < idx.size() || !pq.empty();) {
        for (; i < idx.size() && tasks[idx[i]][0] <= time; ++i)
            pq.push({-tasks[idx[i]][1], -idx[i]});
        if (!pq.empty()) {
            auto [procTime, j] = pq.top(); pq.pop();
            time -= procTime;
            res.push_back(-j);
        }
        else
            time = tasks[idx[i]][0];
    }
    return res;
}