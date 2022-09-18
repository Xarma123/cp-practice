#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    vector<lol> p;
    lol q = 1;
   
    while (q<1e18)
    {
        p.push_back(q);
        q = q * 2;
    }

    lol t;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        lol ans = INT_MAX;
        for (lol i = 0; i <p.size(); i++)
        {
            string check = to_string(p[i]);
            lol polol = 0;
            for (lol j = 0; j < n.size(); j++)
            {
                if (n[j] == check[polol])
                {
                    polol++;
                    if (polol == check.size())
                        break;
                }
            }
            lol temp = n.size() - polol + check.size() - polol;
            ans = min(ans,temp);
        } 
        cout<<ans<<endl;
    }

    return 0;
}