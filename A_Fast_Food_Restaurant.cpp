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
        lol a, b, c;
        cin >> a >> b >> c;
        lol ans = ((a > 0) + (b > 0) + (c > 0));
        a--;
        b--;
        c--;
        vector<lol> q(3);
        q[0] = a, q[1] = b, q[2] = c;
        sort(q.begin(), q.end());
        a = q[2], b = q[1], c = q[0];
        if (a > 0 && b > 0)
        {
            ans++;
            a--;
            b--;
        }
        if (a > 0 && c > 0)
        {
            ans++;
            a--;
            c--;
        }
        if (b > 0 && c > 0)
        {
            ans++;
            c--;
            b--;
        }
        if (a > 0 && b > 0 && c > 0)
        {
            ans++;
        }
        cout << ans << '\n';
    }
}