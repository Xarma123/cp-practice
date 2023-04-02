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
    for (lol op = 0; op < t; op++)
    {

        lol n, d12, d23, d31;
        cin >> n >> d12 >> d23 >> d31;
       
        // 1 mid
        if (d12 + d31 == d23)
        {
            cout << "YES\n";
            lol l = 2;
            lol c = 4;
            while (d12 > 1)
            {
                cout << l << " " << (c++) << '\n';
                d12--;
                l = c - 1;
            }
            cout << l << " " << 1 << '\n';
            l = 1;
            while (d31 > 1)
            {
                cout << l << " " << (c++) << '\n';
                d31--;
                l = c - 1;
            }
            cout << l << " " << 3 << '\n';
            while (c <= n)
            {
                cout << 1 << " " << c << '\n';
                c++;
            }

        } // 2 mid
        else if (d12 + d23 == d31)
        {
            cout << "YES\n";
            lol l = 1;
            lol c = 4;
            while (d12 > 1)
            {
                cout << l << " " << (c++) << '\n';
                d12--;
                l = c - 1;
            }
            cout << l << " " << 2 << '\n';
            l = 2;
            while (d23 > 1)
            {
                cout << l << " " << (c++) << '\n';
                d23--;
                l = c - 1;
            }
            cout << l << " " << 3 << '\n';
            while (c <= n)
            {
                cout << 1 << " " << c << '\n';
                c++;
            }

        } // 3 mid
        else if (d31 + d23 == d12)
        {
            cout << "YES\n";
            lol l = 1;
            lol c = 4;
            while (d31 > 1)
            {
                cout << l << " " << (c++) << '\n';
                d31--;
                l = c - 1;
            }
            cout << l << " " << 3 << '\n';
            l = 3;
            while (d23 > 1)
            {
                cout << l << " " << (c++) << '\n';
                d23--;
                l = c - 1;
            }
            cout << l << " " << 2 << '\n';
            while (c <= n)
            {
                cout << 1 << " " << c << '\n';
                c++;
            }
        }
        else if (d31 + d12 > d23)
        {
            lol ex = d31 + d12 - d23;

            if (((ex / 2) + d23 <= n - 1) && (ex % 2 == 0)&&d31>=ex/2&&d12>=ex/2)
            {
                cout << "YES\n";
                lol l = 2;
                lol c = 4;
                d12 -= ex / 2;
                lol e;
                for (lol i = 0; i < d23 - 1; i++)
                {
                    cout << l << " " << (c++) << '\n';

                    l = c - 1;
                    if (--d12 == 0)
                        e = l;
                }
                cout << l << " " << 3 << '\n';

                d12 = ex / 2;
                l = 1;
                for (lol i = 0; i < d12 - 1; i++)
                {
                    cout << l << " " << (c++) << '\n';
                    l = c - 1;
                }
                cout << e << " " << l << '\n';
                while (c <= n)
                {
                    cout << 1 << " " << (c++) << '\n';
                }
            }
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}