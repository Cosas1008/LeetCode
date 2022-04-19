#include<string>
#include<iostream>

using namespace std;

void helper(){
    string s, ans = "";
    cin >> s;
    int n = s.length();
    int it = 0; // Next not same char index
    for(int i = 0; i < n; ++i){
        if(it == i) ++it;
        while(it <= n && s[it] == s[i]) it++;
        if(it == n || s[i] > s[it])
            ans += s[i];
        else{
            ans += s[i];
            ans += s[i];
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0 ; i < t; ++i){
        cout << "Case #"<< i+1 << ": "; 
        helper();
    }
}