#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool check(lol x, lol m)
{
    while (x && x % m == 0)
        x /= m;
    return (x == 1);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {

        lol n, m;
        cin >> n >> m;
        vector<lol> v(n);
        for (lol i = 0; i < n; i++)
            cin >> v[i];
        lol k;
        cin >> k;
        vector<lol> b(k);
        for (lol i = 0; i < k; i++)
            cin >> b[i];
        vector<pair<lol, lol>> vals(n);
        for (int i = 0; i < n; i++)
        {
            lol num = 1;
            while (v[i] > 1 && v[i] % m == 0)
                num *= m, v[i] /= m;
            vals[i].first = num, vals[i].second = v[i];
        }
        int ind = 0;
        bool pos = true;
        for (int i = 0; i < k; i++)
        {
            if (b[i] % vals[ind].second || !check(b[i] / vals[ind].second, m))
            {
                pos = false;
                break;
            }
            lol req = b[i] / vals[ind].second;
            while (ind < n && req)
            {
                if (b[i] % vals[ind].second)
                    break;
                lol minus = min(req, vals[ind].first);
                req -= minus, vals[ind].first -= minus;
                if (vals[ind].first == 0)
                    ind++;
            }
            if (req)
            {
                pos = false;
                break;
            }
        }
        if (!pos || ind != n)
            cout << "No";
        else
            cout << "Yes";
        cout << endl;
    }

    return 0;
}