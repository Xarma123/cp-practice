#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol q;
    cin >> q;
    while (q--)
    {
        lol k, n, a, b;
        cin >> k >> n >> a >> b;
        if (((k / b) * (b) == k ? k / b - 1 : k / b) >= n)
        {
            lol s = 0;
            lol e = k /(long long)a + 12;
         
            while (s != e - 1)
            {   
                lol m = (s + e) / 2;
               
                bool f;
                if (k - m * a <= 0)
                    f = false;
                else
                {
                    if (m >= n)
                        f = true;
                    else
                    {
                        lol K = k - m * a;
                        if (K <= b)
                            f = false;
                        else
                        {
                            if (((K / b) * (b) == K ? K / b - 1 : K / b) + m >= n)
                                f = true;
                            else
                                f = false;
                        }
                    }
                }
                if (f)
                    s = m;
                else
                    e = m;
            }
            if (s >= n)
                cout << n << endl;
            else
                cout << s << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}