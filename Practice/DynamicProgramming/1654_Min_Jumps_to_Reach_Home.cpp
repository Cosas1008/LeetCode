/*
Hint: 1 <= forbidden.length <= 1000, 1 <= a, b, forbidden[i] <= 2000
1. from 0 to x
2. cannot jump backward twice in a row
3. cannot jump to forbidden positions
4. can jump exact a forward, b backward
*/
class Solution {
public:
    // BFS Space O(N)
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int cur = 0, step = 0;
        queue<pair<int, bool>> q;
        unordered_set<int> visited;
        for(auto forbi : forbidden)
            visited.insert(forbi), visited.insert(-forbi); // pos: forwarding , neg: backwarding
        q.emplace(0, true); // true : backward
        while(!q.empty()){
            int n = q.size();
            while(n){
                n--;
                auto [ cur, backward ] = q.front(); q.pop();
                int key = (backward)? cur : -cur; // if cannot go backward, turn to neg
                if(cur > 6000 || cur < 0 || visited.count(key)) continue;
                if(cur == x) return step;
                // cout << cur << " : " << step << endl;
                visited.insert(key);
                if(backward && visited.count(-1 * (cur-b)) == 0){
                    q.emplace(cur - b, false);
                }
                if(visited.count(cur+a) == 0)
                    q.emplace(cur + a, true);
            }
            step++;
        }
        return -1;
    }
};