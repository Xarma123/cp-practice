#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;
        lol d = 0;
        lol i = 0, j = n - 1;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                d++;
            }
            i++;
            j--;
        }
        string t(n + 1, '0');
        t[d] = '1';
        if (i == j)
        {
            n -= 2ll * d;
            for (lol k = d + 1; k <= d + n; k++)
            {
                t[k] = '1';
            }
        }
        else
        {
            n -= 2ll * d;
            n /= 2;
            lol p = d + 2;
            while ((n--) && p < t.size())
            {
                t[p] = '1';
                p += 2;
            }
        }
        cout << t << '\n';
    }
}