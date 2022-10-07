#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        vector<pair<lol, lol>> p;
        for (lol i = 0; i < 3; i++)
        {
            lol a, b;
            cin >> a >> b;
            p.push_back({b, a});
        }
        lol x, y;
        cin >> x >> y;
        sort(p.begin(), p.end());
        bool f = false;
        if (p[0].first == 1)
        {
            if (p[0].second == 1 && p[1].first == 1 && p[1].second == 2 && p[2].first == 2 && p[2].second == 1)
                f = true;
            if (p[0].second == n - 1 && p[1].first == 1 && p[1].second == n && p[2].first == 2 && p[2].second == n)
                f = true;
        }
        if (p[0].first == n - 1)
        {
            if (p[0].second == 1 && p[1].first == n && p[1].second == 1 && p[2].first == n && p[2].second == 2)
                f = true;
            if (p[0].second == n && p[1].first == n && p[1].second == n - 1 && p[2].first == n && p[2].second == n)
                f = true;
        }
        if (f)
        {
            if (p[0].first == 1 && p[0].second == 1)
            {
                if (x == 1 || y == 1)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else if (p[0].first == 1 && p[0].second == n - 1)
            {
                if (x == n || y == 1)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else if (p[0].first == n - 1 && p[0].second == 1)
            {
                if (x == 1 || y == n)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else
            {
                if (x == n || y == n)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
        else
        {
            lol c, r;

            c = p[1].first;
            map<lol, lol> ded;
            for (lol i = 0; i < 3; i++)
            {
                if (++ded[p[i].second] == 2)
                    r = p[i].second;
            }
            if ((c % 2) == (y % 2) || (r % 2) == (x % 2))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}