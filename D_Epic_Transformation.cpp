#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool cmp(pair<lol, lol> a, pair<lol, lol> b)
{
    return a.second > b.second;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        map<lol, lol> mp;

        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            mp[q]++;
        }
        priority_queue<lol> f;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            f.push((*i).second);
        }

        while (f.size() > 1)
        {
            lol m = f.top();
            f.pop();
            lol n = f.top();
            f.pop();
            m--;
            n--;
            if (m != 0)
                f.push(m);
            if (n != 0)
                f.push(n);
        }
        if (f.size() == 0)
            cout << 0 << endl;
        else
        {
            cout << f.top() << endl;
        }
    }

    return 0;
}