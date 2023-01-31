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
        lol mn = i;
        for (lol j = i + 1; j < n; j++)
        {
            if (a[j] < a[mn])
            {
                mn = j;
            }
        }
        for (lol j = mn; j > i; j--)
        {
            cout << j << " " << j + 1 << '\n';
            swap(a[j], a[j - 1]);
        }
    }

    return 0;
}