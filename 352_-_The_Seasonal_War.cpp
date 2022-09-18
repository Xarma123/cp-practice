#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n;
void dfs(string a[], lol x, lol y)
{

    if (x < 0 || x >= n || y < 0 || y >= n)
        return;
    if (a[x][y] == '0')
        return;
    a[x][y] = '0';
    lol dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    lol dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (lol q = 0; q < 8; q++)
    {
        dfs(a, x + dx[q], y + dy[q]);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lol c = 1;
    while (cin >> n)
    {
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (a[i][j] == '1')
                {
                    ans++;
                    dfs(a, i, j);
                }
            }
        }
        cout << "Image number " << c << " contains " << ans << " war eagles." << endl;
        c++;
    }

    return 0;
}