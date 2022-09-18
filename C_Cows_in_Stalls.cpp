#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> a;
lol n, k;
bool check(lol d)
{
    lol st = a[0];
    lol c = 1;
    for (lol i = 1; i < n; i++)
    {
        if (a[i] - st  >= d)
        {
            st = a[i];
            c++;
        }
    }
    return c >= k;
}
int main()
{
    cin >> n >> k;

    lol s = 0;
    lol e = 1e10;

    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        a.push_back(t);
    }

    while (s != e - 1)
    {
        lol m = (s + e) / 2;
        if (check(m))
            s = m;
        else
            e = m;
    }
    cout << s;

    return 0;
}