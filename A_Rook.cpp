#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        for (lol i = 1; i <= 8; i++)
        {
            if ((s[1] - '0') != i)
            {
                cout << s[0] << i << '\n';
            }
        }
        for (char c = 'a'; c <= 'h'; c++)
        {
            if (s[0] != c)
            {
                cout << c << s[1] << '\n';
            }
        }
    }

    return 0;
}
