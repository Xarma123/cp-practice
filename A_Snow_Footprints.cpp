#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string a;
    cin >> a;
    bool r = false, l = false;
    lol s = -1, e = -1;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] == 'R')
            r = true;
        if (a[i] == 'L')
            l = true;
        if (a[i] == 'R' || a[i] == 'L')
        {
            if (s == -1)
                s = i;
            e = i;
        }
    }
    if (!r)
    {
        if (!l)
            cout << 1 << " " << 1;
        else
        {
            cout << e + 1 << " ";
            cout << s;
        }
    }
    else
    {
        if (!l)
        {
            cout << s + 1 << " " << e + 2;
        }
        else
        {
            cout << s + 1 << " ";
            while (a[s] != 'L')
            {
                s++;
            }
            cout << s;
        }
    }

    return 0;
}