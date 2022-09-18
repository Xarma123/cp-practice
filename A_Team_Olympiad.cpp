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
    lol f[3];
    f[0] = f[1] = f[2] = 0;
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        f[t - 1]++;
        a[i] = {t, i + 1};
    }
    sort(a, a + n);
    lol v = min(f[0], min(f[1], f[2]));
    cout << v << endl;
    lol i = 0;
    lol j = 0;
    while (j != n && a[j].first != 2)
    {
        j++;
    }
    lol k = j;
    while (k != n && a[k].first != 3)
        k++;
    while (v--)
    {
        cout << a[i].second << " " << a[j].second << " " << a[k].second << endl;
        i++, j++, k++;
    }

    return 0;
}