#include <bits/stdc++.h>
#define lol int
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
        lol n, c, q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        vector<pair<lol, lol>> ra;
        vector<long long> count;
        ra.push_back({0, n - 1});
        while (c--)
        {
            lol l, r;
            cin >> l >> r;
            lol c = 0;
            bool lt = false;
            for (lol i = 0; i < ra.size(); i++)
            {
                lol lf = ra[i].first;
                lol rf = ra[i].second;
                c += rf - lf + 1;
                if (c >= l && !lt && c >= r)
                {
                    ra.push_back({rf - (c - l), rf - (c - r)});
                    break;
                }
                else if (c >= l && !lt)
                {
                    ra.push_back({rf - (c - l), rf});
                    lt = true;
                }
                else if (c >= r)
                {
                    ra.push_back({lf, rf - (c - r)});
                    break;
                }
                else if(lt)
                    ra.push_back({lf, rf});
            }
        }
        for (lol i = 0; i < ra.size(); i++)
        {
            long long v = ra[i].second - ra[i].first + 1;
            if (count.size())
                v += count.back();
            count.push_back(v);
        }
        while (q--)
        {
            lol k;
            cin >> k;
            lol j = lower_bound(count.begin(), count.end(), k) - count.begin();

            cout << s[ra[j].second - (count[j] - k)] << '\n';
        }
    }

    return 0;
}