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
        lol n, m;
        cin >> n >> m;
        deque<lol> a(n), b(m);
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        lol ans = 0;
        while (n--)
        {
            if (abs(a.front() - b.back()) >= abs(a.back() - b.front()))
                ans += abs(a.front() - b.back()), a.pop_front(), b.pop_back();
            else
                ans += abs(a.back() - b.front()), a.pop_back(), b.pop_front();
        }
        cout << ans << '\n';
    }

    return 0;
}
