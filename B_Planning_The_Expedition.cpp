#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol a[m];
    lol s = 0;
    for (lol i = 0; i < m; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    sort(a, a + m);
    lol d;
    for (d = 1; d <= s + 1; d++)
    {
        lol co = 0;
        for (lol i = 0; i < m; i++)
        {
            lol j = i + 1;
            while (j < m && a[i] == a[j])
                j++;
            lol c = j - i;
            co += c / d;
            i = j - 1;
        }
        if (co < n)
            break;
    }
    cout << d - 1;
}