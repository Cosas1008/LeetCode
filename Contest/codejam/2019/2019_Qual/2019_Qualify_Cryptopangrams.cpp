/*
103 31
217 1891 4819 2291 2987 3811 1739 2491 4717 445 65 1079 8383 5353 901 187 649 1003 697 3239 7663 291 123 779 1007 3551 1943 2117 1679 989 3053
10000 25
3292937 175597 18779 50429 375469 1651121 2102 3722 2376497 611683 489059 2328901 3150061 829981 421301 76409 38477 291931 730241 959821 1664197 3057407 4267589 4729181 5335543
*/
#include <iostream>
#include <string>

int map[26]; // map of prime and # of char

int *decode(int);
int findNum(int);

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        string ans;
        int max_prime, num;
        cin >> max_prime >> num;
        // step1: map to the prime and 26 words
        int tmp = 26;
        while (tmp > 0)
        {
            int count = 0;
            for (int i = 2; i <= max_prime / 2; i++)
            {
                if (max_prime % i == 0)
                {
                    count++;
                    break;
                }
            }
            if (count == 0)
            {
                map[tmp--] = max_prime;
                // cout << "Number " << tmp <<" : " << max_prime << endl;
            }
            max_prime--;
        }
        // step2: decode each set
        int *prev, *curptr;
        char ch = 'A';
        for (int i = 0; i < num; i++)
        {
            int cypher;
            cin >> cypher;
            prev = curptr;
            curptr = decode(cypher);
            // one of the prev is in curptr
            if (*prev == *curptr || *prev == *(curptr++))
            {
                //swap
                int tmp = *prev;
                *prev = *prev++;
                *prev++ = tmp;
            }
            if (*curptr != *prev++)
            {
                // swap
                int tmp = *curptr;
                *curptr = *curptr++;
                *curptr++ = tmp;
            }
            if (i == 0)
                ans += (char)ch + *prev;
            ans += (char)ch + *prev++;
        }
        ans += (char)ch + *curptr++;
        cout << "Case #" << t << ": " << ans;
    }
    return 0;
}

int *decode(int cypher)
{
    int *arr = new int[2];
    for (int i = 0; i < 26; i++)
    {
        int trial = map[i + 1];
        if ((cypher % trial) == 0)
        {
            // find the prime
            int prime2 = cypher / trial;
            arr[0] = i + 1;
            if (findNum(prime2) == -1)
                continue;
            arr[1] = findNum(prime2);
            cout << " Arr[0] " << arr[0] << " : " << arr[1] << endl;
            return arr;
        }
    }
    return arr;
}

int findNum(int num)
{
    for (int i = 0; i < 26; i++)
    {
        if (map[i + 1] == num)
            return i + 1;
    }
    return -1;
}