#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
int help(){
    int n;
    vector<int> dices;
    cin >> n;
    dices.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> dices[i];
    sort(dices.begin(), dices.end());
    for(int i = 0; i < n; ++i)
        if(dices[i] < i + 1)
            return i;
    return n;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
        cout << "Case #" << i+1 << ": " << help() << endl;
    return 0;
}