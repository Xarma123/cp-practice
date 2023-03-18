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

        lol n, m;
        cin >> n >> m;
        lol start = 1;
        cout << n * m << endl;
        lol i = n;
        for (lol i = 0; i < n; i++)
        {
            lol ex = start;
            for (lol k = 0; k < 10; k++)
                ex = ex * 2ll;
            for (lol j = 0; j < m; j++)
                cout << (j + 1 + ex) << " ";
            start++;
            cout << endl;
        }
    }

    return 0;
}