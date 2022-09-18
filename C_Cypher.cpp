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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            lol c;
            cin >> c;
            string s;
            cin >> s;
            lol up = 0;
            for (lol j = 0; j < s.size(); j++)
            {
                if (s[j] == 'U')
                {
                    up--;
                }
                else
                    up++;
            }
            a[i] = (a[i] + up + 10) % 10;
        }
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}