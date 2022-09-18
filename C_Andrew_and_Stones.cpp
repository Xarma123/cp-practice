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
        lol a[n];
        vector<lol> od;
        vector<lol> ev;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i != 0 || i != n - 1)
            {
                if (a[i] % 2 == 0)
                    ev.push_back(a[i]);
                else
                    od.push_back(a[i]);
            }
        }
        lol ans = 0;
        sort(ev.begin(), ev.end());
        sort(od.begin(), od.end());
        if (ev.size() == 0 && od.size() == 1)
            cout << -1 << endl;
        else
        {
            lol j = ev.size() - 1;
            lol i = od.size() - 1;
            while (i >= 0 && j >= 0)
            {
                ans++;
                od[i]++;
                ev[j] -= 2;
                i--;
                if (ev[j] == 0)
                    j--;
            }

            j = od.size() - 1;
            while (od[j] % 2 == 0 && i >= 0 && j > i)
            {
                ans++;
                od[j] -= 2;
                od[i]++;
                i--;
                if (od[j] == 0)
                    j--; 
                
            }  

            if(i==0)
            cout<<-1<<endl;
            else
            {
                
            }

        }
    }

    return 0;
}