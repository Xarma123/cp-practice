#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k, d;
    cin >> n >> k >> d;
    // k^d<=n
    lol p = 1;
    lol c = 0;
    while (c < d)
    {
        p = p * 1ll * k;
        if (p > n)
            break;
        c++;
    }
    if (p < n)
        cout << -1;
    else
    {
        vector<vector<lol>> all;
        vector<lol> no(d, 0);
        lol N = n;
        while (n--)
        {
            all.push_back(no);
            lol cary = 0;
            no[0]++;
            for (lol i = 0; i < d; i++)
            {
                no[i] += cary;
                cary = 0;
                if (no[i] == k)
                {
                    no[i] = 0;
                    cary = 1;
                }
            }
        }
        lol j = 0;
        n = N;
        while (j < d)
        {
            for (lol i = 0; i < n; i++)
            {
                cout << all[i][j] + 1 << " ";
            }
            j++;
            cout << '\n';
        }
    }

    return 0;
}