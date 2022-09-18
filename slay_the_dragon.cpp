
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long lol n;
    cin >> n;
    long long lol a[n];
    long long lol sum = 0;
    for (long long lol i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    long long lol m, cj = sum;
    cin >> m;
    sort(a, a + n);
    while (m--)
    {
        long long lol ds, s, ans, res;

        cin >> ds;
        long long lol da;
        cin >> da;

        long long u = lower_bound(a, a + n, sum - da) - a;
        if (u == n)
        {
            if (a[n - 1] >= ds)
            {
                cout << 0 << endl;
                continue;
            }
            else
            {
                cout << ds - a[n - 1] << endl;
                continue;
            }
        }
        else
        {
            if (a[u] != sum - da)
                u = u - 1;
            long long v = lower_bound(a, a + n, ds) - a;
         
            if(v<=u)
            {
                cout<<0<<endl;
                continue;
            }
            else
            {      ans = 0;
                    if (a[u] < ds)
                    {
                        ans += ds - a[u];
                    }
                    if (sum - a[u] < da)
                    {
                        ans += da - (sum - a[u]);
                    }
                    cout << ans << endl;
                    continue;

               

            }
        }

        // if (sum - a[n - 1] >= da)
        // {
        //     if (a[n - 1] >= ds)
        //     {
        //         cout << 0 << endl;
        //         continue;
        //     }
        //     else
        //     {
        //         cout << ds - a[n - 1] << endl;
        //     }
        // } // correct
        // else
        // {
        //     long long u = (lower_bound(a, a + n, sum - da) - a);
        //     // if (u == n)
        //     // {
        //     //     long long v = (lower_bound(a, a + n, ds) - a);
        //     //     if (v == n)
        //     //     {
        //     //         // cout << max(da + a[0] - sum, ds + da - sum, ds - a[0]) << endl;
        //     //         ans = 0;
        //     //         if (a[0] < ds)
        //     //         {
        //     //             ans += ds - a[0];
        //     //         }
        //     //         if (sum - a[0] < da)
        //     //         {
        //     //             ans += da - (sum - a[0]);
        //     //         }
        //     //         cout << ans << endl;
        //     //         continue;
        //     //     }
        //     //     else
        //     //     {
        //     //         // cout << max(da + a[v] - sum, ds + da - sum, ds - a[v]) << endl;
        //     //         ans = 0;

        //     //         if (a[v-1] < ds)
        //     //         {
        //     //             ans += ds - a[v-1];
        //     //         }
        //     //         if (sum - a[v-1] < da)
        //     //         {
        //     //             ans += da - (sum - a[v-1]);
        //     //         }
        //     //         cout << ans << endl;
        //     //         continue;
        //     //     }
        //     // } //corrected

        //     long long v = (lower_bound(a, a + n, ds) - a);
        //     if (v == n)
        //     {
        //         for (long long lol i = 0; i <= u; i++)
        //         {
        //             ans = 0;
        //             if (a[i] < ds)
        //             {
        //                 ans += ds - a[i];
        //             }
        //             if (sum - a[i] < da)
        //             {
        //                 ans += da - (sum - a[i]);
        //             }
        //             if (i == u)
        //                 res = ans;
        //             else
        //                 res = min(res, ans);
        //         }
        //         cout << res << endl;
        //         continue;
        //     }
        //     else
        //     { if(a[u-1]==sum-da) u=u-1;
        //         if(a[v-1]==ds)v=v-1;
        //         if (v <= u )
        //         {
        //             cout << 0 << endl;
        //             continue;
        //         }
        //         else
        //         {
        //             // cout << max(da + a[v] - sum, ds + da - sum, ds - a[v]) << endl;
        //             ans = 0;
        //             if (a[v] < ds)
        //             {
        //                 ans += ds - a[v];
        //             }
        //             if (sum - a[v] < da)
        //             {
        //                 ans += da - (sum - a[v]);
        //             }
        //             cout << ans << endl;
        //             continue;
        //         }
        //     }
        // }
    }
}