#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool cmp(pair<lol, lol> a, pair<lol, lol> b)
{
    return a.first > b.first;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        pair<lol, lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            lol x;
            cin >> x;
            a[i] = make_pair(x, i);
        }
        sort(a, a + n, cmp);
        lol index[n + 1];
        index[0] = 0;
        lol c = 1;
        lol T = 0;
        for (lol i = 1; i < n + 1; i++)
        {
            if (i % 2 != 0)
            {
                index[a[i - 1].second + 1] = c;
                T += 2*abs(c * (a[i - 1].first));
            }
            else
            {
                index[a[i - 1].second + 1] = -c;
                T += 2*abs(c * (a[i - 1].first));
                c++;
            }
        } 
        cout<<T<<endl;
        for (lol i = 0; i <=n; i++)
        {
           cout<<index[i]<<" ";
        }
        cout<<endl;
        
    }

    return 0;
}