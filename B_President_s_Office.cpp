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
    char c;
    cin >> c;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = 0;
    set<char> x;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (a[i][j] != c&&a[i][j]!='.')
            {
                bool f = false;
                lol dx[4] = {-1, 0, 0, 1};
                lol dy[4] = {0, -1, 1, 0};
                for (lol k = 0; k < 4; k++)
                {
                    if (i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < m)
                    {
                        if (a[i + dx[k]][j + dy[k]] == c)
                            f = true;
                    }
                }
                if (f)
                    x.insert(a[i][j]);
            }
        }
    }
    cout << x.size();

    return 0;
}