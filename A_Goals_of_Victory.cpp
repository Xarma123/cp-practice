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
        lol s = 0;
        for (lol i = 0; i < n - 1; i++)
        {
            lol v;
            cin >> v;
            s += v;
        }
        cout << -s << '\n';
    }
}