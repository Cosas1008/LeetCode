#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool helper(vector<string>& tower, vector<bool> visit, string ans, int idx){
    if(isValid(ans)){
        helper
    }
}

int main(){
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ++t){
        int n;
        cin >> n;
        vector<string> tower;
        string tmp;
        for(int i = 0; i < n; ++i){
            cin >> tmp;
            tower.push_back(tmp);
        }

        // greedy
        string ans = "";
        vector<bool> visit(n, false);
        if(helper(tower, visit, ans, 0)){

        }
    }
}