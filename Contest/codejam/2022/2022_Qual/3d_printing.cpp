#include<iostream>
#include<vector>

using namespace std;

#define TARGET 1000000

void helper(){
    int color[4] = {0};
    for(int i = 0 ; i < 3; ++i){
        for(int j = 0; j < 4; ++j){
            int tmp;
            cin >> tmp;
            color[j] = (i==0)? tmp : min(color[j], tmp);
        }
    }
    int remain = TARGET;
    vector<int> ans;
    for(int i = 0; i < 4; ++i){
        if(remain == 0){
            ans.push_back(0);
            continue;
        }
        if(remain < color[i]){
            color[i] = remain;
        }
        remain -= color[i];
        ans.push_back(color[i]);
    }
    if(remain > 0){
        cout << "IMPOSSIBLE";
    }else{
        for(int i = 0 ; i < 4; ++i)
            cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ++ti){
        cout << "Case #" << ti+1 << ": ";
        helper();
    }
    return 0;
}