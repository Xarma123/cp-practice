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
        lol k;
        cin >> k;
        lol c[k];
        lol s = 0;
        for (lol i = 0; i < k; i++)
        {
            cin >> c[i];
            s += c[i];
        }

        vector<lol> f(1, 1), d(1, 1);
        while (d.back() < s)
        {
            if (f.size() > 1)
            {
                f.push_back(f.back() + f[f.size() - 2]);
                d.push_back(d.back() + f.back());
            }
            else
            {
                f.push_back(1);
                d.push_back(2);
            }
        }
        if (d.back() != s)
        {
            cout << "NO\n";
        }
        else
        {
            multiset<lol> x;
            for (lol i = 0; i < k; i++)
            {
                x.insert(-c[i]);
            }
            lol l = 0;
            while (f.size() > 0 && x.size() > 0)
            {
                auto it = x.begin();
                lol v = (*it);
                v = -v;
                x.erase(it);
                if (v < f.back())
                    break;
                v -= f.back();
                f.pop_back();
                if (l != 0)
                {
                    x.insert(l);
                }
                l = -v;
            }
            if (f.size() > 0)
            {
                cout << "NO\n";
            }
            else
                cout << "YES\n";
        }
    }
    return 0;
}