#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, s, t;
    cin >> n >> s >> t;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    s--;
    t--;
    lol q = s;
    lol c = 0;
    while (s != t)
    {
        s = a[s];
        c++;
        if (s == q)
            break;
    }
    if (s == t)
        cout << c;
    else
        cout << -1;

    return 0;
}