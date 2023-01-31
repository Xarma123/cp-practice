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
        bool ans = false;
        lol a[n];
        vector<lol> e, o;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2)
                o.push_back(i + 1);
            else
                e.push_back(i + 1);
        }
        if (o.size() >= 3)
        {
            cout << "YES" << '\n';
            cout << o[0] << " " << o[1] << " " << o[2] << '\n';
        }
        else if (o.size() >= 1 && e.size() >= 2)
        {
            cout << "YES" << '\n';
            cout << o[0] << " " << e[0] << " " << e[1] << '\n';
        }
        else
            cout << "NO" << '\n';
    }

    return 0;
}