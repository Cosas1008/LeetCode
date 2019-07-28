#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int lastMatch(string a, string b);
int main()
{
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++)
    {
        int number;
        cin >> number;
        string a[number];
        for (int n = 0; n < number; n++)
        {
            cin >> a[n];
        }
        int ans = 0, max_match = 0, pre_match = 0;
        int i = 1;
        for (int i = 1; i < number;)
        {
            // find a[i-1] a[i] last couple match
            int match = lastMatch(a[i], a[i - 1]);
            // ans = (match * 2 > number) ? number : match * 2;
            if(match && pre_match-1==match)
            {
                ans += 2;
                i += 2;
                pre_match = match;
            }else if(match){
                ans = 2;
                i += 2;
                pre_match = match;
            }else{
                i++;
                ans = 0;
            }
            max_match = max(max_match, ans);
        }
        cout << "Case #" << t + 1 << ": " << max_match << endl;
    }
    return 0;
}

int lastMatch(string a, string b)
{
    int lenA = a.length() - 1;
    int lenB = b.length() - 1;
    int match = 0;
    while (a[lenA] == b[lenB])
    {
        match++;
        lenA--;
        lenB--;
        if (a[lenA] != b[lenB])
            break;
    }
    return match;
}