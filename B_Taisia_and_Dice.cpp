#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, s, r;
        cin >> n >> s >> r;
        cout << s - r << " ";
        lol q = r % (n - 1);
        while (q--)
        {
            cout << (r / (n - 1)) + 1 << " ";
        }
        for (lol i = 0; i < n - 1 - (r % (n - 1)); i++)
        {
            cout << (r / (n - 1)) << " ";
        }
        cout << '\n';
    }

    return 0;
}