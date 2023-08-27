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
        lol n;
        cin >> n;
        lol a[n];
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        bool use[n];
        memset(use, true, sizeof(use));
        lol v = n;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                if (s % 2 != 0)
                {
                    use[i] = false;
                    v--;
                    s--;
                }
                lol j = i + 1;
                while (j < n && a[j] == 0)
                    j++;
                if (j < n && (j - i) % 2 == 0)
                {
                    use[j - 1] = false;
                    v--;
                }
                i = j - 1;
            }
        }

        cout << v << '\n';
        for (lol i = 0; i < n; i++)
        {
            if (use[i])
            {
                cout << a[i] << " ";
            }
        }
        cout << '\n';
    }
}