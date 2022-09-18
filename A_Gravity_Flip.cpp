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
    for (lol i = 1; i < n; i++)
    {
        for (lol j = i - 1; j >= 0 && a[j + 1] < a[j]; j--)
        {
            lol v = a[j] - a[j + 1];
            a[j + 1] += v;
            a[j] -= v;
        }
    }
    for (lol i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}