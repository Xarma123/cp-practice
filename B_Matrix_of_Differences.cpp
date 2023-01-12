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
        lol n;
        cin >> n;
        lol d = n * 1ll * n;
        lol v = d + 1;
        bool a = false;
        lol m[n][n];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (a)
                {
                    v += d;
                    m[i][j] = v;
                    d--;
                    a = false;
                }
                else
                {
                    v -= d;
                    m[i][j] = v;
                    d--;
                    a = true;
                }
            }
        }
        for (lol i = 1; i < n; i += 2)
        {
            lol j1 = 0, j2 = n - 1;
            while (j1 <= j2)
            {
                swap(m[i][j1], m[i][j2]);
                j1++;
                j2--;
            }
        }
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}