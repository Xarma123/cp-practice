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
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        bool ans = true;
        lol difz = 0;
        lol difo = -1;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] < b[i])
                ans = false;
            else if (b[i] < 0 && a[i] != b[i])
            {
                ans = false;
            }
            else if (b[i] == 0)
            {
                difz = max(difz, a[i]);
            }
            else
            {
                if (difo == -1)
                    difo = a[i] - b[i];
                else
                {
                    if (a[i] - b[i] != difo)
                        ans = false;
                }
            }
        }
        if (difo < difz && difo != -1)
            ans = false;
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}