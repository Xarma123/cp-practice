#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol target = n - 1;
        lol killed = 0;
        lol score = 0;
        for (lol i = n - 1 - k; i >= 0; i--)
        {
            if (killed == k)
                break;
            score += a[i] / a[target];
            a[i] = -1;
            a[target] = -1;
            target--;
            killed++;
        }

        for (lol i = 0; i < n; i++)
        {
            if (a[i] != -1)
                score += a[i];
        }

        cout << score << endl;
    }

    return 0;
}