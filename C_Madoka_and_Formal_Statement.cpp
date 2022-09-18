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
        lol a[n], b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool ans = true;
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (lol i = 0; i < n; i++)
        {
            if (b[i] < a[i])
            {
                ans = false;
            }
            else if (b[i] > a[i])
            {
                if (b[(i + 1) % n] < b[i] - 1)
                {
                    ans = false;
                }
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}