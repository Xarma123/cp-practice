#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b;
        cin >> a >> b;
        lol n = a + b;
        set<lol> ans;
        if ((n) % 2 == 0)
        {
            if (a < b)
                swap(a, b);

            lol t = a - n / 2;
            ans.insert(t);
            lol t1 = n / 2 - t;
            while (t1--)
            {
                t += 2;
                ans.insert(t);
            }
        }
        else
        {
            if (a < b)
                swap(a, b);

            lol t = a - (n / 2 + 1);
            ans.insert(t);
            lol t1 = n / 2 - t;
            while (t1--)
            {
                t += 2;
                ans.insert(t);
            }

            t = a - n / 2;
            ans.insert(t);
            t1 = n / 2 + 1 - t;
            while (t1--)
            {
                t += 2;
                ans.insert(t);
            }
        }
        cout << ans.size() << endl;
        for (auto i = ans.begin(); i != ans.end(); i++)
        {
            cout << (*i) << " ";
        }
        cout << endl;
    }

    return 0;
}