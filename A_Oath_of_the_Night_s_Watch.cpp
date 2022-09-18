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
    lol j = n - 1;
    while (j >= 0 && a[j] == a[n - 1])
        j--;
    cout << max(j - i + 1, 0ll);

    return 0;
}