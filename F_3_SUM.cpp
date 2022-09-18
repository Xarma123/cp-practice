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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] %= 10;
        }
        set<lol> si;
        set<lol> du;
        bool f = false;
        for (lol i = 0; i < n; i++)
        {
            for (auto e : du)
            {
                if ((a[i] + e) % 10 == 3)
                    f = true;
            }
            for (auto e : si)
            {
                du.insert((a[i] + e) % 10);
            }
            si.insert(a[i]);
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}