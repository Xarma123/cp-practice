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
        string s;
        cin >> s;
        lol p;
        cin >> p;
        lol cost = 0;
        bool use[s.size()];
        memset(use, true, sizeof(use));
        pair<char, lol> a[s.size()];
        for (lol i = 0; i < s.size(); i++)
        {
            a[i].first = s[i];
            cost += s[i] - 'a' + 1;
            a[i].second = i;
        }
        sort(a, a + s.size());
        lol j = s.size() - 1;
        while (cost > p && j >= 0)
        {
            use[a[j].second] = false;
            cost -= a[j].first - 'a' + 1;
            j--;
        }
        bool f = true;
        for (lol i = 0; i < s.size(); i++)
        {
            if (use[i])
            {
                f = false;
                cout << s[i];
            }
        }
        if (f)
            cout << "";
        cout << endl;
    }

    return 0;
}