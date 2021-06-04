/*
Input: servers = [3,3,2], tasks = [1,2,3,2,1,2]
Output: [2,2,0,2,1,2]
Explanation: Events in chronological order go as follows:
- At second 0, task 0 is added and processed using server 2 until second 1.
- At second 1, server 2 becomes free. Task 1 is added and processed using server 2 until second 3.
- At second 2, task 2 is added and processed using server 0 until second 5.
- At second 3, server 2 becomes free. Task 3 is added and processed using server 2 until second 5.
- At second 4, task 4 is added and processed using server 1 until second 5.
- At second 5, all servers become free. Task 5 is added and processed using server 2 until second 7.
*/
// O(m log m + n log n)
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> order;
        int n = servers.size(), m = tasks.size();
        priority_queue<T, vector<T>, greater<T>> free_server_q;
        priority_queue<U, vector<U>, greater<U>> busy_server_q;
        for(int i = 0; i < n; i++){
            free_server_q.push({servers[i], i});
        }
        long time = 0;
        for(int i = 0; i < m; i++){
            time = max(time, (long) i); // update current time
            
            // fast forward to first finished busy server
            if(free_server_q.empty() && busy_server_q.top().first > time){
                time = busy_server_q.top().first;
            }
            
            while(!busy_server_q.empty() && busy_server_q.top().first <= time){
                auto& fs = busy_server_q.top(); // get first busy server
                free_server_q.push({servers[fs.second], fs.second});
                busy_server_q.pop(); // pop busy server
            }
            
            auto& fs = free_server_q.top();// current highest prority free server
            busy_server_q.push({time + tasks[i], fs.second}); // assign jobs
            order.push_back(fs.second); // push index
            free_server_q.pop();
        }
        return order;
    }
private:
    typedef pair<int, int> T;
    typedef pair<long, long> U;
};