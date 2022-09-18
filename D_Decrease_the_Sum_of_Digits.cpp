#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string n;
        lol s;
        cin >> n >> s;
        string o = n;
        lol is = 0;
        for (lol i = 0; i < n.size(); i++)
        {
            is += n[i] - '0';
        }
        if (is <= s)
            cout << 0 << endl;
        else
        {
            lol ex = is - s;
            lol c = 0;
            lol i;
            for (i = n.size() - 1; i >= 0; i--)
            {
                c += n[i] - '0';
                n[i] = '0';
                if (c == ex)
                {
                    if (i - 1 >= 0)
                    {
                        if (n[i - 1] == '9')
                            break;
                    }
                }
                if (c > ex)
                    break;
            }
            lol add = 1;
            for (i = i - 1; i >= 0; i--)
            {
                if (n[i] == '9')
                {

                    n[i] = '0';
                }
                else
                {

                    n[i] = char(n[i] + 1);
                    add = 0;
                    break;
                }
            }
            if (add)
            {

                n = "1" + n;
            }

            cout << stoll(n) - stoll(o) << endl;
        }
    }

    return 0;
}