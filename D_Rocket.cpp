#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol m, n;
    cin >> m >> n;
    lol p[n];
    for (lol i = 0; i < n; i++)
    {
        cout << 1 << endl;
        lol a;
        cin >> a;
        p[i] = a;
        if (a == 0)
            return 0;
    }
    lol s = 1, e = m;
    lol i = 0;
    while (s <= e)
    {
        lol md = (s + e) / 2ll;
        cout << md << endl;
        lol a;
        cin >> a;
        if (p[i] == -1)
            a = -a;
        i++;
        i %= n;
        if (a == -1)
        {
            e = md - 1;
        }
        else if (a == 1)
        {
            s = md + 1;
        }
        else
            return 0;
    }
}