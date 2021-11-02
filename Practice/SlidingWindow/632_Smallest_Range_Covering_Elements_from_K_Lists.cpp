/*
k lists of sorted integers in non-decreasing order.
Find the smallest range that includes at least one number from each of the k lists
We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
*/
class Solution {
public:
    // priority_queue
    vector<int> smallestRange(vector<vector<int>>& A) {
        auto comp = [&](auto& a, auto& b){
            return A[a.first][a.second] > A[b.first][b.second];
        };
        int n = A.size();
        int lo = INT_MAX, hi = INT_MIN;
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        
        for(int i = 0; i < n; ++i){
            lo = min(lo, A[i][0]);
            hi = max(hi, A[i][0]);
            pq.emplace(i, 0);
        }
        vector<int> ans({lo, hi});
        
        while(pq.size()){
            auto [ k, i ] = pq.top(); pq.pop();
            if(A[k].size() == ++i) return ans; // reach end
            pq.emplace(k, i);
            auto [kk, ii] = pq.top();
            lo = A[kk][ii];
            hi = max(hi, A[k][i]);
            if(hi - lo < ans[1] - ans[0]) ans = {lo, hi};
            cout << "k : " << k << " i : " << i << " ans : " << ans[0] << ":" << ans[1] << endl;
        }
        
        return ans;
    }
};