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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol mx = n;
        for (lol i = n - 1; i >= 0; i--)
        {
            if (a[i] > mx)
            {
                mx--;
            }
            else
                break;
        }
        cout << mx + 1 << '\n';
    }
}