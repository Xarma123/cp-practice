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
        lol n, k, d, w;
        cin >> n >> k >> d >> w;
        lol x[n];
        for (lol i = 0; i < n; i++)
            cin >> x[i];
        lol mx = -1;
        lol dose = 0;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (x[i] > mx || dose == 0)
            {
                ans++;
                mx = x[i] + w + d;
                dose = k - 1;
            }
            else
            {
                dose--;
            }
        }
        cout << ans << endl;
    }

    return 0;
}