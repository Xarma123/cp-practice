#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool us[n + 1];
        for (lol i = 0; i <= n; i++)
        {
            us[i] = false;
        }

        for (lol i = 0; i < n; i++)
        {
            if (a[i] <= n)
                us[a[i]] = true;
        }
        for (lol i = 0; i <= n; i++)
        {
            if (us[i] == false)
            {
                cout << i << endl;
                break;
            }
        }
        while (1)
        {
            lol y;
            cin >> y;
            if (y == -1)
                break;
            cout << y << endl;
        }
    }
}