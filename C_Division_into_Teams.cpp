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
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n);
    cout << n / 2 << endl;
    for (lol i = 1; i < n; i += 2)
    {
        cout << a[i].second << " ";
    }
    cout << endl;
    cout << n - n / 2 << endl;
    for (lol i = 0; i < n; i += 2)
    {
        cout << a[i].second << " ";
    }
    cout << endl;

    return 0;
}