#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            for (lol r = 0; r < n; r++)
            {
                if (r != i)
                {
                    if (a[i][j] == tolower(a[r][j]))
                    {
                        a[i][j] = toupper(a[i][j]);
                    }
                }
            }
            for (lol c = 0; c < m; c++)
            {
                if (c != j)
                {
                    if (a[i][j] == tolower(a[i][c]))
                    {
                        a[i][j] = toupper(a[i][j]);
                    }
                }
            }
            if (a[i][j] >= 'a' && a[i][j] <= 'z')
            {
                cout << a[i][j];
            }
        }
    }

    return 0;
}