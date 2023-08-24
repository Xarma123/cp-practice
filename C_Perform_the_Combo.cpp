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
        lol n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        lol c[n];
        memset(c, 0, sizeof(c));
        while (m--)
        {
            lol i;
            cin >> i;
            i--;
            c[i]++;
        }
        c[n - 1]++;
        for (lol i = n - 2; i >= 0; i--)
        {
            c[i] += c[i + 1];
        }
        lol f[26];
        memset(f, 0, sizeof(f));
        for (lol i = 0; i < n; i++)
        {
            f[s[i] - 'a'] += c[i];
        }
        for (lol i = 0; i < 26; i++)
        {
            cout << f[i] << " ";
        }
        cout << '\n';
    }
}