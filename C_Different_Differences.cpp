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
        lol k, n;
        cin >> k >> n;

        lol l = 1;
        lol d = 1;
        bool f = true;
        lol lp;
        for (lol i = 0; i < k; i++)
        {
            if (f)
            {
                if (n - l >= k - (i + 1))
                {
                    cout << l << " ";
                    lp = l;
                    l += d;
                    d++;
                }
                else
                {
                    f = false;
                    i--;
                }
            }
            else
            {
                cout << (++lp) << " ";
            }
        }
        cout << endl;
    }

    return 0;
}