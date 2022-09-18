#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long k = n;
    multimap<long long, long long> seg;
    long long a, b;
    while (k--)
    {

        cin >> a >> b;
        seg.insert(make_pair(a, b));
    }
    auto it = seg.begin();

    b = (*it).second;
    it++;
    lol ans = 1;
    lol last = 0;

    for (long long i = 1; i < n; i++)
    {
        if ((*it).first <= b)
        {

            if ((*it).second < b)
            {
                b = (*it).second;
            }
        }
        else
        {
            ans = max(ans, i - last);
            last = i;
            b = (*it).second;
        }

        it++;
    }
    ans = max(ans, n - last);
    cout << ans << endl;

    return 0;
}