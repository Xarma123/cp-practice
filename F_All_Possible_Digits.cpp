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
        lol n, p;
        cin >> n >> p;
        lol a[n];
        vector<lol> b(n);
        for (lol i = 0; i < n; i++)
            cin >> a[i], b[i] = a[i];
        // 0 - p-
        sort(b.begin(), b.end());
        lol mn = 0;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && b[j] == b[i])
                j++;
            if (b[i] == mn)
                mn++;
            else
            {
                break;
            }
            i = j - 1;
        }
        if (mn == p)
        {
            cout << 0 << '\n';
            continue;
        }
        lol mx = p - 1;
        for (lol i = n - 1; i >= 0; i--)
        {
            lol j = i - 1;
            while (j >= 0 && b[j] == b[i])
                j--;
            if (b[i] == mx)
                mx--;
            else
            {
                break;
            }
            i = j + 1;
        }
        if (a[n - 1] < mn)
        {
            cout << mx - a[n - 1] << endl;
        }
        else
        {
            lol ans = p - a[n - 1];
            b.clear();
            for (lol i = 0; i < n; i++)
            {
                if (a[i] > 0 && a[i] < a[n - 1])
                {
                    b.push_back(a[i]);
                }
            }
            lol i;
            for (i = n - 2; i >= 0; i--)
            {
                a[i]++;
                if (a[i] != p)
                {
                    if (a[i] > 0 && a[i] < a[n - 1])
                    {
                        b.push_back(a[i]);
                    }
                    break;
                }
                else
                {
                    a[i] = 0;
                }
            }
            if (i < 0ll)
            {
                if (1 < a[n - 1] )
                {
                    b.push_back(1);
                }
            }
            sort(b.begin(), b.end());
           
            mn = 1;
            for (i = 0; i < b.size(); i++)
            {
                lol j = i + 1;
                while (j < b.size() && b[j] == b[i])
                    j++;
                if (b[i] == mn)
                    mn++;
                else
                {
                    break;
                }
                i = j - 1;
            }
            if (mn == a[n - 1])
            {
                cout << ans << '\n';
                continue;
            }

            mx = a[n - 1] - 1;
            for (i = b.size() - 1; i >= 0; i--)
            {
                lol j = i - 1;
                while (j >= 0 && b[j] == b[i])
                    j--;
                if (b[i] == mx)
                    mx--;
                else
                {
                    break;
                }
                i = j + 1;
            }
            ans += mx;
            cout << ans << endl;
        }
    }
    return 0;
}