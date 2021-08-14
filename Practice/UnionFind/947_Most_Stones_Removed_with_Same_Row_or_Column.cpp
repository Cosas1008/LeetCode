class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        for(auto stone : stones)
            uni(stone[0], ~stone[1]);
        return stones.size() - islands;
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
    int islands;
};