/*
You are given two integer arrays of length n, aliceValues and bobValues. 
Each aliceValues[i] and bobValues[i] represents how Alice and Bob, respectively, value the ith stone.
Both players will play optimally. Both players know the other's values.
Determine the result of the game, and:
If Alice wins, return 1.
If Bob wins, return -1.
If the game results in a draw, return 0.
*/
class Solution {
public:
    int stoneGameVI(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<vector<int>> C;
        vector<int> diff(2);
        diff[0] = diff[1] = 0;
        for(int i = 0; i < n; i++){
            C.push_back({ -1 * (A[i] + B[i]), A[i], B[i]}); //why -1?
        }
        sort(C.begin(), C.end());
        for(int i = 0;  i < n; i++){
            diff[i % 2] += C[i][1 + i % 2];
        }
        return diff[0] == diff[1] ? 0 : diff[0] > diff[1]? 1 : -1;
    }
};
/*
Assume a stone valued [a,b] for Alice and Bod.
Alice takes it, worth a for Alice,
Bob takes it, worth b for Bob, we can also consider that it worth -b for Alice.
The difference will be a+b.
*/