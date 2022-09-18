#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n], b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        vector<pair<lol, lol>> x;
        for (lol i = n - 1; i >= 0; i--)
        {
            if (a[i] == b[i])
                continue;
            else
            {
                lol j;
                for (j = i - 1; j >= 0; j--)
                {
                    if (a[j] == b[i])
                    {
                        break;
                    }
                }
                x.push_back(make_pair(j, i));
                for (lol k = j; k < i; k++)
                {
                    a[k] = a[k + 1];
                }
                a[i] = b[i];
            }
        }
        cout << x.size() << endl;
        for (auto i = x.begin(); i != x.end(); i++)
        {
            cout << (*i).first + 1 << " " << (*i).second + 1 << " " << 1 << endl;
        }
    }

    return 0;
}