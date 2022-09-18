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
    vector<pair<lol, lol>> x;
    for (lol i = 0; i < n; i++)
    {
        lol a;
        cin >> a;
        x.push_back({a, i});
    }
    sort(x.begin(), x.end());
    bool ne = true, p = true;
    for (lol i = 0; i < n; i++)
    {

        if (x[i].first % 2 != 0)
        {
            if (x[i].first < 0)
            {
                x[i].first /= 2;
                if (ne)
                {

                    x[i].first--;
                }
                ne = !ne;
            }
            else
            {
                x[i].first /= 2;
                if (p)
                {
                    x[i].first++;
                }
                p = !p;
            }
        }
        else
            x[i].first /= 2;

        swap(x[i].first, x[i].second);
    }
    sort(x.begin(), x.end());
    for (lol i = 0; i < n; i++)
    {
        cout << x[i].second << endl;
    }

    return 0;
}