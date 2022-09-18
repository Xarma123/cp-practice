#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, d;
        cin >> n >> d;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol u = a[0] - 1;
        lol j = 0;
        lol cj = 1;
        for (lol i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] - 1 < u)
            {
                u = a[i] - a[i - 1] - 1;
                j = i;
                cj = 1;
            }
            else if (a[i] - a[i - 1] - 1 == u)
            {
                cj++;
            }
        }

        lol j0 = j - 1;
        vector<lol> ans;
        for (lol i = 0; i < n; i++)
        {
            if (i != j)
            {
                ans.push_back(a[i]);
            }
        }
        lol mngap = LONG_LONG_MAX;
        lol mxgap = LONG_LONG_MIN;
        for (lol i = 0; i < ans.size(); i++)
        {
            if (i == 0)
            {
                mngap = min(mngap, ans[i] - 1);
                mxgap = max(mxgap, ans[i] - 1);
            }
            else
            {
                mngap = min(mngap, ans[i] - ans[i - 1] - 1);
                mxgap = max(mxgap, ans[i] - ans[i - 1] - 1);
            }
        }

        if (mxgap % 2 != 0)
            u = max(u, min(mxgap / 2, mngap));
        else
        {
            u = max(u, min((mxgap / 2) - 1, mngap));
        }

        if (ans[ans.size() - 1] < d)
        {
            u = max(u, min(d - ans[ans.size() - 1] - 1, mngap));
        }

        if (j0 >= 0)
        {
            ans.clear();
            for (lol i = 0; i < n; i++)
            {
                if (i != j0)
                {
                    ans.push_back(a[i]);
                }
            }
            mngap = LONG_LONG_MAX;
            mxgap = LONG_LONG_MIN;
            for (lol i = 0; i < ans.size(); i++)
            {

                if (i == 0)
                {
                    mngap = min(mngap, ans[i] - 1);
                    mxgap = max(mxgap, ans[i] - 1);
                }
                else
                {
                    mngap = min(mngap, ans[i] - ans[i - 1] - 1);
                    mxgap = max(mxgap, ans[i] - ans[i - 1] - 1);
                }
            }

            if (mxgap % 2 != 0)
                u = max(u, min(mxgap / 2, mngap));
            else
            {
                u = max(u, min((mxgap / 2) - 1, mngap));
            }

            if (ans[ans.size() - 1] < d)
            {
                u = max(u, min(d - ans[ans.size() - 1] - 1, mngap));
            }
        }
        cout << u << endl;
    }

    return 0;
}