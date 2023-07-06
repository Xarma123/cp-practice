#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
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
        vector<lol> f;
        bool inc = true;
        for (lol i = 0; i < n; i++)
        {
            if (f.size() == 0)
            {
                cout << 1;
                f.push_back(a[i]);
            }
            else if (inc && f.back() <= a[i])
            {
                cout << 1;
                f.push_back(a[i]);
            }
            else if (inc && f[0] >= a[i])
            {
                inc = false;
                cout << 1;
                f.push_back(a[i]);
            }
            else if (!inc && f[0] >= a[i] && f.back() <= a[i])
            {
                cout << 1;
                f.push_back(a[i]);
            }
            else
                cout << 0;
        }
        cout << '\n';
    }
}