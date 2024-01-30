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
        lol n;
        cin >> n;
        string s;
        cin >> s;
        string f;
        cin >> f;

        lol ex = 0, re = 0;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] != f[i])
            {
                if (s[i] == '1')
                    ex++;
                else
                    re++;
            }
        }
        cout << max(ex, re) << '\n';
    }

    return 0;
}
