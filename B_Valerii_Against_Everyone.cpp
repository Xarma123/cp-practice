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
        lol b[n];
        map<lol, lol> mp;
        bool e = true;
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            mp[b[i]]++;
            if (mp[b[i]] == 2)
                e = false;
        }
        if (e)
        { 
            cout<<"NO"<<endl;
        }
        else
            cout << "YES" << endl;
    }

    return 0;
}