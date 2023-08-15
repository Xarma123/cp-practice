#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol ox = 1, oy = 1;
    lol tx = 1, ty = 2;
    for (lol i = 0; i < n * 1ll * n; i++)
    {
        lol a;
        cin >> a;
        if (a == 3)
        {
            if (ox != n + 1)
            {
                cout << 1 << " " << ox << " " << oy << endl;
                oy += 2;
                if (oy > n)
                {
                    if (oy % 2 == 0)
                    {
                        ox++;
                        oy = 1;
                    }
                    else
                    {
                        ox++;
                        oy = 2;
                    }
                }
            }
            else if (tx != n + 1)
            {
                cout << 2 << " " << tx << " " << ty << endl;
                ty += 2;
                if (ty > n)
                {
                    if (ty % 2 == 0)
                    {
                        tx++;
                        ty = 1;
                    }
                    else
                    {
                        tx++;
                        ty = 2;
                    }
                }
            }
        }
        else if (a == 2)
        {
            if (ox != n + 1)
            {
                cout << 1 << " " << ox << " " << oy << endl;
                oy += 2;
                if (oy > n)
                {
                    if (oy % 2 == 0)
                    {
                        ox++;
                        oy = 1;
                    }
                    else
                    {
                        ox++;
                        oy = 2;
                    }
                }
            }
            else
            {
                cout << 3 << " " << tx << " " << ty << endl;
                ty += 2;
                if (ty > n)
                {
                    if (ty % 2 == 0)
                    {
                        tx++;
                        ty = 1;
                    }
                    else
                    {
                        tx++;
                        ty = 2;
                    }
                }
            }
        }
        else
        {
            if (tx != n + 1)
            {
                cout << 2 << " " << tx << " " << ty << endl;
                ty += 2;
                if (ty > n)
                {
                    if (ty % 2 == 0)
                    {
                        tx++;
                        ty = 1;
                    }
                    else
                    {
                        tx++;
                        ty = 2;
                    }
                }
            }
            else
            {
                cout << 3 << " " << ox << " " << oy << endl;
                oy += 2;
                if (oy > n)
                {
                    if (oy % 2 == 0)
                    {
                        ox++;
                        oy = 1;
                    }
                    else
                    {
                        ox++;
                        oy = 2;
                    }
                }
            }
        }
    }
}