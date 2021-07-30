typedef pair<int,int> pii;
class Solution {
public:
    // struct mycomp{
    //     bool operator()(const pii& lh, const pii& rh){
    //         if(lh.first != rh.first)
    //             return lh.first < rh.first;
    //         return lh.second < rh.second;
    //     }
    // };
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pii> ess;
        for(int i = 0; i < speed.size(); i++)
            ess.emplace_back(efficiency[i], speed[i]);
        sort(ess.rbegin(), ess.rend());
        long tspeed = 0, totalspeed = 0;
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        for(auto& [e, s]: ess){
            pq.emplace(s);
            totalspeed += s;
            if(pq.size() > k){
                totalspeed -= pq.top();
                pq.pop();
            }
            tspeed = max(tspeed, e * totalspeed);
        }
        return tspeed % (int)(1e9+7);
    }
};