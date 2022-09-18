#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol x;
    cin >> x;
    if (x == 1)
    {
        cout << 1 << " " << 1;
    }
    else
    {
        map<lol, lol> fact;
        while (x % 2 == 0)
        {
            fact[2]++;
            x /= 2;
        }
        for (lol i = 3; i * i <= x; i += 2)
        {
            while (x % i == 0)
            {
                fact[i]++;
                x /= i;
            }
        }
        if (x > 1)
        {
            fact[x]++;
        }
        vector<lol> s;
        for (auto i = fact.begin(); i != fact.end(); i++)
        {
            s.push_back((long long)powl((*i).first, (*i).second));
        }
        sort(s.begin(), s.end());
        if (s.size() == 1)
        {
            cout << s[0] << " " << s[0];
        }
        else
        {
            lol c1 = LONG_LONG_MAX, c2 = -1;
            for (lol i = 0; i < pow(2, s.size()); i++)
            {
                lol a = 1;
                lol b = 1;
                for (lol j = 0; j < s.size(); j++)
                {
                    if (i & (1 << j))
                    {
                        a *= s[j];
                    }
                    else
                        b *= s[j];
                }
                if (max(a, b) < max(c1, c2))
                {
                    c1 = a;
                    c2 = b;
                }
            }
            cout << c1 << " " << c2;
        }
    }

    return 0;
}