#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        lol n;
        cin >> n;
        if (n == 0)
            break;
        vector<lol> x(n);
        for (lol i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        lol c = 0;
        for (lol i = 0; i < x.size(); i++)
        {
            for (lol j = i + 1; j < x.size(); j++)
            {
                if (__gcd(x[i], x[j]) == 1)
                {
                    c++;
                }
            }
        }
        if (c == 0)
            cout << "No estimate for this data set." << endl;
        else
        {
            n = n * (n - 1) / 2;
            long double val = (long double)6 * (long double)n;
            cout << setprecision(6) << sqrt(6.0 / c * n) << endl;
        }
    }

    return 0;
}