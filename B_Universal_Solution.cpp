#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        map<char, lol> x;
        for (lol i = 0; i < a.size(); i++)
        {
            x[a[i]]++;
        }
        lol mx = -1;
        char q;
        for (auto i = x.begin(); i != x.end(); i++)
        {
            if (mx <= (*i).second)
            {
                mx = (*i).second;
                q = (*i).first;
            }
        }
        if (q == 'R')
            q = 'P';
        else if (q == 'P')
            q = 'S';
        else
            q = 'R';

        for (lol i = 0; i < a.size(); i++)
        {
            cout << q;
        } 
        cout<<endl;
    }

    return 0;
}