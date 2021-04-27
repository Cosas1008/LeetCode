// Time: O(NlogN)
// Space: O(N)
class Solution {
    typedef pair<int, int> T; // processing time, index
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<T, vector<T>, greater<>> pq;
        long n = tasks.size();
        long time = 0;
        long i = 0; // read pointer
        for (int i = 0; i < n; ++i) tasks[i].push_back(i); // add index to each task
        sort(begin(tasks), end(tasks));
        vector<int> enqueue_order;
        while(i < n || pq.size()){
            if (pq.empty()) {
                time = max(time, (long)tasks[i][0]); // nothing in the heap? try updating the current time using the processing time of the next task in array
            }
            while (i < n && time >= tasks[i][0]) { // push all the tasks in the array whose enqueueTime <= currentTime into the heap
                pq.emplace(tasks[i][1], tasks[i][2]);
                ++i;
            }
            auto [pro, index] = pq.top();
            pq.pop();
            time += pro; // handle this task and increase the current time by the processingTime
            enqueue_order.push_back(index);
        }
        return enqueue_order;
    }
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