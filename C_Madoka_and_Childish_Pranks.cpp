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
        string a[n];
        for (lol i = 0; i < n; i++)
            cin >> a[i];
        if (a[0][0] != '0')
            cout << -1 << '\n';
        else
        {
            cout << n * 1ll * m << '\n';
            cout << "1 1 1 1\n";
            for (lol i = 0; i < n; i++)
            {
                for (lol j = m - 1; j > 0; j--)
                {
                    if (a[i][j] == '0')
                    {
                        cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 1 << '\n';
                    }
                    else
                    {
                        cout << i + 1 << " " << j << " " << i + 1 << " " << j + 1 << '\n';
                    }
                }
            }
            for (lol i = n - 1; i > 0; i--)
            {
                if (a[i][0] == '0')
                    cout << i + 1 << " " << 1 << " " << i + 1 << " " << 1 << '\n';
                else
                    cout << i << " " << 1 << " " << i + 1 << " " << 1 << '\n';
            }
            
        }
    }
}