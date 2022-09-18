#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {

        lol x, n;
        cin >> n >> x;
        lol e = 0, o = 0;
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            if (t % 2 == 0)
                e++;
            else
                o++;
        }
        if (o == 0)
            cout << "NO" << endl;
        else
        {
            if (x == n)
            {

                if (o % 2 != 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else
            {
                if (x % 2 == 0)
                {
                    if (e == 0)
                    {
                        cout << "NO" << endl;
                    }
                    else
                    {
                        cout << "YES" << endl;
                    }
                }
                else
                {
                    cout << "YES" << endl;
                }
            }
        }
    }

    return 0;
}