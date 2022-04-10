#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

typedef long long LL;

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ++ti){
        int N;
        cin >> N;
        vector<int> A;
        for(int i = 0; i < N; ++i)
            A.push_back(1<<i);
        
        for(int i = 0; i < N; ++i)
            cout << A[i] << " \n"[i+1==N];
        
        cout << flush;
        
        A.resize(2*N);
        for(int i = 0 ; i < N; ++i)
            cin >> A[N + i];

        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());

        int64_t s = accumulate(A.begin(), A.end(), int64_t(0));
        s /= 2;
        for(auto x : A){
            if(x > s) continue;
            s -= x;
            cout << x;
        }
        cout << endl;
        cout << flush;
    }
    return 0;
}