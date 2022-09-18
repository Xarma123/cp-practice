#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool cmp(vector<lol> a, vector<lol> b)
{
    return a.size() > b.size();
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        map<lol, multiset<lol, greater<lol>>> mp;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol sum = 0;
        for (lol i = 0; i < n; i++)
        {
            lol s;
            cin >> s;
            sum += s;
            mp[a[i]].insert(s);
        }

        vector<vector<lol>> x;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {

            vector<lol> no;
            no.push_back(0);
            auto it = (*i).second.begin();
            while (it != (*i).second.end())
            {
                no.push_back(no[no.size() - 1] + (*it));

                it++;
            }
            x.push_back(no);
        }
        mp.clear();
        sort(x.begin(), x.end(), cmp);
        lol q = 1;
        while (q <= n)
        {

            lol ans = 0;
            for (auto i = 0; i < x.size(); i++)
            {

                lol nt = x[i].size() - 1 - ((x[i].size() - 1) % q);
                if (nt == 0)
                    break;
                ans += x[i][nt];
            }
            cout << ans << ' ';

            q++;
        }
        cout << endl;
    }

    return 0;
}