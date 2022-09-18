#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool cmp(map<char, lol> a, map<char, lol> b)
{
    if (a.size() != b.size())
        return false;
    for (auto i = a.begin(), j = b.begin(); i != a.end() && j != b.end(); i++, j++)
    {
        if ((*i) != (*j))
            return false;
    }
    return true;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string p;
        cin >> p;
        map<char, lol> x;
        lol n = p.size();
        for (lol i = 0; i < n; i++)
        {
            x[p[i]]++;
        }
        string h;
        cin >> h;

        if (h.size() < n)
        {
            cout << "NO" << endl;
        }
        else
        {
            map<char, lol> x2;
            lol c = h.size();
            lol t = 0;
            bool f = false;
            while (n + t <= c)
            {
                x2.clear();
                for (lol i = t; i < n + t; i++)
                {
                    x2[h[i]]++;
                }
                if (cmp(x, x2))
                {
                    f = true;
                    break;
                }
                t++;
            }
            if (f)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}