#include<iostream>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int MX = 100001; 

void solve(){
    int N, M;
    cin >> N >> M;
    ll A[N][M];
    ll lo[M][N][N];
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> A[i][j];
    
    for(int i = 0; i < M; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                lo[i][j][k] = MX;
    
    for(int i = 0 ; i < M; ++i){
        for(int j = 0; j < N; ++j){
            lo[i][j][j] = A[j][i];
            for(int k = j+1; k < N; ++k){
                lo[i][j][k] = min(lo[i][j][k-1], A[k][i]);
            }
        }
    }

    ll tot[N][N];
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            tot[i][j] = 0;
    
    for(int i = 0; i < N; ++i){
        for(int j = i; j < N; ++j){
            for(int k = 0; k < M; ++k){
                tot[i][j] += lo[k][i][j];
            }
        }
    }

    ll dp[N][N];
    for(int i = 0; i < N; ++i)
        dp[i][i] = tot[i][i] * 2;
    
    for(int l = 1; l < N; ++l){
        for(int i = 0; i < N; ++i){
            int j = i+l;
            if(j >= N) break;
            dp[i][j] = 1e18;
            for(int k = i; k < j; ++k){
                ll cur = dp[i][k] + dp[k+1][j];
                cur -= 2 * tot[i][j];
                dp[i][j] = min(dp[i][j], cur);
            }
        }
    }
    
    cout << dp[0][N-1] << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0); 
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ++ti){
        cout << "Case #" << ti+1 << ": ";
        solve();
    }

    return 0;
}