#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    lol m;
    cin >> m;
    while (m--)
    {
        lol k, p;
        cin >> k >> p;
        lol i = n - k;
        lol fi = i;
        while (1)
        {
            if (fi + 1 < n)
            {
                if (a[fi + 1].first == a[i].first)
                    fi++;
                else
                    break;
            }
            else
                break;
        }
        lol bi = i;
        while (1)
        {
            if (bi - 1 >= 0)
            {
                if (a[bi - 1].first == a[i].first)
                    bi--;
                else
                    break;
            }
            else
                break;
        }
        lol v = fi - i + 1;
        vector<pair<lol, lol>> f;
        while (v--)
        {
            f.push_back(make_pair(a[bi].second, a[bi].first));
            bi++;
        }
        bi = fi + 1;
        while (bi < n)
        {
            f.push_back(make_pair(a[bi].second, a[bi].first));
            bi++;
        }
        sort(f.begin(), f.end());
        cout << f[p - 1].second << endl;
    }

    return 0;
}