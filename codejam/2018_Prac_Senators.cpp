#include <iostream>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#define MAX 26

using namespace std;

int main()
{
    int tc;
    cin >> tc; // input # testCase
    pair<int, char> party[MAX];

    for (int t = 1; t <= tc; t++)
    {
        int count = 0, n = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            party[i] = make_pair(a, (char)'A' + i);
            count += a;
        }
        vector<string> solution;
        while (count > 0)
        {
            sort(party, party + n);
            string set(1, party[n - 1].second);
            party[n - 1].first -= 1;
            count -= 1;
            if (count % 2 == 1)
            {
                set.push_back(party[n - 2].second);
                party[n - 2].first -= 1;
                count -= 1;
            }
            solution.push_back(set);
        }
        cout << "Case #" << t << ":";
        for (string s : solution)
            cout << " " << s;
        cout << endl;
    }

    return 0;
}

// reference https://github.com/ruippeixotog/google-code-jam-2016/blob/master/round1c/senate-evacuation.cpp
