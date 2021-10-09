// DAG
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, -1), ds(n+1, 0);
        int first = -1, second = -1, last = -1;
        for(int i = 0 ; i < n; i++){
            int s = edges[i][0], d = edges[i][1]; // sorce and destination
            if(parent[d] != -1){
                first = parent[d];
                second = i;
                continue;
            }
            parent[d] = i;
            int s1 = find(ds, s);
            if(s1 == d) last = i;
            else ds[d] = s1;
        }

        if(last == -1) return edges[second]; // no cycle
        if(second == -1) return edges[last]; // no edge removed
        return edges[first];
    }
private:
    int find(vector<int>& ds, int k){
        return ds[k] == 0 ? k : (ds[k] = find(ds, ds[k]));
    }
};