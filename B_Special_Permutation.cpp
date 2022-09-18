#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, a, b;
        cin >> n >> a >> b;
        if (n - a + 1 >= n / 2 && b >= n / 2)
        {

            vector<lol> x;
            x.push_back(a);
            lol s = n;
            lol c = (n / 2) - 1;
            bool flag = true;
            while (c--)
            {
                if (s != b)
                {
                    if (s > a)
                    {
                        x.push_back(s);
                        s--;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    c++;
                    s--;
                }
            }
            if (flag)
            {
                x.push_back(b);
                s = 1;
                c = (n / 2) - 1;
                while (c--)
                {
                    if (s != a)
                    {
                        if (s < b)
                        {
                            x.push_back(s);
                            s++;
                        }
                        else
                        {
                            flag = false;
                            break;
                        }
                    }
                    else
                    {
                        c++;
                        s++;
                    }
                }
                if (flag)
                {
                    for (lol i = 0; i < n; i++)
                    {
                        cout << x[i] << " ";
                    }
                }
                else
                    cout << -1;
            }
            else
                cout << -1;

            cout << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}