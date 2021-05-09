class Solution {
public:
    int vis[200005], dp[200005], deg[200005];
    int idx = 6;
    string str;
    vector<int> E[200005];
    queue<int> q;
    void dfs(int x, int col){
        if(vis[x] == idx) return;
        vis[x] = idx;
        dp[x] = 0;
        for(int i = 0; i < (int) E[x].size(); i++){
            dfs(E[x][i], col);
            dp[x] = max(dp[x], dp[E[x][i]]);
        }
        dp[x] += (str[x] - 'a' == col);
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), m = edges.size();
        str = colors;
        for(int i = 0; i< n; i++){
            E[i].clear();
            deg[i] = 0;
        }
        for(int i = 0; i < m; i++){
            int x = edges[i][0], y = edges[i][1];
            E[x].push_back(y);
            ++deg[y];
        }
        queue<int> q;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(deg[i] == 0) q.push(i), ++cnt;
        }
        while(!q.empty()){
            int k = q.front();
            q.pop();
            for(int i = 0; i < (int) E[k].size(); i++){
                int to = E[k][i];
                --deg[to];
                if(deg[to] == 0){
                    q.push(to);
                    ++cnt;
                }
            }
        }
        if(cnt != n) return -1;
        int ans = 0;
        for(int r = 0; r < 26; r++){
            ++idx;
            for(int i = 0; i < n; i++){
                dfs(i, r);
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int ans[100001][26];
    int degree[100001];
    int largestPathValue(string colors, vector<vector<int>>& edges){
        vector<int> v[100005];
        queue<int> q;
        fill(degree, degree+colors.size(), 0);
        for(auto edge: edges){
            v[edge[0]].push_back(edge[1]);
            degree[edge[1]]++;
        }
        for(int i = 0; i < colors.size(); i++){
            if(degree[i]==0) q.push(i);
        }
        int res = 0, cnt = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            cnt++;
            ans[x][colors[x]-'a']++;
            res = max(res, ans[x][colors[x]-'a']);
            for(auto it: v[x]){
                for(int j = 0; j < 26; j++)
                    ans[it][j] = max(ans[it][j], ans[x][j]);
                if(--degree[it]==0) q.push(it);
            }
        }
        if(cnt != colors.size()) return -1;
        return res;
    }
}
