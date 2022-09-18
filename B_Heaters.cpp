#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, r;
    cin >> n >> r;
    char a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool ans = true;
    for (lol i = 0; i < n; i++)
    {
        lol z = 0, fi = -1;
        for (lol j = i - r + 1; j <= i + r - 1; j++)
        {
            if (j >= 0 && j < n)
            {
                if (a[j] == 'z')
                    z++;
                if (a[j] == '1')
                    fi = j;
            }
        }
        if (z == 0)
        {
            if (fi != -1)
                a[fi] = 'z';
            else
                ans = false;
        }
        if (ans == false)
            break;
    }
    if (!ans)
        cout << -1;
    else
    {
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == 'z')
                c++;
        }
        cout << c;
    }

    return 0;
}