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
    bool ans = true;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        for (lol j = 0; j < m; j++)
        {
            if (a[i][j] != a[i][0])
                ans = false;
        }
        if (i)
            ans &= (a[i][0] != a[i - 1][0]);
    }
    if (ans)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}