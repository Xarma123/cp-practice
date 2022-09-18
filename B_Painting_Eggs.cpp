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
    string s = "";
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        lol q = 0;
        cin >> a[i].first >> q;
        a[i].second = i;
        s.push_back('q');
    }
    sort(a, a + n);
    lol i = 0, j = n - 1;
    lol d = 0;
    while (i <= j)
    {
        if (abs(d + a[i].first) <= abs(d - 1000 + a[j].first))
        {
            d = d + a[i].first;
            s[a[i].second] = 'A';
            i++;
        }
        else
        {
            d = d - 1000 + a[j].first;
            s[a[j].second] = 'G';
            j--;
        }
    }
    if (abs(d) > 500)
        cout << -1;
    else
        cout << s;

    return 0;
}