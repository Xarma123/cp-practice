#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;

    vector<pair<lol, lol>> v;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        v.push_back({t, i});
    }
    sort(v.begin(), v.end());
    lol q = 1;
    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        while (j < n && v[j].first == v[i].first)
            j++;
        q = q * 1ll * (j - i);
        if (q >= 3)
            break;
        i = j - 1;
    }
    if (q < 3)
        cout << "NO";
    else
    {
        cout << "YES" << endl;
        for (lol i = 0; i < n; i++)
        {
            cout << v[i].second + 1 << " ";
        }
        cout << endl;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && v[j].first == v[i].first)
                j++;
            if (j - i >= 2)
            {
                swap(v[i], v[i + 1]);
                break;
            }

            i = j - 1;
        }
        for (lol i = 0; i < n; i++)
        {
            cout << v[i].second + 1 << " ";
        }
        cout << endl;
        for (lol i = n - 1; i >= 0; i--)
        {
            lol j = i - 1;
            while (j >= 0 && v[j].first == v[i].first)
            {
                j--;
            }
            if (i - j >= 2)
            {
                swap(v[i], v[i - 1]);
                break;
            }
        }

        for (lol i = 0; i < n; i++)
        {
            cout << v[i].second + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}