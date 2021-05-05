#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++)
    {
        int x, y, sz;
        string s;
        cin >> x >> y;
        cin >> s;
        cout << "Case #" << ti+1 << ": ";
        sz = s.size();
        char pro = 'X';
        int ans = 0;
        for(int i = 0 ; i < sz; i++){
            if(pro == 'C' && s[i] == 'J')
                ans += x;
            if(pro == 'J' && s[i] == 'C')
                ans += y;
            if(s[i] != '?')
                pro = s[i];
        }
        cout << ans << endl;
    }
    return 0;
}