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
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        lol f[26];
        memset(f, 0, sizeof(f));
        for (auto e : s)
        {
            f[e - 'a']++;
        }
        lol od = 0;
        for (lol i = 0; i < 26; i++)
        {
            if (f[i] % 2)
                od++;
        }
        od--;
        if (od <= k)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
