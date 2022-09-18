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
        lol w[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> w[i];
        }
        lol ans = 0;
        for (lol s = 2; s <= 2 * n; s++)
        {

            lol count = 0;
            set<lol> in;
            for (lol i = 0; i < n; i++)
            {
                if (in.find(i) != in.end())
                    continue;
                for (lol j = i + 1; j < n; j++)
                {
                    if (in.find(j) != in.end())
                        continue;
                    if (w[i] + w[j] == s)
                    {
                        in.insert(j);
                        count++;
                        break;
                    }
                }
            }
          
            ans = max(ans, count);
        }
        cout << ans << endl;
    }

    return 0;
}