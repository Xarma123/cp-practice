#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    string a;
    string b;
    cin >> a >> b;
    if (a.size() > b.size())
        swap(a, b);
    lol a1 = a.size(), b1 = b.size();
    lol n = __gcd( a1 , b1 );
    vector<lol> d;
    for (lol i = 1; i <= sqrtl(n); i++)
    {
        if (n % i == 0)
        {
            d.push_back(i);
            if (n / i != i)
                d.push_back(n / i);
        }
    }
    sort(d.begin(), d.end());
    lol ans = 0;
    for (lol i = 0; i < d.size(); i++)
    {
        string c = a.substr(0, d[i]);
        bool f = true;
        for (lol j = 0; j + d[i] -1< a.size(); j += d[i])
        {
            if (c != a.substr(j, d[i]))
            {
                f = false;
                break;
            }
        }

        for (lol j = 0; j + d[i]-1< b.size(); j += d[i])
        {
            if (c != b.substr(j, d[i]))
            {
                f = false;
                break;
            }
        }
        if (f)
            ans++; 
    } 
    cout<<ans;

    return 0;
}