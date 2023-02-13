#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    lol p[a.size()];
    for (lol i = 0; i < a.size(); i++)
    {
        cin >> p[i];
    }
    lol s = 0, e = a.size();
    while (s != e - 1)
    {
        lol m = (s + e) / 2;
        if (m == 0)
        {
            s = m;
        }
        else if (m == a.size())
        {
            e = m;
        }
        else
        {
            set<lol> x;
            for (lol i = 0; i < m; i++)
            {
                x.insert(p[i] - 1);
            }
            lol j = 0;
            for (lol i = 0; i < a.size() && j < b.size(); i++)
            {
                if (x.count(i))
                    continue;
                if (a[i] == b[j])
                    j++;
            }
            if (j == b.size())
                s = m;
            else
                e = m;
        }
    }
    cout << s;

    return 0;
}