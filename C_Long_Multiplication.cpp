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
        string x, y;
        cin >> x >> y;
        lol n = x.size();
        lol q = -1;
        for (lol i = 0; i < n; i++)
        {
            if (q == -1)
            {
                if (x[i] != y[i])
                {
                    if (x[i] < y[i])
                        swap(x[i], y[i]);
                    q = 1;
                }
            }
            else
            {
                if (x[i] > y[i])
                    swap(x[i], y[i]);
            }
        }
        cout << x << '\n';
        cout << y << '\n';
    }

    return 0;
}
