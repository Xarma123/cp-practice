#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol x[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    vector<lol> a, f;
    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        while (j < n && x[j] == x[i])
            j++;
        a.push_back(x[i]);
        f.push_back(j - i);
        i = j - 1;
    }

    lol q[a.size()];
    for (lol i = 0; i < a.size(); i++)
    {
        q[i] = f[i];
        if (i)
            q[i] += q[i - 1];
    }

    lol c[a.size()];
    lol c2[a.size()];
    for (lol i = 0; i < a.size(); i++)
    {
        c[i] = 0;
        c2[i] = 0;
        if (i)
        {
            c[i] += c[i - 1];
            c2[i] += c2[i - 1];
        }
        if (i - 1 >= 0 && i + 1 < a.size())
        {
            if (a[i] > a[i - 1] && a[i + 1] < a[i])
                c[i]++;
            else if (a[i] < a[i - 1] && a[i + 1] > a[i])
                c2[i]++;
        }
    }
    while (m--)
    {
        lol l, r;
        cin >> l >> r;
        lol st = -1, e = a.size() - 1;
        while (st != e - 1)
        {
            lol md = (st + e) / 2;
            if (md == -1)
                st = md;
            else if (q[md] >= l)
                e = md;
            else
                st = md;
        }
        lol ll = e;
        st = -1, e = a.size() - 1;
        while (st != e - 1)
        {
            lol md = (st + e) / 2;
            if (md == -1)
                st = md;
            else if (q[md] >= r)
                e = md;
            else
                st = md;
        }
        lol rr = e;
        if (rr - ll <= 1)
        {
            cout << "Yes" << '\n';
        }
        else
        {
            if (c2[rr - 1] - c2[ll] == 0 && c[rr - 1] - c[ll] <= 1)
                cout << "Yes" << '\n';
            else
                cout << "No" << '\n';
        }
    }

    return 0;
}