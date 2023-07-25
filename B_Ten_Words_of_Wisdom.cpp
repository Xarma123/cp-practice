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
        lol ans = LONG_LONG_MIN;
        lol c = 1;
        lol ansc = 0;
        while (n--)
        {
            lol a, b;
            cin >> a >> b;
            if (a <= 10 && ans < b)
            {
                ans = b;
                ansc = c;
            }
            c++;
        }
        cout << ansc << '\n';
    }
}