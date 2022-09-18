#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        lol n = s.size();
        lol ones[n];
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (s[0] == '0')
                    ones[0] = 0;
                else
                    ones[0] = 1;
            }
            else
            {
                ones[i] = ones[i - 1];
                if (s[i] == '1')
                    ones[i]++;
            }
        }

        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            lol cost = ones[i];
            cost += (n - i - 1) - (ones[n - 1] - ones[i]);
            ans = min(ans, cost);
            cost = (ones[n - 1] - ones[i]);
            cost += (i + 1) - ones[i];
            ans = min(ans, cost);
        }
        cout << ans << endl;
    }

    return 0;
}