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
        lol x, n, m;
        cin >> x >> n >> m;
        while (x > 20ll && n > 0)
        {
            x = (x / 2) + 10;
            n--;
        }
        while (x > 0 && m > 0)
        {

            x -= 10;
            m--;
        }
        if (x > 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}