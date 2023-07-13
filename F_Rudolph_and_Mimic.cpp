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
        lol f[10];
        memset(f, 0, sizeof(f));
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            f[a[i]]++;
        }
        lol c = 2;
        while (c--)
        {
            cout << "- " << 0 << endl;
            lol fnew[10];
            memset(fnew, 0, sizeof(fnew));
            for (lol i = 0; i < n; i++)
            {
                cin >> a[i];
                fnew[a[i]]++;
            }
            lol i;
            for (i = 0; i < 10; i++)
            {
                if (fnew[i] > f[i])
                {
                    c = i;
                    break;
                }
            }
            if (i < 10)
                break;
        }
        vector<lol> r;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] != c)
                r.push_back(i + 1);
        }
        cout << "- " << r.size();
        for (auto e : r)
            cout << " " << e;
        cout << endl;
        n -= (long long)r.size();
        lol ans = -1;
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] != c)
                ans = i + 1;
        }
        if (ans == -1)
        {
            cout << "- " << 0 << endl;
            for (lol i = 0; i < n; i++)
            {
                cin >> b[i];
                if (b[i] != c)
                    ans = i + 1;
            }
        }
        cout << "! " << ans << endl;
    }
}