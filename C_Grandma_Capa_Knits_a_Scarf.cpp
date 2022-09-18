#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol ans(string a, char c)
{
    lol q = 0;
    lol s = 0;
    lol e = a.size() - 1;
    while (s < e)
    {
        if (a[s] == a[e])
        {
            s++;
            e--;
        }
        else
        {
            if (a[s] == c)
            {
                q++;
                s++;
            }
            else if (a[e] == c)
            {
                q++;
                e--;
            }
            else
                return LONG_LONG_MAX;
        }
    }
    return q;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string a;
        cin >> a;
        lol s = 0, e = n - 1;
        while (s < e)
        {
            if (a[s] != a[e])
            {
                break;
            }
            else
            {
                s++;
                e--;
            }
        }
        if (s >= e)
        {
            cout << 0 << endl;
        }
        else
        {
            lol ANS = min(ans(a, a[s]), ans(a, a[e]));
            if (ANS == LONG_LONG_MAX)
                cout << -1 << endl;
            else
                cout << ANS << endl;
        }
    }

    return 0;
}