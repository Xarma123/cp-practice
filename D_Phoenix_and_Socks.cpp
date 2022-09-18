#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, l, r;
        cin >> n >> l >> r;
        vector<lol> cl;
        vector<lol> cr;

        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            if (l <= r)
            {

                if (i >= l)
                    cr.push_back(t);
                else
                    cl.push_back(t);
            }
            else
            {
                if (i >= l)
                    cl.push_back(t);
                else
                    cr.push_back(t);
            }
        }
        if (l > r)
        {
            swap(l, r);
        }
        if (cl.size() != 0)
            sort(cl.begin(), cl.end());
        if (cr.size() != 0)
            sort(cr.begin(), cr.end());
        lol i = 0, j = 0;
        while (i < l && j < r)
        {
            if (cl[i] == cr[j])
            {
                i++;
                j++;
                cr[j] = 0;
                cl[i] = 0;
            }
            else if (cr[j] > cl[i])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        lol ans = 0;

        if (cl.size() != 0)
            sort(cl.begin(), cl.end());
        if (cr.size() != 0)
            sort(cr.begin(), cr.end());

        for (i = 0; i < l; i++)
        {
            if (cl[i] != 0)
                break;
        }
        lol count = l - i;
        ans += count;

        for (i = 0; i < r; i++)
        {
            if (count == 0)
                break;
            if (i + 1 == r)
            {
                count--;
                cr[i] = 0;
            }
            else if (cr[i] == cr[i + 1])
            {
                i++;
            }
            else
            {
                count--;
                cr[i] = 0;
            }
        }
        if (cr.size() != 0)
            sort(cr.begin(), cr.end());
        for (i = 0; i < r; i++)
        {
            if (count == 0)
                break;
            if (cr[i] != 0)
            {
                count--;
                cr[i] = 0;
            }
        }
        if (cr.size() != 0)
            sort(cr.begin(), cr.end());
        for (i = 0; i < r - 1; i++)
        {
            if (cr[i] != 0)
            {
                if (cr[i] == cr[i + 1])
                {
                    ans++;
                    cr[i] = 0;
                    cr[i + 1] = 0;
                }
            }
        }
        if (cr.size() != 0)
            sort(cr.begin(), cr.end());
        for (i = 0; i < r; i++)
        {
            if (cr[i] != 0)
                break;
        }
        ans += ((r - i) / 2) * 2;
        cout << ans << endl;
    }

    return 0;
}