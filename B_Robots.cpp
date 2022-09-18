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
        lol l = -1;
        bool f = false;
        string q[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> q[i];
        }
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {

                if (q[i][j] == 'R')
                {
                    if (l == -1)
                        l = j;
                    else
                    {
                        if (j < l)
                        {
                            cout << "NO" << endl;
                            f = true;
                            break;
                        }
                    }
                }
            }
            if (f)
                break;
        }
        if (!f)
            cout << "YES" << endl;
    }

    return 0;
}