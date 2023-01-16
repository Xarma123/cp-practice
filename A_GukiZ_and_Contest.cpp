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
    for (lol i = 0; i < n; i++)
    {
        lol v = 1;
        for (lol j = 0; j < n; j++)
        {
            if (i != j && a[j] > a[i])
            {
                v++;
            }
        }
        cout << v << ' ';
    }

    return 0;
}