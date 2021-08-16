/*
Input: obstacles = [1,2,3,2]
Output: [1,2,3,3]
Explanation: The longest valid obstacle course at each position is:
- i = 0: [1], [1] has length 1.
- i = 1: [1,2], [1,2] has length 2.
- i = 2: [1,2,3], [1,2,3] has length 3.
- i = 3: [1,2,3,2], [1,2,2] has length 3.
*/
// Time O(nlogn)
// Space O(n)
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& A) {
        vector<int> res, mono;
        for(int a : A) {
            int l = 0, r = mono.size();
            while(l < r) {
                int m = (l + r) / 2;
                if (mono[m] <= a)
                    l = m + 1;
                else
                    r = m;
            }
            res.push_back(l + 1);
            if(mono.size() == l)
                mono.push_back(a); // len++
            mono[l] = a;
            cout << "l " << l << " r " << r << " a " << a << " : ";
            printv(mono);
        }
        return res;
    }
    void printv(vector<int> v){
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
    }
};

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& A) {
        vector<int> ans(A.size()), mono;
        for(int i = 0; i < A.size(); i++) {
            if(mono.size() == 0 || mono[mono.size() - 1] <= A[i]){
                mono.push_back(A[i]);
                ans[i] = mono.size();
            }else{
                auto it = upper_bound(mono.begin(), mono.end(), A[i]);
                *it = A[i];
                ans[i] = it - mono.begin() + 1;
            }
        }
        return ans;
    }
};