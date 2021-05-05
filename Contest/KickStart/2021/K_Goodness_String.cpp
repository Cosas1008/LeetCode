#include<iostream>
#include<string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        int n, k, good = 0;
        string tmp;
        cin >> n >> k >> tmp;
        cout << "Case #" << ti+1 << ": ";
        for(int i = 0; i < n/2; i++){
            if(tmp[i] != tmp[n-1-i]){
                good++;
            }
        }
        if(good >= k){
            cout << good - k;
        }else{
            cout << k - good;
        }
        cout << endl;
    }
}