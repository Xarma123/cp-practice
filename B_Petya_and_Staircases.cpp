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
    lol a[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(a, a + m);
    bool ans = true;
    for (lol i = 0; i < m; i++)
    {
        if (i + 2 < m)
        {
            if (a[i] == a[i + 1] - 1 && a[i + 1] == a[i + 2] - 1)
                ans = false;
        }
        if (a[i] == 1 || a[i] == n)
            ans = false;
    }
    if (ans)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}