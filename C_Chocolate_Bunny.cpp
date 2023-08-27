#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol mx = 1;
    lol ans[n + 1];
    for (lol i = 2; i <= n; i++)
    {
        lol v, v1;
        cout << "? " << mx << " " << i << endl;
        cin >> v;
        cout << "? " << i << " " << mx << endl;
        cin >> v1;
        if (v > v1)
        {
            ans[mx] = v;
            mx = i;
        }
        else
        {
            ans[i] = v1;
        }
    }

    ans[mx] = n;

    cout << "! ";
    for (lol i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}