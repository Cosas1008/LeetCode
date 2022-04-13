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

void solve(int t){
	cout << "Case #" << t << ": ";
	int n, c;
	cin >> n >> c;
	c += 1;
	if(c < n || c > n*(n+1) / 2){
		cout << "IMPOSSIBLE" << '\n';
		return;
	}
	c -= n;
	vector<int> res(n);
	for(int i = 0; i < n; i++) res[i] = i;
	for(int j = n-1; j >= 0; j--){
		int extra = min(c, n-1-j);
		c -= extra;
		reverse(res.begin() + j, res.begin() + j + extra + 1);
	}
	for(int i = 0; i < n; i++){
		cout << (res[i]+1) << " \n"[i == (n-1)];
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) solve(t);
}