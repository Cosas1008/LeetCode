#include <iostream>
#include <string>
#include <vector>

using namespace std;

void permutation(int index, string s, vector<string>& store)
{
    if(index == s.size()){
        store.push_back(s);
    }else if(s[index] == '?'){
        permutation(index+1, s.substr(0,index) + 'C' + s.substr(index+1), store);
        permutation(index+1, s.substr(0,index) + 'J' + s.substr(index+1), store);
    }else{
        permutation(index+1, s, store);
    }
};
int countRepeat(string b, string a){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == b[0] && a[i+1] == b[1]){
            cnt+= 1;
        }
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++)
    {
        int x, y;
        string s;
        int minval = 2147483647;
        vector<string> store;
        cin >> x >> y;
        cin >> s;

        permutation(0, s, store);

        for(int si = 0; si < store.size(); si++){
            string s = store[si];
            // cout << "string : " << s << endl;
            int cntx, cnty;

            cntx = countRepeat("CJ", s);
            cnty = countRepeat("JC", s);

            minval = min(minval, cntx * x + cnty * y);
        }
        cout << "Case #" << ti+1 << ": " << minval << endl;
    }
    return 0;
}