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
        lol n, k;
        cin >> n >> k;
        lol s[k];
        for (lol i = 0; i < k; i++)
        {
            cin >> s[i];
        }

        lol v = LONG_LONG_MAX;
        lol i;
        for (i = k - 1; i > 0; i--)
        {
            if (s[i] - s[i - 1] > v)
            {
                break;
            }
            v = s[i] - s[i - 1];
        }
        if ((s[0] / (n - k + 1)) + ((s[0] % (n - k + 1))>0) > v)
            i = -1;

        if (i == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}