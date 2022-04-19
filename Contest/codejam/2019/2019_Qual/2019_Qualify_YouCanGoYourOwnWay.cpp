#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++)
    {
        int n;
        string test, ans;
        cin >> n >> test;
        for(int i =0; i < 2*(n-1); i++)
        {
            if(test[i]=='S') ans += 'E';
            else ans += 'S';
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}


// WA after hint from Chuck
// int main()
// {
//     int tc;
//     cin >> tc;
//     for (int t = 1; t <= tc; t++)
//     {
//         int num;
//         string test;
//         cin >> num >> test;
//         string ans;
//         int s = 0, e = 0;
//         int ms = 0, me = 0;
//         for(int n = 0; n < num*2-2 ; n++)
//         {
//             if(ms == s && me == e)
//             {
//                 if(test.at(n)=='S')
//                 {
//                     ans += 'E';
//                     me++;
//                 }
//                 else
//                 {
//                     ans += 'S';
//                     ms++;
//                 }
//             }
//             else
//             {
//                 if(ms < s)
//                 {
//                     ans += 'S';
//                     ms++;
//                 }
//                 else
//                 {
//                     ans += 'E';
//                     me++;
//                 }
                
//             }
//             (test.at(n)=='S')? s++: e++;
//         }
//         cout << "Case #" << t << ": " << ans << endl;
//     }
// }