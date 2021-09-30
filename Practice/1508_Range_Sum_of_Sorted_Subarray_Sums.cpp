/*
Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13 
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. 
The sum of the numbers from index left = 1 to right = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
*/
class Solution {
public:
    // TLE: brute force to list all accumulation
    int rangeSum(vector<int>& A, int n, int left, int right) {
        vector<int> acc;
        for(int i = 0; i < n; ++i){
            for(auto j = i, sum = 0; j < n; ++j){
                acc.push_back(sum += A[j]);
            }
        }
        sort(acc.begin(), acc.end());
        return accumulate(acc.begin()+ left - 1, acc.begin() + right, 0);
    }
};
// priority_queue solution
class Solution {
public:
    int rangeSum(vector<int>& A, int n, int left, int right) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < A.size(); i++)
            pq.emplace(A[i], i+1);
        int ans = 0, mod = 1e9+7;
        // print_queue(pq);
        for(int i = 1; i <= right; i++){
            auto p = pq.top(); pq.pop();
            if( i >= left)
                ans = (ans + p.first) % mod;
            if( p.second < n){
                p.first += A[p.second++];
                pq.push(p);
            }
            // cout << "Ans : " << ans << endl;
            // print_queue(pq);
        }
        return ans;
    }
// private:
//     template<typename T>
//     void print_queue(T q) { // NB: pass by value so the print uses a copy
//         while(!q.empty()) {
//             std::cout << q.top().first << " = " << q.top().second << " | ";
//             q.pop();
//         }
//         std::cout << '\n';
//     }
};

// Binary Search (Not yet)
class Solution {
public:
    int rangeSum(vector<int>& A, int n, int left, int right) {
        int mod = 1e9+7;
        B.resize(n+1, 0), C.resize(n+1, 0);
        N = n;
        // B : partial sum of A, C: partial sum of B
        for(int i = 0; i < n; ++i){
            B[i+1] = B[i] + A[i];
            C[i+1] = C[i] + B[i];
        }
        return (int)((sumKsums(right) - sumKsums(left - 1)) % mod);
    }
    // binary search to find how many number are below k
    int kthSum(int k){
        int l = 0, r = B[N];
        while(l < r){
            int mid = (l + r) >> 1;
            if(count_under(mid) < k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    int count_under(int k){
        int res = 0;
        for(int l = 0, r = 0; r <= N; r++){
            while(B[r] - B[l] > k) l++;
            res += r - l + 1;
        }
        return res;
    }
    int sumKsums(int k){
        int score = kthSum(k);
        long sum = 0;
        for(int l = 0, r = 0; r < N; r++){
            while( B[r+1] - B[l] > score) l++;
            sum += B[r+1] * (r - l + 1) - (l? C[r] : C[r] = C[l-1]);
        }
        return sum - (count_under(score) - k) * score;
    }
private:
    vector<int> B, C;
    int N;
};