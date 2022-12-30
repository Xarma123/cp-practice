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
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol i = 0;
    while (i < n && a[i] == a[0])
        i++;
    if (i == n)
        cout << "NO";
    else
        cout << a[i];

    return 0;
}