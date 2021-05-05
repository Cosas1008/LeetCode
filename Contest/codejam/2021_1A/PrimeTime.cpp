// Pass S1 S2
#include<iostream>
#include<vector>
using namespace std;

bool isPrimeTime(int x, int s, vector<int>& ps, vector<int> ns){
    for(int i = 0 ; i < ps.size(); i++){
        while(x % ps[i] == 0){
            x /= ps[i];
            s -= ps[i];
            if(x < 0) return false;
            if(--ns[i] < 0) return false;
        }
    }
    // cout << "x " << x << "s " << s << endl;
    return (x == 1) && (s == 0);
}

int solve(int m, vector<int>& ps, vector<int>& ns){
    int sum = 0;
    for(int i = 0 ; i < m; i++){
        sum += ps[i] * ns[i];
    }
    for(int n = sum; n > 1; n--){
        if(isPrimeTime(n, sum - n, ps, ns)){
            return n;
        }
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        vector<int> ps, ns;
        int m, p, n;
        cin >> m;
        for (size_t i = 0; i < m; i++)
        {
            cin >> p >> n;
            ps.push_back(p);
            ns.push_back(n);
        }
        cout << "Case #" << ti+1 << ": " << solve(m, ps, ns) << endl;
    }
    return 0;
}