#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    lol c[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        c[0][i] = 0;
        c[i][0] = 0;
    }
    for (lol i = 1; i <= n; i++)
    {
        for (lol j = 1; j <= n; j++)
        {
            c[i][j] = c[i - 1][j];
            c[i][j] += c[i][j - 1] - c[i - 1][j - 1];
            char a;
            cin >> a;
            if (a == '*')
                c[i][j]++;
        }
    }
    while (q--)
    {
        lol y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << c[x2][y2] - c[x1 - 1][y2] - (c[x2][y1-1] - c[x1 - 1][y1-1]) << endl;
    }

    return 0;
}