#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol mn, mx;
    cin >> mn >> mx;
    vector<lol> mnind, mxind;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] == mn)
        {
            mnind.push_back(i);
        }
        if (a[i] == mx)
        {
            mxind.push_back(i);
        }
    }

    stack<lol> x;
    x.push(-1);
    lol pmn[n];
    for (lol i = 0; i < n; i++)
    {
        while (x.top() != -1 && a[x.top()] >= a[i])
            x.pop();
        pmn[i] = x.top();
        x.push(i);
    }
    while (x.top() != -1)
        x.pop();
    lol nmn[n];
    for (lol i = 0; i < n; i++)
    {
        while (x.top() != -1 && a[x.top()] > a[i])
        {
            nmn[x.top()] = i;
            x.pop();
        }
        x.push(i);
    }
    while (x.top() != -1)
    {
        nmn[x.top()] = n;
        x.pop();
    }

    lol pmx[n];
    for (lol i = 0; i < n; i++)
    {
        while (x.top() != -1 && a[x.top()] <= a[i])
            x.pop();
        pmx[i] = x.top();
        x.push(i);
    }
    while (x.top() != -1)
        x.pop();
    lol nmx[n];
    for (lol i = 0; i < n; i++)
    {
        while (x.top() != -1 && a[x.top()] < a[i])
        {
            nmx[x.top()] = i;
            x.pop();
        }
        x.push(i);
    }
    while (x.top() != -1)
    {
        nmx[x.top()] = n;
        x.pop();
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        lol j = lower_bound(mnind.begin(), mnind.end(), i) - mnind.begin();
        if (j == mnind.size())
            continue;
        lol j1 = lower_bound(mxind.begin(), mxind.end(), i) - mxind.begin();
        if (j1 == mxind.size())
            continue;
        j = mnind[j];
        j1 = mxind[j1];
        if (pmn[j] >= i || pmx[j1] >= i)
            continue;
        ans += min(nmn[j], nmx[j1]) - max(j, j1);
    }
    cout << ans;

    return 0;
}