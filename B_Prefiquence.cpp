#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        lol j = 0;
        for (lol i = 0; i < m && j < n; i++)
        {
            if (b[i] == a[j])
            {
                j++;
            }
        }
        cout << j << '\n';
    }

    return 0;
}
