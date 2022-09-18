#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x, y;
        cin >> n >> x >> y;
        if (n == y - x + 1)
        {
            while (n--)
            {
                cout << x << " ";
                x++;
            }
        }
        else
        {
            set<lol> ans;
            lol c = n - 2;
            while (1)
            {
                if ((y - x) % (c + 1) == 0)
                {
                    break;
                }
                else
                    c--;
            }
            lol d = (y - x) / (c + 1);
            lol k = 0;
            for (lol i = x; i <= y; i = i + d)
            {
                ans.insert(i);
                k++;
                if (k == n)
                    break;
            }
            if (k < n)
            {
                for (lol i = x - d; i > 0; i = i - d)
                {
                    ans.insert(i);
                    k++;
                    if (k == n)
                        break;
                }
            }
            if (k < n)
            {
                for (lol i = y + d; k < n; i = i + d)
                {
                    ans.insert(i);
                    k++;
                }
            }
            for (auto i = ans.begin(); i != ans.end(); i++)
            {
                cout << (*i) << " ";
            }
        }

        cout << endl;
    }

    return 0;
}