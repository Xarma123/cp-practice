#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol l = 0;
        for (lol i = 0; i < n; i++)
        {
            l++;
            cin >> a[i];
            if (l == a[i])
                l++;
        }
        cout << l << '\n';
    }
}