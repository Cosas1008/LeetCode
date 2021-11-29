/*
You are given an integer n indicating there are n people numbered from 0 to n - 1. 
You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. 
A person may attend multiple meetings at the same time. 
Finally, you are given an integer firstPerson.

Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
Output: [0,1,2,3,5]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 5, person 1 shares the secret with person 2.
At time 8, person 2 shares the secret with person 3.
At time 10, person 1 shares the secret with person 5.​​​​
Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
*/
class Solution {
public:
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // 1. Create the graph
        vector<vector<pair<int,int>>> graph(n);
        for(int i = 0; i < meetings.size(); ++i){
            graph[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
            graph[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});
        }
        // 2. priority_queue
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, firstPerson}); // {time, person}
        pq.push({0, 0});

        vector<bool> ack(n, false);
        vector<int> ans;

        while(pq.size()){
            pair<int,int> cur = pq.top(); pq.pop();
            int person = cur.second;
            int time   = cur.first;
            if(ack[person]) continue; // this person has already shared secret
            ack[person] = true;
            for(auto g : graph[person]){
                if(!ack[g.first] && time <= g.second)
                    pq.push({g.second, g.first});
            }
        }
        for(int i = 0; i < n; ++i)
            if(ack[i]) ans.emplace_back(i);
        return ans;
    }
    // Wrong Answer
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        priority_queue<vector<int>> pq;
        vector<bool> ack(n, false);
        for(auto meeting : meetings){
            pq.push({-1*meeting[2]*(1+meeting[0]), meeting[0], meeting[1]});
        }
        ack[0] = ack[firstPerson] = true;
        while(pq.size()){
            vector<int> tp = pq.top(); pq.pop();
            int p1 = tp[1], p2 = tp[2];
            if(ack[p1] || ack[p2]) ack[p1] = ack[p2] = true;
        }
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            if(ack[i]) ans.push_back(i);
        }
        return ans;
    }
};