#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol x[s.size()];
    lol y[s.size()];
    lol z[s.size()];
    for (lol i = 0; i < s.size(); i++)
    {
        x[i] = 0;
        y[i] = 0;
        z[i] = 0;
        if (s[i] == 'x')
            x[i]++;
        else if (s[i] == 'y')
            y[i]++;
        else if (s[i] == 'z')
            z[i]++;
        if (i)
        {
            x[i] += x[i - 1];
            y[i] += y[i - 1];
            z[i] += z[i - 1];
        }
    }
    lol m;
    cin >> m;
    while (m--)
    {
        lol l, r;
        cin >> l >> r;
        if ((r - l + 1) < 3)
        {
            cout << "YES" << '\n';
            continue;
        }

        vector<lol> v;
        if (l - 2 >= 0)
        {
            v.push_back(x[r - 1] - x[l - 2]);
            v.push_back(y[r - 1] - y[l - 2]);
            v.push_back(z[r - 1] - z[l - 2]);
        }
        else
        {
            v.push_back(x[r - 1]);
            v.push_back(y[r - 1]);
            v.push_back(z[r - 1]);
        }
        sort(v.begin(), v.end());
        if ((r - l + 1) % 3 == 0)
        {
            if (v[0] == ((r - l + 1) / 3) && v[1] == v[0] && v[1] == v[2])
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        else if ((r - l + 1) % 3 == 1)
        {
            if (v[0] == ((r - l + 1) / 3) && v[1] == v[0] && v[0] + 1 == v[2])
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        else
        {
            if (v[0] == ((r - l + 1) / 3) && v[1] == v[0] + 1 && v[0] + 1 == v[2])
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }

    return 0;
}