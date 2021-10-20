#include <iostream>
#include <algorithm>
using namespace std;

void permuations(string str, int i, int n)
{
    if (i == n - 1)
    {
        cout << str << " ";
        return;
    }
    for (int j = i; j < n; ++j)
    {
        swap(str[i], str[j]);
        permuations(str, i + 1, n);
        swap(str[i], str[j]); // restore default
    }
}
void permutations2(string str, int n, string res)
{
    // base condition (only one character is left in the string)
    if (n == 1)
    {
        cout << res + str << endl;
        return;
    }

    // process each character of the remaining string
    for (int i = 0; i < n; i++)
    {
        // push current character to the output string and recur
        // for the remaining characters
        permutations2(str.substr(1), n - 1, res + str[0]);

        // left rotate the string by 1 unit for next iteration
        // to right rotate the string use reverse iterator
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}
int main()
{
    int test = 0;
    cin >> test;
    for (int t = 0; t < test; ++t)
    {
        string str = "";
        string res;
        cin >> str;
        // permuations(str,0,str.length());
        permutations2(str, str.length(), res);
        cout << endl;
    }
    return 0;
}