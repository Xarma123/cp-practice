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
        string a;
        cin >> a;
        bool f = true;
        map<char, lol> x;
        for (lol i = 0; i < n; i++)
        {
            x[a[i]]++;
            if (a[i] == 'M')
            {
                if (x['T'] == 0)
                {
                    f = false;
                    break;
                }
                x['T']--;
            }
        }
        if (x['M'] != x['T'])
        {
            f = false;
        }
        x['T'] = 0;
        x['M'] = 0;
        for (lol i = a.size() - 1; i >= 0; i--)
        {
            x[a[i]]++;
            if (a[i] == 'M')
            {
                if (x['T'] == 0)
                {
                    f = false;
                    break;
                }
                x['T']--;
            }
        }
        if (x['M'] != x['T'])
        {
            f = false;
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}