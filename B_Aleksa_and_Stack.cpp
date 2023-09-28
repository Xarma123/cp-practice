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
        lol ans[n];
        ans[0] = 2;
        ans[1] = 3;
        for (lol i = 0; i < n; i++)
        {
            cout << 2ll * i + 1 << " ";
        }
        cout << '\n';
    }
}