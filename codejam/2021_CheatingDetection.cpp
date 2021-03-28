#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int t;
    ifstream fin("cheat.in");
    fin >> t;
    for(int ti = 0; ti < t; ti++)
    {
        int ans;
        int p;
        // int dp[100][100000];
        int mid   = 100000 / 2;
        int diff  = 100000;
        int index = 0;
        fin >> p;
        for(int test = 0; test < 100; test++){
            string s;
            fin >> s;
            int count = 0;
            for(int i = 0; i < 100000; i++){
                // dp[test][i] = (int) s[i] - '0';
                if(s[i] == '1') count++;
            }
            int cur = abs(count - mid);
            // find the nearest 50% person
            if(cur < diff){
                index = test;
                diff  = cur;
            }
        }
        ans = index;
        cout << "Case #" << ti+1 << ": " << ans << endl;
    }
    return 0;
}