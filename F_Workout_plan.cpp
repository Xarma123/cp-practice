#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    lol x[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    lol A;
    cin >> A;
    priority_queue<lol> p;
    lol ans = 0;
    bool f = true;
    for (lol i = 0; i < n; i++)
    {
        lol c;
        cin >> c;
        p.push((-c));
        if (k < x[i])
        {
            while (k < x[i] && !p.empty())
            {
                k += A;

                ans += (-p.top());
                p.pop();
            }
        }
        if (k < x[i])
            f = false;
    }
    if (f)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}