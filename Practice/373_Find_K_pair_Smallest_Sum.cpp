/*
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
*/
class Solution {
public:
    typedef pair<int, pair<int, int>> ppi
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
        vector<vector<int>> res;
        if (m == 0 || n == 0) return res;
        for (int i = 0; i < m; i++) {
            pq.push({{nums1[i]+nums2[0]}, {i, 0}});
        }
        while (!pq.empty() && k-- > 0) {
            int val = pq.top().first, i = pq.top().second.first, j = pq.top().second.second;
            pq.pop();
            vector<int> v = {nums1[i], nums2[j]};
            res.push_back(v);
            if (j+1 == n) continue;
            pq.push({{nums1[i]+nums2[j+1]}, {i, j+1}});
        }
        return res;   
    }
};

/*
Python 1-line
class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        return sorted(itertools.product(nums1, nums2), key=sum)[:k]
*/