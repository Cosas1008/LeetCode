#include<string>
#include<iostream>
#include<queue>

using namespace std;

string helper(){
    string s, ans = "";
    cin >> s;
    int n = s.length();
    queue<int> dup;
    char rep = s[0];
    for(int i = 1; i < s.length(); ++i){
        if( (s[i] > s[i-1]) || ( (s[i] == s[i-1]) && (rep != s[i]) ) ) dup.push(i-1), rep = s[i];
    }
    for(int i = 0; i < s.length(); ++i){
       if(dup.size() && dup.front() == i){
           // duplicate
           ans += s[i];
           ans += s[i];
           dup.pop();
       }else{
           // copy once
           ans += s[i];
       }
    }
    return ans;
}


int main(){
    int t;
    cin >> t;
    for(int i = 0 ; i < t; ++i)
        cout << "Case #"<< i+1 << ": " << helper() << endl; 
}