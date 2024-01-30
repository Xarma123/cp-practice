#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol h, w, xa, ya, xb, yb;
        cin >> h >> w >> xa >> ya >> xb >> yb;
        if (xa >= xb)
        {
            cout << "Draw\n";
        }
        else
        {
            lol d = xb - xa;
            if (d % 2 == 0)
            {
                if (ya == yb)
                {
                    cout << "Bob\n";
                }
                else if (ya < yb)
                {
                    ya--;
                    yb--;
                    if (ya <= d / 2ll && yb <= d / 2ll)
                    {
                        cout << "Bob\n";
                    }
                    else
                        cout << "Draw\n";
                }
                else
                {
                    ya = w - ya;
                    yb = w - yb;
                    if (ya <= d / 2ll && yb <= d / 2ll)
                        cout << "Bob\n";
                    else
                        cout << "Draw\n";
                }
            }
            else
            {
                bool f = true;
                bool ans = false;
                while (1)
                {
                    if (f)
                    {
                        if (xa == h)
                            break;
                        xa++;
                        if (yb > ya)
                        {
                            ya++;
                            ya = min(ya, w);
                        }
                        else if (yb < ya)
                        {
                            ya--;
                            ya = max(ya, 1ll);
                        }
                        f = false;
                    }
                    else
                    {
                        if (xb == 1)
                            break;
                        xb--;
                        if (yb >= ya)
                        {
                            yb++;
                            yb = min(yb, w);
                        }
                        else
                        {
                            yb--;
                            yb = max(yb, 1ll);
                        }
                        f = true;
                    }

                    if (xa == xb && ya == yb)
                        ans = true;
                }
                if (ans)
                {
                    cout << "Alice\n";
                }
                else
                    cout << "Draw\n";
            }
        }
    }

    return 0;
}
