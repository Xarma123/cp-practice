#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a, b;
    cin >> a >> b;
    multiset<lol> x;
    for (lol i = a; i < b; i++)
    {
        x.insert(i);
    }
    for (lol i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        for (lol j = a; j < b; j++)
        {
            if (x.find(j) != x.end())
            {
                x.erase(x.find(j));
            }
        }
    }
    cout << x.size();

    return 0;
}