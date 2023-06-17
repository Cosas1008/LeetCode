/*
Input: arr = [1,2,3,4,5,6,7,8]
Output: 5
Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
Given a strictly increasing array arr
*/
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> s(A.begin(), A.end());
        int res = 0, n = A.size();
        for(int i = 0; i < n; i++){
            for(int j = i +1; j < n; j++){
                int a = A[i], b = A[j], l = 2;
                while(s.count(a+b)){
                    b += a;
                    a = b - a;
                    l++;
                }
                res = max(res, l);
            }
        }
        return res > 2? res : 0; // array size should be at least 3
    }
};