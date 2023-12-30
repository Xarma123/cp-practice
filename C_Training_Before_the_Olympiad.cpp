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
        lol n;
        cin >> n;
        lol a[n];
        lol od[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            od[i] = (a[i] % 2);
            if (i)
                a[i] += a[i - 1];
            if (i)
                od[i] += od[i - 1];
            if (i == 0)
                cout << a[i] << " ";
            else if (od[i] == i + 1)
            {
                if (i == 1)
                {
                    cout << a[i] << " ";
                }
                else
                {
                    lol c = od[i] - 3;
                    cout << a[i] - 1 - (c / 3) - (c % 3 == 1) << " ";
                }
            }
            else
            {
                cout << a[i] - (od[i] / 3) - (od[i] % 3 == 1) << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}
