#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b;
    cin >> a >> b;
    lol n;
    cin >> n;
    vector<lol> da;
    for (lol i = 1; i * 1ll * i <= a; i++)
    {
        if (a % i == 0)
        {
            da.push_back(i);
            if (a / i != i)
            {
                da.push_back(a / i);
            }
        }
    }
    set<lol> db;
    for (lol i = 1; i * 1ll * i <= b; i++)
    {
        if (b % i == 0)
        {
            db.insert(i);
            if (b / i != i)
            {
                db.insert(b / i);
            }
        }
    }
    vector<lol> com;
    for (lol i = 0; i < da.size(); i++)
    {
        if (db.count(da[i]))
        {
            com.push_back(da[i]);
        }
    }
    sort(com.begin(), com.end());

    while (n--)
    {
        lol l, r;
        cin >> l >> r;
        lol i = upper_bound(com.begin(), com.end(), r) - com.begin();
        lol ans = -1;
        i--;
        if (i >= 0)
        {
            if (com[i] >= l)
            {
                ans = com[i];
            }
        }
        cout << ans << endl;
    }

    return 0;
}