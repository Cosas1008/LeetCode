#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int costCount(vector<int> v, int n){
    int cost = 0;
    for(int i = 0 ; i < n - 1; i++){
        int mn  = 101;
        int idx = 0;
        for(int j = i; j < n; j++){
            if(v[j] < mn){
                mn = v[j];
                idx = j;
            }
        }
        cost += idx - i + 1;
        reverse(v.begin() + i, v.begin() + idx + 1);
    }
    return cost;
}

int main()
{
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        cout << "Case #" << ti+1 << ": ";
        bool flag = false;
        int n, c;
        cin >> n >> c;
        vector<int> v(n);

        for(int i = 0 ; i < n; i++){
            v[i] = i+1;
        }
        
        do{
            if(costCount(v, n) == c){
                flag = true;
                break;
            }
        }while(next_permutation(v.begin(), v.end()));
        if(flag){
            for(int vi: v){
                cout << vi << ' ';
            }
            cout << endl;
        }else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}