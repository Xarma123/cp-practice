#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        for (lol i = 1;; i++)
        {
            if (n % i != 0)
            {
                string s = "";
                for (char c = 'a'; c <= char('a' + i - 1); c++)
                {
                    s += c;
                }
                lol sz = s.size();
                lol j = 0;
                for (lol i = 0; i < n; i++)
                {
                    cout << s[j];
                    j++;
                    j %= sz;
                }
                cout << '\n';

                break;
            }
        }
    }
}