#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s;
    cin >> s;
    string a(10, '0');
    for (lol i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            for (lol j = 0;; j++)
            {
                if (a[j] == '0')
                {
                    a[j] = '1';
                    break;
                }
            }
        }
        else if (s[i] == 'R')
        {
            for (lol j = 9;; j--)
            {
                if (a[j] == '0')
                {
                    a[j] = '1';
                    break;
                }
            }
        }
        else
        {
            a[s[i] - '0'] = '0';
        }
    }
    cout << a;
}