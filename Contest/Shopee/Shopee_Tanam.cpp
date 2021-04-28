#include<iostream>
#include<vector>

using namespace std;

int helper(int day, int side, int n, int m, vector<vector<int>>& bridge)
{
    if(day == n) return 0;
    int local_min = 0, cross_cost = 0;
    // Determin local min
    if(side){
        for(int i = m-1; i >= 0, bridge[day][i] >= 0; i--){
            local_min += bridge[day][i];
        }
    }else{
        for(int i = 0; i < m, bridge[day][i] >= 0; i--){
            local_min += bridge[day][i];
        }
    }
    for(auto bri : bridge[day]) cross_cost += bri;
    return max(
        (local_min + helper(day+1, side, n, m, bridge)), // not cross
        , (helper(day-1, !side, n, m, bridge) + cross_cost)
    );
}
int main()
{
    int t, n, m;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        cin >> n >> m;
        vector<vector<int>> bridge(n, vector<int>(m));
        // cross and not cross
        cout << helper(0, 0, n, m, bridge) << endl;
    }
    return 0;
}