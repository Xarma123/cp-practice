#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[2ll * n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            a[i + n] = a[i];
        }
        lol suf[n];
        for (lol i = n - 1; i >= 0; i--)
        {
            suf[i] = a[i];
            if (i < n - 1)
                suf[i] = min(suf[i], suf[i + 1]);
        }
        deque<pair<lol, lol>> q;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && suf[j] == suf[i])
                j++;
            q.push_back({suf[i], j - i});
            ans += suf[i] * 1ll * (j - i);
            i = j - 1;
        }
        lol cans = ans;
        n = n * 2ll;
        for (lol i = 0; i < n; i++)
        {
            pair<lol, lol> fr = q.front();
            q.pop_front();
            fr.second--;
            cans -= fr.first;
            if (fr.second)
                q.push_front(fr);
            fr = {a[i], 1};
            while (q.size() && q.back().first >= a[i])
            {
                cans -= q.back().first * 1ll * q.back().second;
                fr.second += q.back().second;
                q.pop_back();
            }
            cans += fr.first * 1ll * fr.second;
            q.push_back(fr);
            ans = max(ans, cans);
        }
        cout << ans + (n / 2ll) << '\n';
    }

    return 0;
}
