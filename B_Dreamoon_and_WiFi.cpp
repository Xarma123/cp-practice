#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    lol p = 0;
    for (lol i = 0; i < s1.size(); i++)
    {
        if (s1[i] == '+')
            p++;
        else
            p--;
    }

    vector<lol> ind;
    lol p2 = 0;
    for (lol i = 0; i < s2.size(); i++)
    {
        if (s2[i] == '?')
            ind.push_back(i);
        else if (s2[i] == '+')
            p2++;
        else
            p2--;
    }
    lol tot = 0, fav = 0;
    for (lol i = 0; i < (1 << ind.size()); i++)
    {
        lol pm = p2;
        for (lol j = 0; j < ind.size(); j++)
        {
            if (((i >> j) & 1))
            {
                pm++;
            }
            else
                pm--;
        }
        tot++;
        if (pm == p)
            fav++;
    }
    cout << setprecision(10) << (long double)fav / (long double)tot;

    return 0;
}