/*
square matrices of size n x n. A binary matrix has only 0s and 1s as values.
We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. 
Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3

Hint : 2N horizontal possible sliding, 2N vertical sliding and N^2 to count overlap area.
Hint : Using hash table to store key
Constraints:
1 <= n <= 30
*/
class Solution {
public:
    // Time O(N^2) for traversing, O(AB) for loop, Space(A+B)
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int N = A.size();
        vector<int> LA, LB;
        unordered_map<int, int> count;
        for(int i = 0; i < N*N; ++i){
            int x = i / N;
            int y = i % N;
            if(img1[x][y])
                LA.push_back(x * 60 + y); // Key should be bigger than 2*N - 1
            if(img2[x][y])
                LB.push_back(x * 60 + y);
        }
        for(int a : LA)
            for(int b : LB)
                count[a - b]++;
        int res = 0;
        for(auto it : count)
            res = max(res, it.second);
        return res;
    }
};