#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool check(lol d[], lol m, lol c, lol n)
{
    lol cd = 1, l = d[0];
    for (lol i = 1; i < n; i++)
    {
        if (d[i] - l >= m)
        {
            cd++;
            l = d[i];
        }
    }
    return cd >= c;
}
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
        lol c;
        cin >> n >> c;
        lol d[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        sort(d, d + n);
        lol s = 0;
        lol e = d[n - 1] + 10;
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            if (check(d, m, c, n))
                s = m;
            else
                e = m;
        }
        cout << s<<endl;
    }

    return 0;
}