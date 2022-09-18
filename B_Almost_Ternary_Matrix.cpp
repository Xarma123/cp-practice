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
        lol n, m;
        cin >> n >> m;
        lol mt[n][m];
        lol v = 1;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (i % 2 == 0)
                {
                    if (i == 0 && j == 0)
                    {
                        mt[i][j] = v;
                    }
                    else if (j % 4 == 1)
                        mt[i][j] = 1 - v;
                    else if (j % 4 == 2)
                        mt[i][j] = 1 - v;
                    else
                        mt[i][j] = v;
                }
                else
                {
                    mt[i][j] = 1 - mt[i - 1][j];
                }
                cout << mt[i][j] << " ";
            }
            if (i % 2 == 0)
                v = 1 - v;
            cout << endl;
        }
    }

    return 0;
}