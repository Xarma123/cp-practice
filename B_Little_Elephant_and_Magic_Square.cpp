#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a[3][3];
    for (lol i = 0; i < 3; i++)
    {
        for (lol j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    for (lol c = 1; c <= 1e5; c++)
    {
        lol k = c + a[2][0] + a[0][2];
        lol v = k - a[0][1] - a[0][2];
        if (v > 0)
        {
            lol q = k - a[2][0] - a[2][1];
            if (q == k - c - v && q > 0)
            {
                a[0][0] = v;
                a[1][1] = c;
                a[2][2] = q;
                break;
            }
        }
    }
    for (lol i = 0; i < 3; i++)
    {
        for (lol j = 0; j < 3; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}