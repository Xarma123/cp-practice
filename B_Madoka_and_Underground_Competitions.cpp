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
        r %= k;
        c %= k;
        for (lol i = 0; i < n; i++)
        {
            a[i] = s;
        }
        a[r][c] = 'X';
        set<lol> avoid;
        avoid.insert(c);
        lol v = 0;
        for (lol i = 0; i < k; i++)
        {
            if (i == r)
            {
                for (lol j = i + k; j < n; j += k)
                {
                    a[j][c] = 'X';
                }
            }
            else
            {
                while (avoid.count(v))
                    v = (v + 1) % k;
                avoid.insert(v);
                a[i][v] = 'X';
                for (lol j = i + k; j < n; j += k)
                {
                    a[j][v] = 'X';
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {
            lol j;
            for (j = 0; j < n; j++)
            {
                if (a[i][j] == 'X')
                    break;
            }
            for (lol q = j + k; q < n; q += k)
            {
                a[i][q] = 'X';
            }
        }

        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
    }

    return 0;
}