#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol b[3][3];
    for (lol i = 0; i < 3; i++)
        for (lol j = 0; j < 3; j++)
            b[i][j] = 1;

    for (lol i = 0; i < 3; i++)
    {
        for (lol j = 0; j < 3; j++)
        {
            lol q;
            cin >> q;
            if (q % 2 == 1)
            {
                b[i][j] = 1 - b[i][j];
                if (i - 1 >= 0)
                    b[i - 1][j] = 1 - b[i - 1][j];
                if (i + 1 < 3)
                    b[i + 1][j] = 1 - b[i + 1][j];
                if (j - 1 >= 0)
                    b[i][j - 1] = 1 - b[i][j - 1];
                if (j + 1 < 3)
                    b[i][j + 1] = 1 - b[i][j + 1];
            }
        }
    }
    for (lol i = 0; i < 3; i++)
    {
        for (lol j = 0; j < 3; j++)
        {
            cout << b[i][j];
        }
        cout << '\n';
    }

    return 0;
}