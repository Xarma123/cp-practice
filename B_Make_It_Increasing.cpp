#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol deal(lol a[], lol i)
{
    if (a[i + 1] == 0)
        return -1;
    lol c = 0;
    while (a[i] >= a[i + 1])
    {
        c++;
        a[i] /= 2;
    }
    return c;
}
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
        int ans = 0;

        for (lol i = 0; i < n - 1; i++)
        {
            if (a[i] >= a[i + 1])
            {
                lol q = deal(a, i);
                if (q == -1)
                {
                    ans = -1;
                    break;
                }
                ans += q;
                for (lol j = i - 1; j >= 0; j--)
                {
                    if (a[j] >= a[j + 1])
                    {
                        q = deal(a, j);
                        if (q == -1)
                        {
                            ans = -1;
                            break;
                        }
                        ans += q;
                    }
                    else
                        break;
                }
                if (ans == -1)
                    break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}