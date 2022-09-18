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
        char c;
        cin >> c;
        string a;
        cin >> a;
        vector<lol> x;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] != c)
            {
                x.push_back(i);
            }
        }
        if (x.empty())
            cout << 0 << endl;

        else
        {
            bool f2 = true;

            for (lol i = 2; i <= n; i++)
            {
                lol h = 1;
                bool flag = true;
                while (i * h - 1 < n)
                {
                    if (a[i * h - 1] != c)
                    {
                        flag = false;
                        break;
                    } 
                    h++;
                }
                if (flag)
                {
                    f2 = false;
                    cout << 1 << endl;
                    cout << i << endl;
                    break;
                }
            }
            if (f2)
            {
                cout << 2 << endl;
                cout << n << " " << n - 1 << endl;
            }
        }
    }

    return 0;
}