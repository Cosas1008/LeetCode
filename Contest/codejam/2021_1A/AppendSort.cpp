#include<iostream>
#include<string>
#include<vector>

using namespace std;

int intlen(int x){
    return str(x).length();
}

int increment(int x_pre, int x){
    x_pre += 1; // must be at least 1 larget than previous
    if(x > x_pre) return x;
    string x_pre_str(x_pre), x_str(x);
    if(x_str.length() > x_pre_str.length()){
        return (int) x_str+'0' * (x_pre_str.length() - x_str.length());
    }else if(x_str.length() < x_pre_str.length()){
        return (int) x_str+'0' * (1+x_pre_str.length() - x_str.length());
    }
    return x_pre;
}

int helper(vector<int>& vc)
{
    if(vc.size() == 0) return 0;
    int total_cost = 0, x_new, x_pre;
    x_pre = 0;
    for(auto v : vc){
        x_new = increment(x_pre, x);
        int cost = intlen(x_new) - intlen(x);
        x_pre = x_new;
        total_cost += cost;
    }
    return total_cost;
}

int main(){
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        int n;
        cin >> n;
        vector<int> vc(n);
        for(int i = 0 ; i < n; i++){
            cin >> vc[i];
        }
        int sol = helper(vc);
        cout << "Case #" << ti+1 << ": ";
        
    }
    return 0;
}