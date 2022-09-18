#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    pair<lol, lol> a[n];
    stack<lol> x;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (x.size() == 0)
        {
            ans++;
            x.push(a[i].second);
        }
        else
        {
            while (x.size() && x.top() > a[i].second)
            {
                x.pop();
            }
            if (x.size() == 0)
            {
                ans++;
                x.push(a[i].second);
            }
            else if (x.top() == a[i].second)
            {
                continue;
            }
            else
            {
                ans++;
                x.push(a[i].second);
            }
        }
    }
    cout << ans;

    return 0;
}