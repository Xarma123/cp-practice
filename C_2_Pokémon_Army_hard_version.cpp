#include <bits/stdc++.h>
using namespace std;
#define lol long long

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, q;
        cin >> n >> q;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        set<lol> mxi, mni;
        lol mx = 0, mn = 0;
        for (lol i = 0; i < n; i++)
        {
            lol l = LONG_LONG_MIN;
            lol r = LONG_LONG_MIN;
            if (i - 1 >= 0)
                l = a[i - 1];
            if (i + 1 < n)
                r = a[i + 1];
            if (a[i] >= l && a[i] > r)
            {
                mx += a[i];
                mxi.insert(-i);
            }
            if (a[i] < l && a[i] <= r)
            {
                mn += a[i];
                mni.insert(-i);
            }
        }

        if (-(*mni.begin()) > -(*mxi.begin()))
        {
            cout << mx - mn + a[-(*mni.begin())];
        }
        else
        {
            cout << mx - mn;
        }
        cout << '\n';
        
        while (q--)
        {
            lol a1, a2;
            cin >> a1 >> a2;
            a1--;
            a2--;
            if (a1 == a2 - 1)
            { 
                
                if (a1 - 1 >= 0)
                {
                    lol i = a1 - 1;
                    lol l = LONG_LONG_MIN;
                    lol r = LONG_LONG_MIN;
                    if (i - 1 >= 0)
                        l = a[i - 1];
                    if (i + 1 < n)
                        r = a[i + 1];
                    if (a[i] >= l && a[i] > r)
                    {
                        mx -= a[i];
                        mxi.erase(-i);
                    }
                    if (a[i] < l && a[i] <= r)
                    {
                        mn -= a[i];
                        mni.erase(-i);
                    }
                }
                if (1)
                {
                    lol i = a1;
                    lol l = LONG_LONG_MIN;
                    lol r = LONG_LONG_MIN;
                    if (i - 1 >= 0)
                        l = a[i - 1];
                    if (i + 1 < n)
                        r = a[i + 1];
                    if (a[i] >= l && a[i] > r)
                    {
                        mx -= a[i];
                        mxi.erase(-i);
                    }
                    if (a[i] < l && a[i] <= r)
                    {
                        mn -= a[i];
                        mni.erase(-i);
                    }
                }
                
                if (a1 + 1 < n)
                {
                    lol i = a1 + 1;
                    lol l = LONG_LONG_MIN;
                    lol r = LONG_LONG_MIN;
                    if (i - 1 >= 0)
                        l = a[i - 1];
                    if (i + 1 < n)
                        r = a[i + 1];
                    if (a[i] >= l && a[i] > r)
                    {
                        mx -= a[i];
                        mxi.erase(-i);
                    }
                    if (a[i] < l && a[i] <= r)
                    {
                        mn -= a[i];
                        mni.erase(-i);
                    }
                }
                
                if (a1 + 2 < n)
                {
                    lol i = a1 + 2;
                    lol l = LONG_LONG_MIN;
                    lol r = LONG_LONG_MIN;
                    if (i - 1 >= 0)
                        l = a[i - 1];
                    if (i + 1 < n)
                        r = a[i + 1];
                    if (a[i] >= l && a[i] > r)
                    {
                        mx -= a[i];
                        mxi.erase(-i);
                    }
                    if (a[i] < l && a[i] <= r)
                    {
                        mn -= a[i];
                        mni.erase(-i);
                    }
                }
                
                swap(a[a1], a[a2]);
                if (a1 - 1 >= 0)
                {
                    lol i = a1 - 1;
                    lol l = LONG_LONG_MIN;
                    lol r = LONG_LONG_MIN;
                    if (i - 1 >= 0)
                        l = a[i - 1];
                    if (i + 1 < n)
                        r = a[i + 1];
                    if (a[i] >= l && a[i] > r)
                    {
                        mx += a[i];
                        mxi.insert(-i);
                    }
                    if (a[i] < l && a[i] <= r)
                    {
                        mn += a[i];
                        mni.insert(-i);
                    }
                }
                if (1)
                {
                    lol i = a1;
                    lol l = LONG_LONG_MIN;
                    lol r = LONG_LONG_MIN;
                    if (i - 1 >= 0)
                        l = a[i - 1];
                    if (i + 1 < n)
                        r = a[i + 1];
                    if (a[i] >= l && a[i] > r)
                    {
                        mx += a[i];
                        mxi.insert(-i);
                    } 
                    
                    if (a[i] < l && a[i] <= r)
                    {
                        mn += a[i];
                        mni.insert(-i);
                    }
                }
                
                if (a1 + 1 < n)
                {
                    lol i = a1 + 1;
                    lol l = LONG_LONG_MIN;
                    lol r = LONG_LONG_MIN;
                    if (i - 1 >= 0)
                        l = a[i - 1];
                    if (i + 1 < n)
                        r = a[i + 1];
                    if (a[i] >= l && a[i] > r)
                    {
                        mx += a[i];
                        mxi.insert(-i);
                    }
                    if (a[i] < l && a[i] <= r)
                    {
                        mn += a[i];
                        mni.insert(-i);
                    }
                }
                if (a1 + 2 < n)
                {
                    lol i = a1 + 2;
                    lol l = LONG_LONG_MIN;
                    lol r = LONG_LONG_MIN;
                    if (i - 1 >= 0)
                        l = a[i - 1];
                    if (i + 1 < n)
                        r = a[i + 1];
                    if (a[i] >= l && a[i] > r)
                    {
                        mx += a[i];
                        mxi.insert(-i);
                    }
                    if (a[i] < l && a[i] <= r)
                    {
                        mn += a[i];
                        mni.insert(-i);
                    }
                }
                if (-(*mni.begin()) > -(*mxi.begin()))
                {
                    cout << mx - mn + a[-(*mni.begin())];
                }
                else
                {
                    cout << mx - mn;
                }
                cout << '\n';
                continue;
            }
            lol x = a[a1], y = a[a2];
            if (a1 - 1 >= 0)
            {
                lol i = a1 - 1;
                lol l = LONG_LONG_MIN;
                lol r = LONG_LONG_MIN;
                if (i - 1 >= 0)
                    l = a[i - 1];
                if (i + 1 < n)
                    r = a[i + 1];
                if (a[i] >= l && a[i] > r)
                {
                    mx -= a[i];
                    mxi.erase(-i);
                }
                if (a[i] < l && a[i] <= r)
                {
                    mn -= a[i];
                    mni.erase(-i);
                }
            }
            if (1)
            {
                lol i = a1;
                lol l = LONG_LONG_MIN;
                lol r = LONG_LONG_MIN;
                if (i - 1 >= 0)
                    l = a[i - 1];
                if (i + 1 < n)
                    r = a[i + 1];
                if (a[i] >= l && a[i] > r)
                {
                    mx -= a[i];
                    mxi.erase(-i);
                }
                if (a[i] < l && a[i] <= r)
                {
                    mn -= a[i];
                    mni.erase(-i);
                }
            }
            if (a1 + 1 < n)
            {
                lol i = a1 + 1;
                lol l = LONG_LONG_MIN;
                lol r = LONG_LONG_MIN;
                if (i - 1 >= 0)
                    l = a[i - 1];
                if (i + 1 < n)
                    r = a[i + 1];
                if (a[i] >= l && a[i] > r)
                {
                    mx -= a[i];
                    mxi.erase(-i);
                }
                if (a[i] < l && a[i] <= r)
                {
                    mn -= a[i];
                    mni.erase(-i);
                }
            }
            a[a1] = y;
            if (a1 - 1 >= 0)
            {
                lol i = a1 - 1;
                lol l = LONG_LONG_MIN;
                lol r = LONG_LONG_MIN;
                if (i - 1 >= 0)
                    l = a[i - 1];
                if (i + 1 < n)
                    r = a[i + 1];
                if (a[i] >= l && a[i] > r)
                {
                    mx += a[i];
                    mxi.insert(-i);
                }
                if (a[i] < l && a[i] <= r)
                {
                    mn += a[i];
                    mni.insert(-i);
                }
            }
            if (1)
            {
                lol i = a1;
                lol l = LONG_LONG_MIN;
                lol r = LONG_LONG_MIN;
                if (i - 1 >= 0)
                    l = a[i - 1];
                if (i + 1 < n)
                    r = a[i + 1];
                if (a[i] >= l && a[i] > r)
                {
                    mx += a[i];
                    mxi.insert(-i);
                }
                if (a[i] < l && a[i] <= r)
                {
                    mn += a[i];
                    mni.insert(-i);
                }
            }
            if (a1 + 1 < n)
            {
                lol i = a1 + 1;
                lol l = LONG_LONG_MIN;
                lol r = LONG_LONG_MIN;
                if (i - 1 >= 0)
                    l = a[i - 1];
                if (i + 1 < n)
                    r = a[i + 1];
                if (a[i] >= l && a[i] > r)
                {
                    mx += a[i];
                    mxi.insert(-i);
                }
                if (a[i] < l && a[i] <= r)
                {
                    mn += a[i];
                    mni.insert(-i);
                }
            }
            swap(a1, a2);
            swap(x, y);
            if (a1 - 1 >= 0)
            {
                lol i = a1 - 1;
                lol l = LONG_LONG_MIN;
                lol r = LONG_LONG_MIN;
                if (i - 1 >= 0)
                    l = a[i - 1];
                if (i + 1 < n)
                    r = a[i + 1];
                if (a[i] >= l && a[i] > r)
                {
                    mx -= a[i];
                    mxi.erase(-i);
                }
                if (a[i] < l && a[i] <= r)
                {
                    mn -= a[i];
                    mni.erase(-i);
                }
            }
            if (1)
            {
                lol i = a1;
                lol l = LONG_LONG_MIN;
                lol r = LONG_LONG_MIN;
                if (i - 1 >= 0)
                    l = a[i - 1];
                if (i + 1 < n)
                    r = a[i + 1];
                if (a[i] >= l && a[i] > r)
                {
                    mx -= a[i];
                    mxi.erase(-i);
                }
                if (a[i] < l && a[i] <= r)
                {
                    mn -= a[i];
                    mni.erase(-i);
                }
            }
            if (a1 + 1 < n)
            {
                lol i = a1 + 1;
                lol l = LONG_LONG_MIN;
                lol r = LONG_LONG_MIN;
                if (i - 1 >= 0)
                    l = a[i - 1];
                if (i + 1 < n)
                    r = a[i + 1];
                if (a[i] >= l && a[i] > r)
                {
                    mx -= a[i];
                    mxi.erase(-i);
                }
                if (a[i] < l && a[i] <= r)
                {
                    mn -= a[i];
                    mni.erase(-i);
                }
            }
            a[a1] = y;
            if (a1 - 1 >= 0)
            {
                lol i = a1 - 1;
                lol l = LONG_LONG_MIN;
                lol r = LONG_LONG_MIN;
                if (i - 1 >= 0)
                    l = a[i - 1];
                if (i + 1 < n)
                    r = a[i + 1];
                if (a[i] >= l && a[i] > r)
                {
                    mx += a[i];
                    mxi.insert(-i);
                }
                if (a[i] < l && a[i] <= r)
                {
                    mn += a[i];
                    mni.insert(-i);
                }
            }
            if (1)
            {
                lol i = a1;
                lol l = LONG_LONG_MIN;
                lol r = LONG_LONG_MIN;
                if (i - 1 >= 0)
                    l = a[i - 1];
                if (i + 1 < n)
                    r = a[i + 1];
                if (a[i] >= l && a[i] > r)
                {
                    mx += a[i];
                    mxi.insert(-i);
                }
                if (a[i] < l && a[i] <= r)
                {
                    mn += a[i];
                    mni.insert(-i);
                }
            }
            if (a1 + 1 < n)
            {
                lol i = a1 + 1;
                lol l = LONG_LONG_MIN;
                lol r = LONG_LONG_MIN;
                if (i - 1 >= 0)
                    l = a[i - 1];
                if (i + 1 < n)
                    r = a[i + 1];
                if (a[i] >= l && a[i] > r)
                {
                    mx += a[i];
                    mxi.insert(-i);
                }
                if (a[i] < l && a[i] <= r)
                {
                    mn += a[i];
                    mni.insert(-i);
                }
            }
            if (-(*mni.begin()) > -(*mxi.begin()))
            {
                cout << mx - mn + a[-(*mni.begin())];
            }
            else
            {
                cout << mx - mn;
            }
            cout << '\n';
        }
    }
}