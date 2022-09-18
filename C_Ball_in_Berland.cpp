#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, k;
        cin >> a >> b >> k;
        lol ar[k];
        for (lol i = 0; i < k; i++)
        {
            cin >> ar[i];
        }
        lol br[k];
        for (lol i = 0; i < k; i++)
        {
            cin >> br[i];
        }
        sort(ar, ar + k);
        sort(br, br + k);
        lol ways = 0;
        lol c = 1;
        for (lol i = 1; i < k; i++)
        {
            if (ar[i] != ar[i - 1])
            {
                ways += c * (c - 1) / 2;
                c = 1;
            }
            else
            {
                c++;
            }
        }
        ways += c * (c - 1) / 2;
        c = 1;
        for (lol i = 1; i < k; i++)
        {
            if (br[i] != br[i - 1])
            {
                ways += c * (c - 1) / 2;
                c = 1;
            }
            else
            {
                c++;
            }
        }
        ways += c * (c - 1) / 2;
        cout << k * (k - 1) / 2 - ways << endl;
    }

    return 0;
}