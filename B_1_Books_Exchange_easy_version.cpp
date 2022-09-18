#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol q;
    cin >> q;
    while (q--)
    {
        lol n;
        cin >> n;
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for (lol i = 0; i < n; i++)
        {
            lol j = i;
            lol c = 1;
            while (p[j] != i + 1)
            {
                c++;
                j = p[j] - 1;
            }
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}