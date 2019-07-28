#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        string s;
        cin >> s;
        size_t s_ptr = s.find("4");
        int init = s_ptr;
        string a(s.size() - s_ptr, '0');
        while (s_ptr != string::npos)
        {
            s.replace(s_ptr, 1, "3");
            a.replace(s_ptr-init, 1, "1");
            s_ptr = s.find("4");
        }
        cout << "Case #" << t << ": " << s << " " << a << endl;
    }
    return 0;
}