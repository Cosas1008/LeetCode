#include<vector>
#include<iostream>

using namespace std;

void solve(){
    int r, c;
    cin >> r >> c;
    string row, comm;
    row = "|";
    comm = "+";
    for(int i = 0; i < c; ++i){
        row  += ".|";
        comm += "-+";
    }
    for(int i = 0; i < 2*r+1; ++i){
        if(i%2 == 0){ // comm
            if(i == 0){
                string tmp = comm;
                tmp[0] = tmp[1] = '.';
                cout << tmp;
            }else{
                cout << comm;
            }
        }else{
            if(i == 1){
                string tmp = row;
                tmp[0] = tmp[1] = '.';
                cout << tmp;
            }else{
                cout << row;
            }
        }
        cout << endl;
    }
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        cout << "Case #" << i << ":" << endl;
        solve();
    }
}