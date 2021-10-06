/*
Each [i, j] in red_edges denotes a red directed edge from node i to node j.  Similarly, 
each [i, j] in blue_edges denotes a blue directed edge from node i to node j.
Return an array answer of length n, where each answer[X] is the length of the shortest 
path from node 0 to node X such that the edge colors alternate along the path
Input: n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
Output: [0,1,-1]
*/
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& R, vector<vector<int>>& B) {
        vector<vector<pair<int,int>>> g(n);  //index, {neighbor index, color}
        queue<pair<int,int>> q; // index, color(0 or 1)

    }
};