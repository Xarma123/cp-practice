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
        lol a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << '\n';
        }
        else if (b > a)
        {
            lol k = (b - a) / 5;
            lol ans = k + (b - (a + 5ll * k)) / 2 + ((b - (a + 5ll * k)) % 2);
            k++;
            ans = min(ans, ((a + 5ll * k - b) / 2 + ((a + 5ll * k - b) % 2) + k));
            cout << ans << '\n';
        }
        else
        {
            swap(a, b);
            lol k = (b - a) / 5;
            lol ans = k + (b - (a + 5ll * k)) / 2 + ((b - (a + 5ll * k)) % 2);
            k++;
            if (b - 5ll * k >= 0)
            {
                ans = min(ans, ((a + 5ll * k - b) / 2 + ((a + 5ll * k - b) % 2) + k));
            }
            cout << ans << '\n';
        }
    }
}