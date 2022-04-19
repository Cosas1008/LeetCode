#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int64_t solve(){
    int n;
    cin >> n;
    vector<int64_t> F(n);
    for(auto& f : F)
        cin >> f;
    
    vector<int> parent(n);
    vector<vector<int>> children(n);
    for(int i = 0; i < n; ++i){
        cin >> parent[i];
        parent[i]--;
        
        // record every node's children, except root( add last )
        if(parent[i] >= 0)
            children[parent[i]].push_back(i);
    }
    int64_t total = 0;
    vector<int64_t> up(n, 0);

    for(int node = n - 1; node >= 0; --node){

        // Sorted store child's value and sort
        vector<int64_t> sorted;

        for(int child : children[node])
            sorted.push_back(up[child]);

        sort(sorted.begin(), sorted.end());

        while(sorted.size() > 1){
            total += sorted.back();
            sorted.pop_back();
        }
        if(sorted.empty())
            sorted = {0};

        up[node] = max(sorted[0], F[node]);
    }

    // Get root's child
    for(int i = 0; i < n; ++i)
        if(parent[i] < 0)
            total += up[i];
    
    return total;
}

int main(){
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ++ti){
        int64_t ans = solve();
        cout << "Case #" << ti+1 << ": " << to_string(ans) << endl;
    }
    return 0;
}