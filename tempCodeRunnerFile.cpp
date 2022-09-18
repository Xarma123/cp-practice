#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k, r, c;
        cin >> n >> k >> r >> c;
        string a[n];
        string s = "";
        for (lol i = 0; i < n; i++)
        {
            s = s + ".";
        }
        r--;
        c--;
        for (lol i = 0; i < n; i++)
        {
            a[i] = s;
        }
        set<lol> avoid;
        avoid.insert((c % k));
        a[r][c] = 'X';
        lol v = 0;
        for (lol i = 0; i < n; i++)
        {
            v = (v + 1) % k;
            while (avoid.count(v) && avoid.size() < k)
                v = (v + 1) % k;

            if (i == r)
                v = c % k;
            for (lol j = v; j < n; j += k)
            {
                a[i][j] = 'X';
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
    }

    return 0;
}