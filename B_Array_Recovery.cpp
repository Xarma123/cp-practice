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
        lol n;
        cin >> n;
        lol d[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        lol ans[n];
        ans[0] = d[0];
        bool a = true;
        for (lol i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] + d[i];
            if (ans[i - 1] - d[i] >= 0 && d[i] != 0)
                a = false;
        }
        if (a)
        {
            for (lol i = 0; i < n; i++)
            {
                cout << ans[i] << " ";
            }
        }
        else
            cout << -1;
        cout << endl;
    }

    return 0;
}