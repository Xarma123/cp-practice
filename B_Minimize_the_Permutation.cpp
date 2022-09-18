#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol q;
    cin >> q;
    while (q--)
    {
        lol n;
        cin >> n;
        lol a[n];
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]] = i;
        }
        lol last = 0;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {

            if ((*i).second == last)
                last++;
            else if ((*i).second > last)
            {
                mp[a[(*i).second - 1]]++;
                for (lol j = (*i).second - 1; j >= last; j--)
                {
                    swap(a[j], a[j + 1]);
                }
                last = (*i).second;
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] <<" ";
        }
        cout << endl;
    }

    return 0;
}