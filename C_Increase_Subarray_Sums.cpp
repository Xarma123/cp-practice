#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{   unordered_set<lol> x;
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x;
        cin >> n >> x;
        lol a[n];
        bool give[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];

            give[i] = false;
        }

        lol N = n;
        stack<lol> ans;
        lol s = -1;
        lol e = -1;
        N++;
        while (N--)
        { 

            if (s != -1)
            {
                if (s == e)
                {
                    lol mxind = -1;
                    for (lol i = 0; i < n; i++)
                    {
                        if (!give[i])
                        {
                            if (mxind == -1)
                                mxind = i;
                            else
                            {
                                if (a[i] > a[mxind])
                                    mxind = i;
                            }
                        }
                    }
                    give[mxind] = true;
                    a[mxind] += x;
                }
                else
                {
                    s--;
                    e--;
                    bool done = false;
                    for (lol i = s + 1; i <= e; i++)
                    {
                        if (!give[i])
                        {
                            give[i] = true;
                            a[i] += x;
                            done = true;
                            break;
                        }
                    }
                    if (!done)
                    {
                        lol mxind = -1;
                       
                        for (lol i = s; i >= 0; i--)
                        {
                            if (!give[i])
                            {
                                mxind = i;
                                break;
                            }
                        }
                      
                        for (lol i = e + 1; i < n; i++)
                        {
                            if (!give[i])
                            {
                                if (mxind == -1)
                                    mxind = i;
                                else if (a[mxind] < a[i])
                                {
                                    mxind = i;
                                }
                                break;
                            }
                        }

                        give[mxind] = true;
                        a[mxind] += x;
                    }
                }
            }
            lol c[n + 1];
            for (lol i = 0; i <= n; i++)
            {
                if (i == 0)
                    c[i] = 0;
                else
                {
                    c[i] = c[i - 1] + a[i - 1];
                }
            }
            lol mn = -1;

            lol mx = LONG_LONG_MIN;
            for (lol i = 0; i <= n; i++)
            {
                if (mn == -1)
                {
                    s = i;
                    mn = i;
                    mx = 0;
                    e = i;
                }
                else
                {
                    if (c[i] <= c[mn])
                    {
                        mn = i;
                    }
                    if (c[i] - c[mn] > mx)
                    {
                        s = mn;
                        e = i;
                        mx = c[i] - c[mn];
                    }
                    else if (c[i] - c[mn] == mx)
                    {
                        if (i - mn <= e - s)
                        {
                            s = mn;
                            e = i;
                        }
                    }
                }
            }
            ans.push(mx);
        }

        while (!ans.empty())
        {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }

    return 0;
}