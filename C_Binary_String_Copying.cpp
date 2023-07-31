#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        lol c[n];

        string s;
        cin >> s;
        for (lol i = 0; i < n; i++)
        {
            c[i] = 0;
            if (s[i] == '1')
                c[i] = 1;
            if (i)
                c[i] += c[i - 1];
        }

        vector<lol> prvone(n), nxtzero(n);
        lol prv[n];
        lol l = -1;
        for (lol i = 0; i < n; i++)
        {
            prvone[i] = l;
            if (s[i] == '1')
                l = i;
        }
        l = -1;
        for (lol i = 0; i < n; i++)
        {
            prv[i] = l;
            if (s[i] == '0')
                l = i;
        }
        l = n;
        for (lol i = n - 1; i >= 0; i--)
        {
            nxtzero[i] = l;
            if (s[i] == '0')
                l = i;
        }
        vector<pair<lol, lol>> v;
        while (m--)
        {
            lol a, b;
            cin >> a >> b;
            a--;
            b--;
            v.push_back({b, a});
        }
        sort(v.begin(), v.end());
        lol ans = 0;
         bool f = false;
        for (lol i = 0; i < v.size(); i++)
        {
            lol r = v[i].first;

            vector<lol> lef;
            lol j = i + 1;
            lef.push_back(-v[i].second);

            while (j < v.size() && v[j].first < nxtzero[r])
            {
                lef.push_back(-v[j].second);
                j++;
            }

            sort(lef.begin(), lef.end());

            i = j - 1;
           
            for (lol k = 0; k < lef.size(); k++)
            {

                j = k + 1;
                lol l = -lef[k];
                lol sum = c[r];
                if (l - 1 >= 0)
                    sum -= c[l - 1];
                if (!((sum > 0 && s[r] == '1' && r - prv[r] >= sum) || (sum == 0)))
                {
                    ans++;
                }
                else if (!f)
                {
                    ans++;
                    f = true;
                }

                while (j < lef.size() && -lef[j] > prvone[-lef[k]])
                {
                    j++;
                }

                k = j - 1;
            }
        }
        cout << ans << '\n';
    }
}