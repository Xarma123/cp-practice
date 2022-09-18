#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, q;
    cin >> n >> q;
    deque<lol> a;
    lol mx = 0;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        a.push_back(t);
        if (a[i] > mx)
            mx = a[i];
    }
    map<lol, pair<lol, lol>> mp;

    lol i = 1;
    while (a[0] != mx)
    {
        mp[i] = make_pair(a[0], a[1]);
        if (a[0] <= a[1])
        {
            lol t = a.front();
            a.pop_front();
            a.push_back(t);
        }
        else
        {
            lol t = a[0];
            a.pop_front();
            a.push_back(a[0]);
            a.pop_front();
            a.push_front(t);
        }

        i++;
    }
    mp[i] = make_pair(a[0], a[1]);

    while (q--)
    {
        lol t;
        cin >> t;
        if (t < i)
            cout << mp[t].first << " " << mp[t].second << endl;
        else
        {
            lol in = t - i;
            if (n == 2)
                cout << a[0] << " " << a[1] << endl;
            else
                cout << a[0] << " " << a[in % (n - 1) + 1] << endl;
        }
    }

    return 0;
}