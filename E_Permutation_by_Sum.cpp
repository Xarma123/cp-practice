#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, l, r, s;
        cin >> n >> l >> r >> s;
        bool a[n];
        memset(a, false, sizeof(a));
        lol x = 0;
        for (lol i = 0; i < r - l + 1; i++)
        {
            a[i] = true;
            x += i + 1;
        }
        bool ans = true;
        for (lol i = r - l; i >= 0; i--)
        {
            if (x < s)
            {
                a[i] = false;

                for (lol j = min(i + s - x , n - 1); j >= 0; j--)
                {
                    if (!a[j])
                    {
                        x -= i + 1;
                        x += j + 1;
                        a[j] = true;
                        break;
                    }
                }
            }
            else if (x == s)
                break;
            else
            {
                ans = false;
                break;
            }
        }
        if (x == s)
        {
            vector<lol> v;
            for (lol i = 0; i < n; i++)
            {
                if (a[i])
                {
                    v.push_back(i + 1);
                }
            }

            lol b[n];
            memset(b, -1, sizeof(b));
            for (lol i = l - 1; i < r; i++)
            {
                b[i] = v.back();
                v.pop_back();
            }

            for (lol i = 0; i < n; i++)
            {
                if (b[i] == -1)
                {
                    for (lol j = 0; j < n; j++)
                    {
                        if (!a[j])
                        {
                            b[i] = j + 1;
                            a[j] = true;
                            break;
                        }
                    }
                }
                cout << b[i] << " ";
            }
            cout << '\n';
        }
        else
            cout << -1 << '\n';
    }
}