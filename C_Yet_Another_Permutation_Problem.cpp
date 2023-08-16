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
        a[0] = 1;
        if (n > 1)
        {
            a[1] = 2;
            set<lol> x;
            for (lol i = 3; i <= n; i++)
            {
                x.insert(i);
            }
            for (lol i = 2; i < n; i++)
            {
                if (x.count(a[i - 1] * 2ll))
                {
                    a[i] = a[i - 1] * 2ll;
                    x.erase(a[i]);
                }
                else
                {
                    a[i] = (*x.begin());
                    x.erase(x.begin());
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
}