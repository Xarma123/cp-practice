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
    bool ans = true;
    set<lol> d;
    for (lol i = 0; i < n; i++)
    {
        lol g = -1, s = -1;
        for (lol j = 0; j < m; j++)
        {
            if (a[i][j] == 'G')
            {
                g = j;
                if (s != -1)
                    ans = false;
            }
            else if (a[i][j] == 'S')
                s = j;
        }
        d.insert(s - g);
    }
    if (ans)
        cout << d.size();
    else
        cout << -1;

    return 0;
}