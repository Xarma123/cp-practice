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
        vector<lol> a;
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            a.push_back(t);
        }
        lol w[k];
        for (lol i = 0; i < k; i++)
        {
            cin >> w[i];
        }
        sort(a.begin(), a.end());
        sort(w, w + k);
        lol ans = 0;
        for (lol i = 0; i < k; i++)
        {
            ans += a[a.size() - 1];
            if (w[i] == 1)
            {
                ans += a[a.size() - 1];
            }
            a.pop_back();
        }
        lol index = a.size() - 1;
        for (lol i = 0; i < k; i++)
        {
            w[i] -= 1;
            if (w[i])
            {
                ans += a[index - w[i] + 1];
                index = index - w[i];
            }
        }

        cout << ans << endl;
    }

    return 0;
}