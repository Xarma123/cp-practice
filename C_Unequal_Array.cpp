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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol c = 0;
        lol l = -1;
        for (lol i = 0; i < n - 1; i++)
        {
            if (a[i] == a[i + 1])
            {
                c++;
                l = i;
            }
        }
        if (c <= 1)
            cout << 0 << endl;
        else
        {
            for (lol i = 0; i < n - 1; i++)
            {
                if (a[i] == a[i + 1])
                {
                    if (l == i + 1)
                        cout << 1 << endl;
                    else
                        cout << l - i - 1 << endl;
                    break;
                }
            }
        }
    }

    return 0;
}