#include<iostream>
#include<string>
#include<vector>

typedef long long ll;
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        int n;
        cin >> n;
        string arr[n];
        for(string& x : arr) cin >> x;
        ll res = 0;
        for(int i = 1; i < n; ++i){
            // Case 1 : arr size is increasing
            if(arr[i].size() > arr[i-1].size()) continue;
            // Case 2: arr size is small -> add x
            while(arr[i].size() < arr[i-1].size()){
                arr[i].push_back('x');
                ++res;
            }
            // Case 3: number equal
            if(arr[i] == arr[i-1]){
                arr[i].push_back('0');
                ++res;
                continue;
            }
            // Deal with 'x' case, one digit a time
            for(int j = 0; j < arr[i].size(); ++j){
                
                if(arr[i][j] == 'x'){
                    bool all9 = true;
                    for(;j < arr[i].size(); ++j) if(arr[i-1][j] != '9') all9 = false;

                    if(all9){ // All-9
                        for(char &c : arr[i]) if(c == 'x') c = '0';
                        arr[i] += '0';
                        res++;
                        break;
                    }else{
                        int carry = 1;
                        for(int k = arr[i].size() - 1; k >= 0; --k){
                            if(arr[i][k] != 'x') break;
                            int sum = carry + (arr[i-1][k] - '0');
                            arr[i][k] = '0' + sum % 10;
                            carry = sum / 10;
                        }
                        break;
                    }
                }
                
                if(arr[i][j] < arr[i-1][j]){
                    for(auto& c : arr[i]) if(c == 'x') c = '0';
                    arr[i].push_back('0');
                    ++res;
                    break;
                }

                if(arr[i][j] > arr[i-1][j]){
                    for(auto& c : arr[i]) if(c == 'x') c = '0';
                    break;
                }
            }
        }
        cout << "Case #" << ti+1 << ": " << res << endl;
    }
    return 0;
}