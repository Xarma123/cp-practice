#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol r, b;
        cin >> r >> b;
        lol d = r / (b + 1);
        lol q = r % (b + 1);
        for (lol i = 0; i < b; i++)
        {
            for (lol j = 0; j < d; j++)
            {
                cout << "R";
            }
            if (q > 0)
            {
                q--;
                cout << "R";
            }
            cout << "B";
        }
        for (lol j = 0; j < d; j++)
        {
            cout << "R";
        }
        if (q > 0)
        {
            q--;
            cout << "R";
        }

        cout << '\n';
    }
}