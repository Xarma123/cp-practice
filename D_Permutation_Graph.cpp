#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol pmx[300000], pmn[300000];
lol smx[300000], smn[300000];
lol solve(lol i, lol j, bool mx, bool l)
{
    if (i == j - 1)
        return 1;
    if (i == j)
        return 0;
    if (l)
    {
        if (mx)
        {
            lol k = pmx[j];
            if (k != j)
                return solve(i, k, false,l) + 1;
            else
                return solve(i, k, false,l);
        }
        else
        {
            lol k = pmn[j];
            if (k != j)
                return solve(i, k, true,l) + 1;
            else
                return solve(i, k, true,l);
        }
    }
    else
    {
        if (mx)
        {
            lol k = smx[i];
            if (i != k)
                return solve(k, j, false,l) + 1;
            else
                return solve(k, j, false,l);
        }
        else
        {
            lol k = smn[i];
            if (i != k)
                return solve(k, j, true,l) + 1;
            else
                return solve(k, j, true,l);
        }
    }
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
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1)
            cout << 0 << '\n';
        else
        {
            for (lol i = 0; i < n; i++)
            {
                if (i == 0)
                    pmx[i] = i, pmn[i] = i;
                else
                {
                    pmx[i] = pmx[i - 1];
                    if (a[pmx[i]] < a[i])
                    {
                        pmx[i] = i;
                    }
                    pmn[i] = pmn[i - 1];
                    if (a[pmn[i]] > a[i])
                    {
                        pmn[i] = i;
                    }
                }
            }
            for (lol i = n - 1; i >= 0; i--)
            {

                if (i == n - 1)
                    smx[i] = i, smn[i] = i;
                else
                {

                    smx[i] = smx[i + 1];
                    if (a[smx[i]] < a[i])
                    {
                        smx[i] = i;
                    }
                    smn[i] = smn[i + 1];
                    if (a[smn[i]] > a[i])
                    {
                        smn[i] = i;
                    }
                }
            }
            lol k = pmx[n - 1];
            cout << solve(0, k, false, true) + solve(k, n - 1, false, false) << '\n';
        }
    }

    return 0;
}