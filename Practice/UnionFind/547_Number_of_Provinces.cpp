/*
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if
the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        islands = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(isConnected[i][j] == 1){
                    uni(i, j);
                }
            }
        }
        return islands;
    }
    int find(int x){
        if(!m.count(x)) m[x] = x, islands++;
        if(x != m[x]) m[x] = find(m[x]);
        return m[x];
    }

    void uni(int x, int y){
        x = find(x), y = find(y);
        if(x != y) m[x] = y, islands--;
    }
private:
    unordered_map<int, int> m;
    int islands = 0;
};