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

        int k = A.size();
        // assume to take large and small from [0] list
        int lo = INT_MAX, hi = INT_MIN;
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);

        for(int i = 0; i < k; ++i){
            lo = min(lo, A[i][0]);
            hi = max(hi, A[i][0]);
            pq.emplace(i, 0);
        }
        vector<int> ans({lo, hi});
        while(!pq.empty()){
            auto [i, j] = pq.top(); pq.pop();
            if(A[i].size() == ++j) return ans; // reach end
            pq.emplace(i, j);
            auto [ii, jj] = pq.top(); // no pop here

            lo = A[ii][jj];
            hi = max(hi, A[i][j]);
            if(hi - lo < ans[1] - ans[0]) ans = {lo, hi};
        }
        return ans;
    }
};