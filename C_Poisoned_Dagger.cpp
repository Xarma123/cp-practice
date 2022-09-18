#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, h;
vector<lol> a;
bool check(lol k)
{
    lol d = 0;
    for (lol i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            if (a[i] + k - 1 < a[i + 1])
            {
                d += k;
            }
            else
            {
                d += a[i + 1] - a[i];
            }
        }
        else
        {
            d += k;
        }
    }
    return d >= h;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {

        cin >> n >> h;

        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            a.push_back(t);
        }
        lol s = 0;
        lol e = 1e18;
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            if (check(m))
            {
                e = m;
            }
            else
                s = m;
        }
        cout << e << endl;
        a.erase(a.begin(),a.end());
    }
    return 0;
}