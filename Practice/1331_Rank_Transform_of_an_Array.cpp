/*
Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
*/
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        if(n == 0) return ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < n; i++){
            pq.emplace(arr[i], i);
        }
        int pre = pq.top().first;
        int rank = 1;
        while(!pq.empty()){
            auto tmp = pq.top(); pq.pop();
            ans[tmp.second] = (pre == tmp.first)? rank : ++rank;
            pre = tmp.first;
        }
        return ans;
    }
};
// Hash
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& A) {
        int n = A.size();
        vector<int> ans(A);
        sort(ans.begin(), ans.end());
        unordered_map<int,int> rank;
        for(auto& a : ans)
            rank.emplace(a, rank.size() + 1);
        for(int i = 0; i < n; i++)
            ans[i] = rank[A[i]];
        return ans;
    }
};