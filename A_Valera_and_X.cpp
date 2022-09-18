#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string a[n];
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    char d = a[0][0];
    bool f = true;
    for (lol i = 0, j = 0; i < n && j < n; i++, j++)
    {
        vis[i][j] = true;
        if (a[i][j] != d)
            f = false;
    }
    for (lol i = 0, j = n - 1; i < n && j >= 0; i++, j--)
    {
        vis[i][j] = true;
        if (a[i][j] != d)
            f = false;
    }
    if (a[0][1] == d)
        f = false;
    d = a[0][1];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            if (!vis[i][j])
            {
                if (a[i][j] != d)
                    f = false;
            }
        }
    }
    if (f)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}