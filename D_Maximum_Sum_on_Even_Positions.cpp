#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol kadane(vector<lol> a)
{
    lol mx = 0;
    lol mxtill = 0;
    for (lol i = 0; i < a.size(); i++)
    {
        mxtill += a[i];
        mx = max(mx, mxtill);
        if (mxtill < 0)
            mxtill = 0; 
    } 
    return mx;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        vector<lol> ev;
        vector<lol> od;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            if (i % 2 == 0)
            {
                ans += q;
                ev.push_back(q);
            }
            else
                od.push_back(q);
        }
        vector<lol> k;
        lol s = 0;
        while (s < ev.size() && s < od.size())
        {
            k.push_back(od[s] - ev[s]);
            s++;
        }
        vector<lol> k1;
        s = 0;
        while (s + 1 < ev.size() && s < od.size())
        {
            k1.push_back(od[s] - ev[s + 1]);
            s++;
        }
        cout << max(ans + kadane(k1), ans + kadane(k)) << endl;
    }

    return 0;
}