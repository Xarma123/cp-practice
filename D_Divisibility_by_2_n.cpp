#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol pw[31];
lol cal(lol a)
{
    lol s = 0;
    lol e = 30;
    while (s != e - 1)
    {
        lol m = (s + e) / 2;
        if ((a % (pw[m])) == 0)
            s = m;
        else
            e = m;
    }
    return s;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pw[0] = 1;
    for (lol i = 1; i <= 30; i++)
    {
        pw[i] = pw[i - 1] * 1ll * 2;
    }
    lol t;
    cin >> t;
    while (t--)
    {

        lol n;
        cin >> n;

        lol p = 1;
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            lol v;
            cin >> v;
            c += cal(v);
        }

        if (c >= n)
        {
            cout << 0 << endl;
        }
        else
        {
            vector<lol> q;
            for (lol i = 1; i <= n; i++)
            {
                lol c1 = cal(i);
                if (c1)
                    q.push_back(c1);
                
            }
            sort(q.rbegin(), q.rend());
            lol i = 0;
            while (i < q.size() && c < n)
            {
                c += q[i];
                i++;
            }
            if (c >= n)
            {
                cout << i << endl;
            }
            else
                cout << -1 << endl;
        }
    }

    return 0;
}