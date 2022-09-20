#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol d;
    lol p;
    cin >> p >> d;
    string ps = to_string(p);
    while (d > 0)
    {
        lol take = -1;
        for (lol i = ps.size() - 1; i > 0; i--)
        {
            if (ps[i] == '9')
                continue;
            else
            {
                take = (ps[i] - '0' + 1) * 1ll * powl(10, (ps.size() - 1 - i));
                break;
            }
        }
        if (take == -1 || take > d)
        {
            break;
        }
        p -= take;
        ps = to_string(p);
        d -= take;
    }
    cout << p;

    return 0;
}