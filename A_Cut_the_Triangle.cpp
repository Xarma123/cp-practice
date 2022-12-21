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
        pair<lol, lol> a[3];
        for (lol i = 0; i < 3; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        sort(a, a + 3);
        if (a[1].first > a[0].first && a[1].first < a[2].first)
        {
            cout << "YES" << endl;
        }
        else
        {
            for (lol i = 0; i < 3; i++)
            {
                swap(a[i].first, a[i].second);
            }
            sort(a, a + 3);
            if (a[1].first > a[0].first && a[1].first < a[2].first)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}