#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{

    lol x;
    cin >> x;
    if (((x + 1) & (x)) == 0)
        cout << 0;
    else
    {
        lol op = 0;
        vector<lol> ans;
        lol tggle = 1;
        while (((x + 1) & (x)) != 0)
        {
            if (tggle)
            {
                bool o = false;
                lol i;
                for (i = 31; i >= 0; i--)
                {
                    if (!o)
                    {
                        if ((x & (1 << i)))
                        {
                            o = true;
                        }
                    }
                    else
                    {
                        if (!(x & (1 << i)))
                        {
                            break;
                        }
                    }
                }
                x = (x ^ ((1 << (i + 1)) - 1));
                ans.push_back(i + 1);
                tggle = 1 - tggle;
                op++;
            }
            else
            {
                x++;
                op++;
                tggle = 1 - tggle;
            }
        }
        cout << op << endl;
        for (lol i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }

    return 0;
}