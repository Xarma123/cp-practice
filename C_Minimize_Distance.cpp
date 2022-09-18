#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        vector<lol> a;
        vector<lol> b;
        lol c1 = 0, c2 = 0;
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            if (t >= 0)
            {
                a.push_back(t);
                c1++;
            }
            else
            {
                t = abs(t);
                b.push_back(t);
                c2++;
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        lol ansp1 = 0, ansp2 = 0;

        for (lol i = c1 - 1 - k; i >= 0; i = i - k)
        {
            
            ansp1 += 2 * (abs(a[i]));
        } 
        if(c1-1>=0&&a.size()>=1)
        ansp1 += a[c1 - 1]; 

        for (lol i = c1 - 1; i >= 0; i = i - k)
        {
           
            ansp2 += 2 * (abs(a[i]));
        }
        lol ansn1 = 0, ansn2 = 0;

        for (lol i = c2 - 1 - k; i >= 0; i = i - k)
        {
           
            ansn1 += 2 * (abs(b[i]));
        }
        if (c2 - 1 >= 0&&b.size()>=1)
            ansn1 += b[c2 - 1];
        for (lol i = c2 - 1; i >= 0; i = i - k)
        {
           
            ansn2 += 2 * (abs(b[i]));
        }
        lol ans1  = ansp1+ansn2;
        lol ans2  = ansp2+ansn1;
        
        cout << min(ans1,ans2) << endl;
    }

    return 0;
}