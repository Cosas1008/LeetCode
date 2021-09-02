/*
Input: dist = [1,1,2,3], speed = [1,1,1,1]
Output: 1
Explanation:
In the beginning, the distances of the monsters are [1,1,2,3]. You eliminate the first monster.
After a minute, the distances of the monsters are [X,0,1,2], so you lose.
You can only eliminate 1 monster.
*/
class Solution {
public:
    // Wrong, but nice try to sort
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // don't be < 1 after a while
        vector<pair<int,int>> monster;
        for(int i = 0; i < dist.size(); i++){
            monster.emplace_back(dist[i], speed[i]);
        }
        sort(begin(monster), end(monster), [](const pair<int,int>& a,const pair<int,int>& b){
            return (a.first - a.second) < (b.first - b.second); 
        });
        int ans = 1;
        for(; ans < monster.size(); ans++){
            if(monster[ans].first - monster[ans].second*ans < 1)
                break;
        }
        return ans;
    }
    // consider this: new dis divide by speed
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for(int i = 0; i < dist.size(); i++){
            dist[i] = (dist[i] - 1) / speed[i]; // important to - 1
        }
        sort(begin(dist), end(dist));
        for(int i = 0; i < dist.size(); i++){
            if(i > dist[i])
                return i;
        }
        return dist.size();
    }
};